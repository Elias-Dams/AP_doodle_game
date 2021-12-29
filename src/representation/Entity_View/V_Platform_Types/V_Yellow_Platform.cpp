
#include "V_Yellow_Platform.h"

#include <memory>

View::Yellow_Platform::Yellow_Platform(const float &platformWidth_, const float &platformHeight_, const shared_ptr<Camera> &camera_) :
    camera(camera_), platformWidth(platformWidth_), platformHeight(platformHeight_) {
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
    platform->setColor(sf::Color::Yellow);
}

void View::Yellow_Platform::UpdatePosition(const float &xpos, const float &ypos) {
    platform->setPosition(camera->toGamewidth(xpos, platformWidth), camera->toGameheight(ypos, platformHeight));
}

sf::Sprite View::Yellow_Platform::getPlatform() const {
    return *platform;
}

View::Yellow_Platform::~Yellow_Platform() {

}
