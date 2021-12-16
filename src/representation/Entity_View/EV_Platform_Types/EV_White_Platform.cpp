
#include "EV_White_Platform.h"

EV_White_Platform::EV_White_Platform(Entity_Model &subject, float platformWidth_, float platformHeight_, shared_ptr<Camera> camera_) : EV_Platform(subject), camera(camera_), platformWidth(platformWidth_), platformHeight(platformHeight_) {
    // we initiaize a new platform

    platform = unique_ptr<sf::Sprite>(new sf::Sprite);
    texture = unique_ptr<sf::Texture>(new sf::Texture);

    try {
        if (!texture->loadFromFile("../Textures/Doodle/1jump_panel.png")){
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

    platform->setScale( platformWidth_ / texture->getSize().x , platformHeight_ / texture->getSize().y );
    platform->setColor(sf::Color::White);
}

void EV_White_Platform::UpdatePosition(float xpos, float ypos){
    //cout << "jeej we get updates" << endl;
    platform->setPosition(camera->toGamewidth(xpos, platformWidth), camera->toGameheight(ypos, platformHeight));
}

sf::Sprite EV_White_Platform::getPlatform() const {
    return *platform;
}

EV_White_Platform::~EV_White_Platform() {
    cout << "destructor of EV_White_Platform" << endl;
}
