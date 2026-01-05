#include "space.h"
#include <iostream>

space::space() {}

space::~space() {
    bodies.clear();
}

std::vector<Body>& space::getBodies() {
    return bodies;
}

void space::applyG() {
    if (bodies.size() < 2) return;

    for (size_t i = 0; i < bodies.size(); ++i) {
        for (size_t j = 0; j < bodies.size(); ++j) {
            if (i == j) continue;

            Body& a = bodies[i];
            Body& b = bodies[j];

            Vector2 direction = { b.getPos().x - a.getPos().x, b.getPos().y - a.getPos().y };
            double dist = distanceBetween(a.getPos(), b.getPos());

            if (dist < 2.0f) dist = 2.0f;

            double forceMag = (G * a.getMass() * b.getMass()) / (dist * dist);

            Vector2 forceVec = {
                (float)(direction.x / dist * forceMag),
                (float)(direction.y / dist * forceMag)
            };

            a.addForce(forceVec);
        }
    }
}

void space::drawBodies() {
    for (auto& b : bodies) {
        b.draw();
    }
}

void space::clearBodiesIfOver10() {
    if (bodies.size() >= 10) {
        bodies.clear();
    }
}

void space::updateAll(float dt) {
    applyG();

    for (size_t i = 0; i < bodies.size(); ++i) {
        for (size_t j = i + 1; j < bodies.size(); ++j) {
            bodies[i].handleCollision(bodies[j]);
        }
    }

    for (auto& b : bodies) {
        b.update(dt);
    }
}

void space::add(Body b) {
    bodies.push_back(b);
}

void space::removeAtPos(Vector2 mousePos) {
    for (auto it = bodies.begin(); it != bodies.end(); ) {
        if (isInside(mousePos, *it)) {
            it = bodies.erase(it);
        }
        else {
            ++it;
        }
    }
}