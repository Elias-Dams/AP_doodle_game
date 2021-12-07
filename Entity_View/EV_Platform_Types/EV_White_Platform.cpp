

#include "EV_White_Platform.h"

EV_White_Platform::EV_White_Platform(Entity_Model &subject, float platformWidth, float platformHeight) : EV_Platform(subject) {
    // we initiaize a new platform

    platform = unique_ptr<sf::Sprite>(new sf::Sprite);
    texture = unique_ptr<sf::Texture>(new sf::Texture);

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
    platform->setColor(sf::Color::White);
}

void EV_White_Platform::Update(float xpos, float ypos){
    //cout << "jeej we get updates" << endl;
    platform->setPosition(xpos, ypos);
}

sf::Sprite EV_White_Platform::getPlatform() const {
    return *platform;
}

EV_White_Platform::~EV_White_Platform() {

}
