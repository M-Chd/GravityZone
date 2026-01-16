#include "space.h"
#include <iostream>

constexpr uint16_t MAX_BODIES = 10;

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

            Body& firstBody = bodies[i];
            Body& secondBody = bodies[j];

            Vector2 direction = { secondBody.getPos().x - firstBody.getPos().x, secondBody.getPos().y - firstBody.getPos().y };
            double dist = distanceBetween(firstBody.getPos(), secondBody.getPos());

            if (dist < 2.0) dist = 2.0;

            double forceMag = (Gforce * firstBody.getMass() * secondBody.getMass()) / (dist * dist);

            Vector2 forceVec = {
                (float)(direction.x / dist * forceMag),
                (float)(direction.y / dist * forceMag)
            };

            firstBody.addForce(forceVec);
        }
    }
}

void space::drawBodies() {
    for (auto& b : bodies) {
        b.draw();
    }
}

void space::clearBodiesIfOver10(Log& log) {
    if (bodies.size() == MAX_BODIES) {
        bodies.clear();
        logs.push_back(logsEvents::DELETE_EVENT);
        notify(log);
    }
}

void space::updateAll(float dt,Log& log) {
    applyG();

    for (size_t i = 0; i < bodies.size(); ++i) {
        for (size_t j = i + 1; j < bodies.size(); ++j) {

            if (bodies.size() < 5){
                bodies[i].handleCollision(bodies[j]); //optimisation?
                logs.push_back(logsEvents::COLLISION_EVENT);
            }
        }
    }

    notify(log);

    for (auto& b : bodies) {
        b.update(dt);
    }
}

void space::add(Body b,Log& log) {
    bodies.push_back(b);
    logs.push_back(logsEvents::PLACE_EVENT);
    notify(log);
}

void space::removeAtPos(Vector2 mousePos,Log& log) {
    for (auto it = bodies.begin(); it != bodies.end(); ) {
        if (isInside(mousePos, *it)) {
            it = bodies.erase(it);
            logs.push_back(logsEvents::DELETE_EVENT);
        }
        else {
            ++it;
        }
    }
    notify(log);
}

void space::notify(Log& log)
{
    log.update(*this);
}