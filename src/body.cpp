#include <iostream>
#include "body.h"

namespace Space {
    Body::Body(Color color, Vector2 pos, double mass, float radius, Velocity2 speed) : color(color), pos(pos), mass(mass),
        radius(radius), speed(speed)
    {
        if (mass <= 0) {
            std::cerr << "Mass cannot be negative or null" << "\n";
            return;
        }
        if (radius <= 0) {
            std::cerr << "Radius cannot be negative or null" << "\n";
        }
    }

    void Body::draw() const {
        int screenX = static_cast<int>(pos.x * scale);
        int screenY = static_cast<int>(pos.y * scale);
        float screenRadius = radius * scale;
        DrawCircle(screenX, screenY, screenRadius, color);

        for (auto& e : oldPositions) {
            DrawCircle(static_cast<int>(e.x * scale), static_cast<int>(e.y * scale), 2, color);
        }
    }

    //Need to be optimized.
    void Body::check_touched_ledge()
    {
        double posY = pos.y + radius + 0.15; // Position y of the body
        double posX = pos.x + radius;
        double posXBack = pos.x - radius - 0.18;
        double posYTop = pos.y - radius;

        has_touched_low_ledge = (posY >= 720 / scale);
        has_touched_top_ledge = (posYTop <= 0);
        has_touched_left_ledge = (posXBack <= 0.5);
        has_touched_right_ledge = (posX >= 1280 / scale);

    }

    Color Body::getColor() const
    {
        return color;
    }

    double Body::getMass() const
    {
        return mass;
    }

    float Body::getRadius() const
    {
        return radius;
    }

    Velocity2 Body::getSpeed() const
    {
        return speed;
    }

    double Body::getAcceleration() const
    {
        return acceleration;
    }

    Vector2 Body::getPos() const
    {
        return pos;
    }

    std::vector<Vector2> Body::getOldPositions()
    {
        return oldPositions;
    }

    void Body::setMass(double m)
    {
        if (m > 0) {
            mass = m;
        }
        else {
            std::cerr << "Mass cannot be negative or null" "\n";
        }
    }

    void Body::setRadius(float r)
    {
        if (r > 0) {
            radius = r;
        }
        else {
            std::cerr << "Radius cannot be negative or null" "\n";
        }
    }

    void Body::setSpeed(Velocity2 v)
    {
        speed = v;
    }

    void Body::setAcceleration(double a)
    {
        acceleration = a;
    }

    void Body::setPosition(Vector2 p)
    {
        pos = p;
    }

    /**
    All this following code need to be changed and optimized.
    All the code below this message are obselete.
     */

    double calculateDistance(Body& b1, Body& b2) {

        Vector2 b1Pos = b1.getPos();
        Vector2 b2Pos = b2.getPos();

        return sqrt((pow(b2Pos.x - b1Pos.x, 2) + pow(b2Pos.y - b1Pos.y, 2)));
    }

    bool collisionCheck(Body& b1, Body& b2) {

        double distance = calculateDistance(b1, b2);
        float radiusSum = b1.getRadius() + b2.getRadius();
        return distance <= radiusSum;
    }
}

