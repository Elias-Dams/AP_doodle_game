
#include "EV_Platform.h"

EV_Platform::EV_Platform(Entity_Model &subject, float platformWidth, float platformHeight) : Entity_View(subject) {
    // we initiaize a new player

    platform = new sf::Sprite;
    texture = new sf::Texture;

    try {
        if (!texture->loadFromFile("../Textures/1jump_panel.png")){
            string error = "Loading platform failed";
            throw error;
        }
        else{
            // we give the platform a texture
            platform->setTexture(*texture);
        }
    }
    catch(string& a){
        cerr << a << endl;
    }

    platform->setScale( platformWidth / texture->getSize().x , platformHeight / texture->getSize().y );
    platform->setColor(sf::Color::Green);
}

void EV_Platform::Update(float xpos, float ypos){
    //cout << "jeej we get updates" << endl;
    ypos = 570-ypos;
    platform->setPosition(xpos, ypos);
}

sf::Sprite EV_Platform::getPlatform() const {
    return *platform;
}


