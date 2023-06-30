//
// Created by illyum on 6/30/2023.
//

#ifndef MOBSLAYER_UI_HPP
#define MOBSLAYER_UI_HPP


#include <raylib.h>


struct UiButton {
    float normalTextureWidth;
    float normalTextureHeight;
    float hoverTextureWidth;
    float hoverTextureHeight;
    float clickedTextureWidth;
    float clickedTextureHeight;

    float hitboxWidth;
    float hitboxHeight;

    float center;

    Rectangle getHitbox() const;
};

UiButton getButton(const char* path, float scale);


class ui {

};


#endif //MOBSLAYER_UI_HPP
