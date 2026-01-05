#pragma once
#include <raylib.h>
#include <raymath.h>
#include <vector>
#include <iostream>
#include "constant.h"

const size_t MAXOLDPOS = 600;

class Body {
public:
    Body(Color color, Vector2 pos, double mass, float radius, Vector2 initialVelocity);
    ~Body() = default;

    void draw() const;
    void update(float deltaTime);
    void addForce(Vector2& Fvector);
    void handleCollision(Body& other);
    void check_touched_ledge();

    const Vector2& getPos() const { return pos; }
    const std::vector<Vector2>& getOldPositions() const;
    double getMass() const { return mass; }
    float getRadius() const { return radius; }

    void setMass(double m) { mass = m; }
    void setPosition(Vector2 p) { pos = p; }

    bool has_touched_top_ledge = false;
    bool has_touched_low_ledge = false;
    bool has_touched_left_ledge = false;
    bool has_touched_right_ledge = false;

private:
    Vector2 pos;
    Vector2 velocity;
    Vector2 totalForce;

    double mass;
    float radius;
    Color color;

    std::vector<Vector2> oldPositions;
};