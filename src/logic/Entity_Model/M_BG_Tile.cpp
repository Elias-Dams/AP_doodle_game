
#include "M_BG_Tile.h"

Model::BG_Tile::BG_Tile(float width, float height) :
    width(width), height(height) {
    position.first = 0;
    position.second = 0;
}

const pair<float, float> &Model::BG_Tile::getPosition() const {
    return position;
}

void Model::BG_Tile::setPosition(const float &posx, const float &posy) {
    position.first = posx;
    position.second = posy;
    NotifyPosition(posx, posy);
}

float Model::BG_Tile::getWidth() const {
    return width;
}

float Model::BG_Tile::getHeight() const {
    return height;
}

Model::BG_Tile::~BG_Tile() {

}