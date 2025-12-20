#include <iostream>
#include <raylib.h>
#include "constant.h"
#include "view.h"
#include "space.h"
#include "handleEvent.h"
#include <memory>
#include <vector>

#define HEIGHT 720
#define LENGTH 1280

using namespace Space;


int main() {

    
    InitWindow(LENGTH, HEIGHT, "GravityZone-alpha");

    SetTargetFPS(60);

    space Space;

    Vector2 pos = {20,20};

    Body planet = Body(WHITE,pos,50,1,Velocity2(1,1));

    View v;

    Space.add(planet);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);

        
        handleEvent(Space);
        Space.updateBodies();
        Space.freeBodies();

        v.DebugInfo(planet);
        
        EndDrawing();
    }

    CloseWindow();
    return 0;
}