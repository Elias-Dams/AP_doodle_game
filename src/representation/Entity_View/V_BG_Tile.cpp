
#include "V_BG_Tile.h"

View::BG_Tile::BG_Tile(float width, float height, shared_ptr<Camera> camera_) : camera(camera_), width(width),
    height(height) {

    try {
        if (!texture.loadFromFile("../Textures/Doodle/bg.png")) {
            string error = "Loading background failed";
            throw error;
        } else {
            // we give the player a texture
            background.setTexture(texture);
        }
    } catch (string &a) {
        cerr << a << endl;
    }

    background.setScale(width / texture.getSize().x, height / texture.getSize().y);
}

void View::BG_Tile::UpdatePosition(float xpos, float ypos) {
    background.setPosition(camera->toGamewidth(xpos, width), camera->toGameheight(ypos, height));
}

const sf::Sprite &View::BG_Tile::getBackground() const {
    return background;
}

View::BG_Tile::~BG_Tile() {

}
