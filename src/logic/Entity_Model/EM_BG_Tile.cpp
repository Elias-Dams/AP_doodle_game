
#include "EM_BG_Tile.h"

Model::EM_BG_Tile::EM_BG_Tile(float width, float height) : width(width), height(height) {
    position.first = 0;
    position.second = 0;
}

const pair<float, float> &Model::EM_BG_Tile::getPosition() const {
    return position;
}

void Model::EM_BG_Tile::setPosition(const float &posx, const float &posy) {
    position.first = posx;
    position.second = posy;
    NotifyPosition(posx, posy);
}

float Model::EM_BG_Tile::getWidth() const {
    return width;
}

float Model::EM_BG_Tile::getHeight() const {
    return height;
}

Model::EM_BG_Tile::~EM_BG_Tile() {
    cout << "destructor of EM_BG_Tile" << endl;
}