//
// Created by illyum on 6/30/2023.
//

#include "ui.hpp"
#include <raylib.h>


Rectangle UiButton::getHitbox() const {
    float hitboxX = center - hitboxWidth / 2;
    float hitboxY = center - hitboxHeight / 2;

    return { hitboxX, hitboxY, hitboxWidth, hitboxHeight };
}

UiButton getButton(const char* path, float scale) {
    UiButton uiButton;
    Texture2D normalTexture2D = LoadTexture(path);
    uiButton.normalTextureWidth = normalTexture2D.width *= scale;
    uiButton.normalTextureHeight = normalTexture2D.height *= scale;

    Texture2D hoverTexture2D = LoadTexture(path);
    uiButton.hoverTextureWidth = normalTexture2D.width *= scale;
    uiButton.normalTextureHeight = normalTexture2D.height *= scale;

    Texture2D clickedTexture2D = LoadTexture(path);
    uiButton.clickedTextureWidth = normalTexture2D.width *= scale;
    uiButton.clickedTextureHeight = normalTexture2D.height *= scale;


}