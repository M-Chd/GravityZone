#include <iostream>
#include <raylib.h>
#include "constant.h"
#include "view.h"
#include "space.h"
#include "handleEvent.h"
#include <memory>
#include <vector>

constexpr uint16_t HEIGHT  = 720;
constexpr uint16_t LENGTH = 1280;

int main() {
    InitWindow(LENGTH, HEIGHT, "GravityZone-alpha");
    SetTargetFPS(60);

    space terrain;
    View v;

    while (!WindowShouldClose()) {
       
        handleEvent(terrain);

        
        float dt = GetFrameTime();

        terrain.applyG();

        for (auto& b : terrain.getBodies()) {
            b.update(dt);
        }

        BeginDrawing();
        ClearBackground(BLACK);

        if (!terrain.getBodies().empty()) {
            terrain.drawBodies();
            terrain.clearBodiesIfOver10();

            DrawFPS(10, 10);
            DrawText(TextFormat("Corps: %i", terrain.getBodies().size()), 10, 30, 20, RAYWHITE);
        }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}