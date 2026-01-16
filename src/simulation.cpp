#include "simulation.h"

void Simulation::init() const
{
    InitWindow(LENGTH, HEIGHT, "GravityZone (WIP)");
    SetTargetFPS(60);    
}

void Simulation::run()
{

    init();

    while (!WindowShouldClose()) {
       
        handleEvent(terrain,logger);

        
        float dt = GetFrameTime();

        terrain.applyG();

        for (auto& b : terrain.getBodies()) {
            b.update(dt);
        }

        BeginDrawing();
        ClearBackground(BLACK);

        if (!terrain.getBodies().empty()) {
            terrain.drawBodies();
            terrain.clearBodiesIfOver10(logger);

            DrawFPS(10, 10);
            DrawText(TextFormat("Corps: %i", terrain.getBodies().size()), 10, 30, 20, RAYWHITE);
        }
        else {
            DrawFPS(10, 10);
            DrawText(TextFormat("Corps: %i", terrain.getBodies().size()), 10, 30, 20, RAYWHITE);
        }
        EndDrawing();
    }
    CloseWindow();
}
