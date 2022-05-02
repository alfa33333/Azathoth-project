#include <iostream>
#include <fstream>
#include <string>
#include <cerrno>
#include "raylib.h"

//String reading

std::string get_file_contents(const char *filename)
{
  std::ifstream in(filename, std::ios::in | std::ios::binary);
  if (in)
  {
    std::string contents;
    in.seekg(0, std::ios::end);
    contents.resize(in.tellg());
    in.seekg(0, std::ios::beg);
    in.read(&contents[0], contents.size());
    in.close();
    return(contents);
  }
  throw(errno);
}

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Basic window");


    //message-setting
    std::ifstream myfile("file.txt");
    std::string line;


    //--------- text show example example

    int framesCounter = 0;

    // //
    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    // //--------------------------------------------------------------------------------------

    //Get the lines from the file

    if (myfile.is_open())
    {
        while ( getline (myfile,line) )
        {
            //   cout << line << '\n';
            continue;
        }
        myfile.close();
    } else {
        std::cout << "Unable to open file";
    } 


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
            DrawText(TextSubtext(line.c_str(), 0, framesCounter/2), 210, 160, 20, GREEN);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}