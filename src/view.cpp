#include <iostream>
#include "view.h"

using std::string;

namespace Space {
    void View::DebugInfo(Body& b) {

        auto speedX = b.getSpeed().x;
        auto speedY = b.getSpeed().y;
        auto posX = b.getPos().x;
        auto posY = b.getPos().y;
        //bool isCollising = collisionCheck(b, b2);
        auto acc = b.getAcceleration();

        string sX = std::to_string(speedX);
        string sY = std::to_string(speedY);
        string pX = std::to_string(posX);
        string pY = std::to_string(posY);
        //string check = std::to_string(isCollising);
        string accString = std::to_string(acc);

        DrawText(("X speed: " + sX).c_str(), 10, 10, 13, WHITE);
        DrawText(("Y speed: " + sY).c_str(), 10, 40, 13, WHITE);
        DrawText(("X position: " + pX).c_str(), 10, 70, 13, WHITE);
        DrawText(("Y position: " + pY).c_str(), 10, 100, 13, WHITE);
        //DrawText(("Collision: " + check).c_str(), 10, 130, 13, WHITE);
        DrawText(("Acceleration: " + accString).c_str(), 10, 145, 13, WHITE);
    }
}

