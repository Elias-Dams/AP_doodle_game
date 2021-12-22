/*
 * Deze vormen de achtergrond van je spel door ze in een raster te plaatsen.
 * Om deze tegels samen met de rest van de wereld te laten scrollen, moeten
 * ze ook dynamisch worden aangemaakt en vernietigd of automatisch gerecycled
 * worden van onder naar boven.
 */

#ifndef AP_DOODLE_GAME_EM_BG_TILE_H
#define AP_DOODLE_GAME_EM_BG_TILE_H

#include "Entity_Model.h"
#include "namespaces.cpp"

class Model::EM_BG_Tile : public Entity_Model {
public:
    EM_BG_Tile(float width, float height);

    ~EM_BG_Tile();

    float getWidth() const;

    float getHeight() const;

    const pair<float, float> &getPosition() const;

    void setPosition(const float &posx,const float &posy);

private:
    pair<float, float> position;
    float width;
    float height;
};


#endif //AP_DOODLE_GAME_EM_BG_TILE_H
