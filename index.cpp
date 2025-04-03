#include <raylib.h>
#include <iostream>
#include <simulation.hpp>

using namespace std;

int main() {
    Color GREY = {29, 29, 29, 255};
    const int screenWidth = 1000;
    const int screenHeight = 1000;

    const int cellSize = 10;

    InitWindow(screenWidth, screenHeight, "                GAME OF LIFE");

    SetTargetFPS(7);

    Simulation s(screenWidth, screenHeight, cellSize);
    //Simulation Loop 

    while(!WindowShouldClose()) 
    {  
        if(IsKeyPressed(KEY_ENTER)) {
            s.Start();
            SetWindowTitle("                GAME OF LIFE - RUNNING");
        }

        else if(IsKeyPressed(KEY_SPACE)) {
            s.Stop();
            SetWindowTitle("                GAME OF LIFE - PAUSED");
        }

        else if(IsKeyPressed(KEY_BACKSPACE)) {
            s.ClearGrid();
            s.Stop();
        
        }

        else if(IsKeyPressed(KEY_S)) {
            s.CreateRandomState();
            s.Start();
        }

        s.Update();
        
        BeginDrawing();
        ClearBackground(GREY);
        s.Draw();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
