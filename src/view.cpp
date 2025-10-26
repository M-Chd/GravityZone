#include <iostream>
#include "view.h"

using std::string;

namespace Space {
    void View::DebugInfo(Body& b, Body& b2) {

        auto speedX = b.getSpeed().x;
        auto speedY = b.getSpeed().y;
        auto posX = b.getPos().x;
        auto posY = b.getPos().y;
        bool isCollising = collisionCheck(b, b2);
        auto acc = b.getAcceleration();

        string sX = std::to_string(speedX);
        string sY = std::to_string(speedY);
        string pX = std::to_string(posX);
        string pY = std::to_string(posY);
        string check = std::to_string(isCollising);
        string accString = std::to_string(acc);

        auto speedX_ = b2.getSpeed().x;
        auto speedY_ = b2.getSpeed().y;
        auto posX_ = b2.getPos().x;
        auto posY_ = b2.getPos().y;
        bool isCollising_ = collisionCheck(b2, b);
        auto accB2 = b2.getAcceleration();

        string sX_ = std::to_string(speedX_);
        string sY_ = std::to_string(speedY_);
        string pX_ = std::to_string(posX_);
        string pY_ = std::to_string(posY_);
        string check_ = std::to_string(isCollising_);
        string accB2String = std::to_string(accB2);

        DrawText(("X speed: " + sX).c_str(), 10, 10, 13, WHITE);
        DrawText(("Y speed: " + sY).c_str(), 10, 40, 13, WHITE);
        DrawText(("X position: " + pX).c_str(), 10, 70, 13, WHITE);
        DrawText(("Y position: " + pY).c_str(), 10, 100, 13, WHITE);
        DrawText(("Collision: " + check).c_str(), 10, 130, 13, WHITE);
        DrawText(("Acceleration: " + accString).c_str(), 10, 145, 13, WHITE);

        DrawText(("X speed: " + sX_).c_str(), 10, 160, 13, BLUE);
        DrawText(("Y speed: " + sY_).c_str(), 10, 190, 13, BLUE);
        DrawText(("X position: " + pX_).c_str(), 10, 210, 13, BLUE);
        DrawText(("Y position: " + pY_).c_str(), 10, 240, 13, BLUE);
        DrawText(("Collision: " + check_).c_str(), 10, 270, 13, BLUE);
        DrawText(("Acceleration: " + accB2String).c_str(), 10, 285, 13, BLUE);
    }
}

