
#include "EV_BG_Tile.h"

View::EV_BG_Tile::EV_BG_Tile(Subject &subject, float width, float height, shared_ptr<Camera> camera_) : Entity_View(subject), camera(camera_), width(width),
                                                                      height(height) {

    try {
        if (!texture.loadFromFile("../Textures/Doodle/bg.png")){
            string error = "Loading background failed";
            throw error;
        }
        else{
            // we give the player a texture
            background.setTexture(texture);
        }
    }
    catch(string& a){
        cerr << a << endl;
    }

    background.setScale( width / texture.getSize().x , height / texture.getSize().y );
}

void View::EV_BG_Tile::UpdatePosition(float xpos, float ypos){
    background.setPosition(camera->toGamewidth(xpos, width),camera->toGameheight(ypos, height));
}

const sf::Sprite &View::EV_BG_Tile::getBackground() const {
    return background;
}

View::EV_BG_Tile::~EV_BG_Tile() {
    cout << "destructor of EV_BG_Tile" << endl;
}
