
#include "V_Jetpack.h"

View::Jetpack::Jetpack(const float Width, const float Height, const shared_ptr<Camera> &camera_) :
    camera(camera_), jetpack_Width(Width), jetpack_Height(Height) {
    // we initiaize a new platform

    jetpack = unique_ptr<sf::Sprite>(new sf::Sprite);
    texture = unique_ptr<sf::Texture>(new sf::Texture);

    try {
        if (!texture->loadFromFile("../Textures/Doodle/raketa_on_panel.png")) {
            string error = "Loading jetpack failed";
            throw error;
        } else {
            // we give the jetpack a texture
            jetpack->setTexture(*texture);
        }
    } catch (string &a) {
        cerr << a << endl;
    }

    jetpack->setScale(Width / texture->getSize().x, Height / texture->getSize().y);
    jetpack->setColor(sf::Color(82, 170, 228));
}

void View::Jetpack::UpdatePosition(const float xpos, const float ypos) {
    jetpack->setPosition(camera->toGamewidth(xpos, jetpack_Width), camera->toGameheight(ypos, jetpack_Height));
}

sf::Sprite View::Jetpack::getBonus() const {
    return *jetpack;
}

View::Jetpack::~Jetpack() {

}
