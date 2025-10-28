#pragma once
#include <iostream>
#include <raylib.h>
#include "constant.h"
#include <vector>

namespace Space {
    const size_t MAXOLDPOS = 1000;

    struct Velocity2 {
        double x;
        double y;
    };

    class Body {

    public:

        Body(Color color, Vector2 pos, double mass, float radius, Velocity2 speed);
        ~Body() = default;

        void draw() const;
        void check_touched_ledge();

        //Getters & setters
        Color getColor() const;
        double getMass() const;
        float getRadius() const;
        Velocity2 getSpeed() const;
        double getAcceleration() const;
        Vector2 getPos() const;
        std::vector<Vector2> getOldPositions();

        void appgravity(Body& b2);

        void setMass(double m);
        void setRadius(float r);
        void setSpeed(Velocity2 v);
        void setAcceleration(double a);
        void setPosition(Vector2 p);

        bool has_touched_top_ledge = false;
        bool has_touched_low_ledge = false; //TODO need to be changed -> not optimal
        bool has_touched_left_ledge = false;
        bool has_touched_right_ledge = false;

    private:
        Color color;
        double mass;
        float radius;
        Velocity2 speed;
        double acceleration = 0;
        Vector2 pos;
        std::vector<Vector2> oldPositions;
    };

    double calculateDistance(Body& b1, Body& b2);

    bool collisionCheck(Body& b1, Body& b2);
}
