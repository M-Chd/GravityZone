#include <iostream>
#include <raylib.h>
#include "constant.h"
#include "view.h"
#include <memory>
#include <vector>

#define HEIGHT 720
#define LENGTH 1280

using namespace Space;


int main() {

    
    InitWindow(LENGTH, HEIGHT, "GravityZone-alphaBuild");

    SetTargetFPS(60);

    std::vector<Body> bodies;

    Position pos = {20,20};
    Position pos2 = {30,20};
    Position pos3 = {40,20};

    Body planet = Body(WHITE,pos,50,1,Velocity2(1,1));
    Body planet2 = Body(BLUE,pos2,50,1,Velocity2(1,1));

    View v;

    bodies.push_back(planet);
    bodies.push_back(planet2);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);

        planet.draw();
        planet2.draw();

        v.DebugInfo(planet,planet2);

        planet.appgravity(planet2);
        planet2.appgravity(planet);
        
        EndDrawing();
    }

    CloseWindow();
    return 0;
}