#include "raylib.h"


int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Basic window");

    //--------- text show example example
    const char message[128] = "This sample illustrates a text writing\nanimation effect! Check it out! ;)";

    int framesCounter = 0;

    // //
    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    // //--------------------------------------------------------------------------------------

    // // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        if (IsKeyDown(KEY_SPACE)) {
            framesCounter += 8;
        }
        else {
            framesCounter++;
        }
        if (IsKeyPressed(KEY_ENTER)) framesCounter = 0;
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(BLACK);
            DrawFPS(0, 20);
            DrawText(TextSubtext(message, 0, framesCounter/2), 210, 160, 20, GREEN);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}