//
// Created by illyum on 6/26/2023.
//

//#include "raylib.h"
#include "MainMenu.hpp"

MainMenu::MainMenu(float scale, float _centerScreenX, float _centerScreenY) {
    centerScreenX = _centerScreenX;
    centerScreenY = _centerScreenY;

    // Load Assets and Objects
    selectSound = LoadSound("assets/audio/sounds/select.ogg");

    playButton.rectangle = {
            centerScreenX - (playButton.normal.width / 2),
            (centerScreenY - (playButton.normal.height / 2)) + (playButton.normal.height * 1.1f),
            static_cast<float>(playButton.normal.width),
            static_cast<float>(playButton.normal.height)
    };
    LoadButtonAssets(playButton, 15);
    playButton.text = "Play Game";

    optionsButton.rectangle = {
            centerScreenX - (optionsButton.normal.width / 2),
            centerScreenY - (optionsButton.normal.height / 2),
            static_cast<float>(optionsButton.normal.width),
            static_cast<float>(optionsButton.normal.height)
    };
    LoadButtonAssets(optionsButton, 15);
    optionsButton.text = "Options";

    exitButton.rectangle = {
            centerScreenX - (exitButton.normal.width / 2),
            (centerScreenY - (exitButton.normal.height / 2)) + (exitButton.normal.height * -1.1f),
            static_cast<float>(exitButton.normal.width),
            static_cast<float>(exitButton.normal.height)
    };
    LoadButtonAssets(exitButton, 15);
    exitButton.text = "Quit Game";
}

void MainMenu::Update() {
    // Input handling
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        if (IsMouseOverButton(playButton)) {
            // Change to Play Screen
            PlaySound(selectSound);
        }
        else if (IsMouseOverButton(optionsButton)) {
            // Change to Options Screen
            PlaySound(selectSound);
        }
        else if (IsMouseOverButton(exitButton)) {
            // Quit Game
            PlaySound(selectSound);
        }
    }
}

void MainMenu::Render() {
    // Draw
    BeginDrawing();
    DrawFPS(10, 10);
    ClearBackground(RAYWHITE);

    // Draw buttons
    DrawButton(playButton);
    DrawButton(optionsButton);
    DrawButton(exitButton);

    EndDrawing();
}

void MainMenu::LoadButtonAssets(Button& button, float scale) {
    button.normal = LoadTexture("assets/ui/buttons/medium/normal.png");
    button.normal.width *= scale;
    button.normal.height *= scale;

    button.highlighted = LoadTexture("assets/ui/buttons/medium/highlighted.png");
    button.highlighted.width *= scale;
    button.highlighted.height *= scale;

    button.clicked = LoadTexture("assets/ui/buttons/medium/clicked/highlighted.png");
    button.clicked.height *= scale;
    button.clicked.width *= scale;

    // Scale Textures
}

bool MainMenu::IsMouseOverButton(const Button& button) {
    return CheckCollisionPointRec(GetMousePosition(), button.rectangle);
}

void MainMenu::DrawButton(const Button& button) {
    DrawTextureRec(IsMouseOverButton(button) && IsMouseButtonDown(MOUSE_LEFT_BUTTON) ? button.clicked : (IsMouseOverButton(button) ? button.highlighted : button.normal),
                   { 0, 0, static_cast<float>(button.normal.width), static_cast<float>(button.normal.height) },
                   { button.rectangle.x, button.rectangle.y }, WHITE);

    int textSize = MeasureText(button.text.c_str(), 120) / 2;
    DrawText(button.text.c_str(), centerScreenX - textSize, button.rectangle.y - (button.rectangle.height / 5), 120, BLACK);
}

void MainMenu::unload() {
    UnloadTexture(playButton.normal);
    UnloadTexture(playButton.highlighted);
    UnloadTexture(playButton.clicked);

    UnloadTexture(optionsButton.normal);
    UnloadTexture(optionsButton.highlighted);
    UnloadTexture(optionsButton.clicked);

    UnloadTexture(exitButton.normal);
    UnloadTexture(exitButton.highlighted);
    UnloadTexture(exitButton.clicked);

    UnloadSound(selectSound);
}
