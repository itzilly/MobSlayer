#include <cmath>
#include <list>
#include <string>
#include <memory>
#include "raylib.h"
#include "GameObject.hpp"
#include "MainMenu.hpp"


typedef enum GameState {
    LOGO = 0,
    TITLE = 1,
    GAMEPLAY = 2,
    ENDING = 3
} GameState;


GameState currentGameState;

Sound titleTheme;
Sound selectSound;

Texture2D logo;

float centerScreenX;
float centerScreenY;


int main()
{
    const int screenWidth = GetScreenWidth();
    const int screenHeight = GetScreenHeight();

    // Set up the window
    InitWindow(GetScreenWidth(), GetScreenHeight(), "Mob Slayer!");
    Image icon = LoadImage("assets/icons/title.png");
    ImageFormat(&icon, PIXELFORMAT_UNCOMPRESSED_R8G8B8A8);
    SetWindowIcon(icon);
    ToggleFullscreen();
    SetTargetFPS(60);
    int framesCounter = 0;

    // Set gamestate
    currentGameState = LOGO;

    // Load Audio
    InitAudioDevice();
    titleTheme = LoadSound("assets/audio/music/title.ogg");

    // Load Logo
    logo = LoadTexture("assets/icons/title.png");

    std::list<GameObject> InGameObjects;

    currentGameState = TITLE;
    SetSoundVolume(titleTheme, 0.8f);
    centerScreenX = GetScreenWidth() / 2;
    centerScreenY = GetScreenHeight() / 2;

    MainMenu mainMenu(1.0f, centerScreenX, centerScreenY);
    PlaySound(titleTheme);


    while (!WindowShouldClose())
    {
        // Minimize window if other window is selected
        if (!IsWindowFocused()) {
            PauseSound(titleTheme);
            MinimizeWindow();
            continue;
        }
        ResumeSound(titleTheme);
        mainMenu.Update();
        mainMenu.Render();



        for (GameObject object : InGameObjects) {
            object.Update();
        }

        for (GameObject object : InGameObjects) {
            object.Render();
        }





//        switch (currentGameState) {
//            case LOGO: {
//                framesCounter++;
//                if (framesCounter > 120) {
//                    currentGameState = TITLE;
//                    PlaySound(titleTheme);
//                }
//            } break;
//            case TITLE: {
//                if (IsKeyPressed(KEY_ENTER)) {
//                    currentGameState = GAMEPLAY;
//                }
//            } break;
//            case GAMEPLAY: {
//                if (IsKeyPressed(KEY_ENTER)) {
//                    currentGameState = ENDING;
//                }
//            } break;
//            case ENDING:
//                exit(0);
//                break;
        }

//        BeginDrawing();
//
//        ClearBackground(RAYWHITE);
//
//        switch(currentGameState)
//        {
//            case LOGO:
//            {
//                // TODO: Draw LOGO screen here!
//                DrawText("Loading Game ...", (GetScreenWidth() - (GetScreenWidth() / 2)), (GetScreenHeight() - (GetScreenHeight() / 2)), 100, LIGHTGRAY);
//                std::string loadingString = "Please wait while the game loads .";
//                if ((framesCounter / 3) >= 40) {
//                    loadingString = "Please wait while the game loads ..";
//                }
//                else if ((framesCounter / 3) >= 80) {
//                    loadingString = "Please wait while the game loads ...";
//                }
//                DrawText(loadingString.c_str(), (GetScreenWidth() - (GetScreenWidth() / 2)), (GetScreenHeight() - (GetScreenHeight() / 2)), 40, GRAY);
//
//            } break;
//            case TITLE:
//            {
//                // TODO: Draw TITLE screen here!
//
//                // Update logo position using the equation y = a * sin(b(x - h)) + k
//                x = static_cast<float>(GetScreenWidth() / 2 - logo.width / 2);  // Keep x constant (centered)
//                y = a * sin(b * (ticks - h)) + k;
//
//                ClearBackground(BLACK);
//
//                // Draw logo at updated position
//                DrawTextureEx(logo, Vector2{ x, y }, 0.0f, 1.0f, WHITE);
//
//                // Draw the text at the center of the screen
//                DrawText(message, GetScreenWidth() / 2 - textWidth / 2, GetScreenHeight() / 2 - textHeight / 2, fontSize, WHITE);
//
//
//                ticks++;
////                DrawRectangle(0, 0, screenWidth, screenHeight, GREEN);
////                DrawText("TITLE SCREEN", 20, 20, 40, DARKGREEN);
////                DrawText("PRESS ENTER or TAP to JUMP to GAMEPLAY SCREEN", 120, 220, 20, DARKGREEN);
//
//            } break;
//            case GAMEPLAY:
//            {
//                // TODO: Draw GAMEPLAY screen here!
//                DrawRectangle(0, 0, screenWidth, screenHeight, PURPLE);
//                DrawText("GAMEPLAY SCREEN", 20, 20, 40, MAROON);
//                DrawText("PRESS ENTER or TAP to JUMP to ENDING SCREEN", 130, 220, 20, MAROON);
//
//            } break;
//            case ENDING:
//            {
//                // TODO: Draw ENDING screen here!
//                DrawRectangle(0, 0, screenWidth, screenHeight, BLUE);
//                DrawText("ENDING SCREEN", 20, 20, 40, DARKBLUE);
//                DrawText("PRESS ENTER or TAP to RETURN to TITLE SCREEN", 120, 220, 20, DARKBLUE);
//
//            } break;
//            default: break;
//        }
//
//        EndDrawing();
//    }


    // Unload Game Objects
    InGameObjects.clear();

    // Unload resources
    UnloadSound(titleTheme);
    UnloadTexture(logo);
    mainMenu.unload();

    CloseAudioDevice();
    CloseWindow();

    return 0;
}

