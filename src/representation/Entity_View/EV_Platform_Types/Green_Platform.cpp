
#include "Green_Platform.h"

#include <memory>

View::Green_Platform::Green_Platform(Entity_Model &subject, float platformWidth_, float platformHeight_, shared_ptr<Camera> camera_) :
    Platform(subject), camera(camera_), platformWidth(platformWidth_), platformHeight(platformHeight_) {
    // we initiaize a new platform

    platform = std::make_unique<sf::Sprite>();
    texture = std::make_unique<sf::Texture>();

    try {
        if (!texture->loadFromFile("../Textures/Doodle/1jump_panel.png")) {
            string error = "Loading platform failed";
            throw error;
        } else {
            // we give the platform a texture
            platform->setTexture(*texture);
        }
    } catch (string &a) {
        cerr << a << endl;
    }

    platform->setScale(platformWidth_ / texture->getSize().x, platformHeight_ / texture->getSize().y);
    platform->setColor(sf::Color::Green);
}

void View::Green_Platform::UpdatePosition(float xpos, float ypos) {
    //cout << "jeej we get updates" << endl;
    platform->setPosition(camera->toGamewidth(xpos, platformWidth), camera->toGameheight(ypos, platformHeight));
}

sf::Sprite View::Green_Platform::getPlatform() const {
    return *platform;
}

View::Green_Platform::~Green_Platform() {
    cout << "destructor of Green_Platform" << endl;
}