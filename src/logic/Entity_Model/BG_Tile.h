
#ifndef AP_DOODLE_GAME_M_BG_TILE_H
#define AP_DOODLE_GAME_M_BG_TILE_H

#include "Entity_Model.h"
#include "Namespaces.cpp"

class Model::BG_Tile : public Entity_Model {
public:
    BG_Tile(float width, float height);

    ~BG_Tile();

    float getWidth() const;

    float getHeight() const;

    const pair<float, float> &getPosition() const;

    void setPosition(const float &posx,const float &posy);

private:
    pair<float, float> position;
    float width;
    float height;
};


#endif //AP_DOODLE_GAME_BG_TILE_H
