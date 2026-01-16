#pragma once
#include <raylib.h>
#include <raymath.h>
#include <vector>
#include <iostream>
#include "constant.h"

class Body {
public:
    Body(Color color, Vector2 pos, double mass, float radius, Vector2 initialVelocity);
    ~Body() = default;

    void draw() const;
    void update(float deltaTime);
    void addForce(Vector2& Fvector);
    void handleCollision(Body& other);
    void checkLedgeCollisions();

    const Vector2& getPos() const { return pos; }
    const std::vector<Vector2>& getOldPositions() const;
    double getMass() const { return mass; }
    float getRadius() const { return radius; }

    void setMass(double m) { mass = m; }
    void setPosition(Vector2 p) { pos = p; }

private:
    Vector2 pos;
    Vector2 velocity;
    Vector2 totalForce;

    double mass;
    float radius;
    Color color;

    size_t MAXOLDPOS = 300;

    std::vector<Vector2> oldPositions;
};