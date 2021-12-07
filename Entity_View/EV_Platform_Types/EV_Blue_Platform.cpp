
#include "EV_Blue_Platform.h"

EV_Blue_Platform::EV_Blue_Platform(Entity_Model &subject, float platformWidth, float platformHeight) : EV_Platform(subject) {
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
    platform->setColor(sf::Color(82, 170, 228));
}

void EV_Blue_Platform::Update(float xpos, float ypos){
    //cout << "jeej we get updates" << endl;
    ypos = 570-ypos;
    platform->setPosition(xpos, ypos);
}

sf::Sprite EV_Blue_Platform::getPlatform() const {
    return *platform;
}

EV_Blue_Platform::~EV_Blue_Platform() {

}
