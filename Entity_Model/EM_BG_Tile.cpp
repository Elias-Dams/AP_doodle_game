
#include "EM_BG_Tile.h"

EM_BG_Tile::EM_BG_Tile(){
    position.first = 0;
    position.second = 0;
}


const pair<float, float> &EM_BG_Tile::getPosition() const {
    return position;
}

void EM_BG_Tile::setPosition(const float &posx, const float &posy) {
    position.first = posx;
    position.second = posy;
    NotifyPosition(posx, posy);
}

EM_BG_Tile::~EM_BG_Tile() {

}