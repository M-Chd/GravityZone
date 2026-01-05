#include "body.h"
#include <iostream>

Body::Body(Color color, Vector2 pos, double mass, float radius, Vector2 initialVelocity)
    : color(color), pos(pos), mass(mass), radius(radius), velocity(initialVelocity)
{
    oldPositions.reserve(MAXOLDPOS);
    totalForce = { 0.0f, 0.0f };

    if (mass <= 0) std::cerr << "Mass must be > 0\n";
    if (radius <= 0) std::cerr << "Radius must be > 0\n";
}

void Body::draw() const {
    for (size_t i = 0; i < oldPositions.size(); i++) {
        DrawCircle(oldPositions[i].x * scale, oldPositions[i].y * scale, 1.0f, color);
    }

    DrawCircleV({ pos.x * scale, pos.y * scale }, radius * scale, color);
}

void Body::check_touched_ledge() {
    float limitX = 1280.0f / scale;
    float limitY = 720.0f / scale;

    has_touched_low_ledge = (pos.y + radius >= limitY);
    has_touched_top_ledge = (pos.y - radius <= 0);
    has_touched_left_ledge = (pos.x - radius <= 0);
    has_touched_right_ledge = (pos.x + radius >= limitX);

    if (has_touched_low_ledge) {
        pos.y = limitY - radius;
        velocity.y *= -0.9f;
    }
    if (has_touched_top_ledge) {
        pos.y = radius;
        velocity.y *= -0.9f;
    }
    if (has_touched_left_ledge) {
        pos.x = radius;
        velocity.x *= -0.9f;
    }
    if (has_touched_right_ledge) {
        pos.x = limitX - radius;
        velocity.x *= -0.9f;
    }
}

void Body::update(float deltaTime) {
    if (oldPositions.empty() || Vector2Distance(pos, oldPositions.back()) > 0.1f) {
        if (oldPositions.size() >= MAXOLDPOS) {
            oldPositions.erase(oldPositions.begin());
        }
        oldPositions.push_back(pos);
    }

    Vector2 acc = { (float)(totalForce.x / mass), (float)(totalForce.y / mass) };

    velocity.x += acc.x * deltaTime;
    velocity.y += acc.y * deltaTime;

    pos.x += velocity.x * deltaTime;
    pos.y += velocity.y * deltaTime;

    totalForce = { 0.0f, 0.0f };

    check_touched_ledge();
}

const std::vector<Vector2>& Body::getOldPositions() const {
    return oldPositions;
}

void Body::addForce(Vector2& Fvector) {
    totalForce.x += Fvector.x;
    totalForce.y += Fvector.y;
}

void Body::handleCollision(Body& other) {
    Vector2 normal = Vector2Subtract(other.pos, this->pos);
    float distance = Vector2Length(normal);

    if (distance == 0) return;

    normal = Vector2Scale(normal, 1.0f / distance);

    float overlap = (radius + other.radius) - distance;
    if (overlap > 0) {
        Vector2 separation = Vector2Scale(normal, overlap / 2.0f);
        pos = Vector2Subtract(pos, separation);
        other.pos = Vector2Add(other.pos, separation);
    }

    Vector2 relativeVelocity = Vector2Subtract(velocity, other.velocity);
    float velocityAlongNormal = Vector2DotProduct(relativeVelocity, normal);

    if (velocityAlongNormal < 0) return;

    float e = 0.9f;

    float j = -(1.0f + e) * velocityAlongNormal;
    j /= (1.0f / (float)mass + 1.0f / (float)other.mass);

    Vector2 impulse = Vector2Scale(normal, j);

    velocity = Vector2Add(velocity, Vector2Scale(impulse, 1.0f / (float)mass));
    other.velocity = Vector2Subtract(other.velocity, Vector2Scale(impulse, 1.0f / (float)other.mass));
}