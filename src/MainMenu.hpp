//
// Created by illyum on 6/26/2023.
//

#ifndef MOBSLAYER_MAINMENU_HPP
#define MOBSLAYER_MAINMENU_HPP


// MainMenu.h

#ifndef MAINMENU_H
#define MAINMENU_H

#include <string>
#include <raylib.h>
#include "GameObject.hpp"

struct Button {
    Rectangle rectangle;
    Texture2D normal;
    Texture2D highlighted;
    Texture2D clicked;
    std::string text;
};

class MainMenu {
public:
    MainMenu(float scale, float screenX, float screenY);
    void Update();
    void Render();
    void unload();
//
//private:
    float centerScreenX;
    float centerScreenY;

    Sound selectSound;
    Button playButton;
    Button optionsButton;
    Button exitButton;

    void LoadButtonAssets(Button& button, float scale);
    void DrawButton(const Button& button);
    bool IsMouseOverButton(const Button& button);
};

#endif



#endif //MOBSLAYER_MAINMENU_HPP
