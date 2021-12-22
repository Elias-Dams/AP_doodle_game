
#include "Player.h"

#include <utility>

View::Player::Player(Entity_Model &subject, float playerWidth_, float playerHeight_, shared_ptr<Camera> camera_) :
    Entity_View(subject), camera(camera_), playerWidth(playerWidth_), playerHeight(playerHeight_) {
    // we initiaize a new player

    try {
        if (!left_texture.loadFromFile("../Textures/Chicken/chicken1-left.png")) {
            string error = "Loading player failed";
            throw error;
        }
        if (!right_texture.loadFromFile("../Textures/Chicken/chicken1-right.png")) {
            string error = "Loading player failed";
            throw error;
        }
        if (!left_spring_texture.loadFromFile("../Textures/Chicken/chicken-spring-left.png")) {
            string error = "Loading player failed";
            throw error;
        }
        if (!right_spring_texture.loadFromFile("../Textures/Chicken/chicken-spring-right.png")) {
            string error = "Loading player failed";
            throw error;
        }
        if (!left_jetpack_texture.loadFromFile("../Textures/Chicken/chicken-jetpack-left.png")) {
            string error = "Loading player failed";
            throw error;
        }
        if (!right_jetpack_texture.loadFromFile("../Textures/Chicken/chicken-jetpack-right.png")) {
            string error = "Loading player failed";
            throw error;
        } else {
            // we give the player a texture
            current_right_texture = right_texture;
            current_left_texture = left_texture;
            left = false;
            right = true;
            player.setTexture(current_right_texture);
        }
    } catch (string &a) {
        cerr << a << endl;
    }

    player.setScale(playerWidth / right_texture.getSize().x, playerHeight / right_texture.getSize().y);
}

void View::Player::UpdatePosition(float xpos, float ypos) {
    sf::Vector2f prev_coordiantes = player.getPosition();
    if (prev_coordiantes.x > xpos) {
        player.setTexture(current_left_texture);
        left = true;
        right = false;
    } else if (prev_coordiantes.x < xpos) {
        player.setTexture(current_right_texture);
        left = false;
        right = true;
    }
    //cout << "we are getting updates" << endl;

    player.setPosition(camera->toGamewidth(xpos, playerWidth), camera->toGameheight(ypos, playerHeight));
}


sf::Sprite View::Player::getPlayer() const {
    return player;
}

void View::Player::setTexture() {
    if (left) {
        player.setTexture(current_left_texture);
    } else if (right) {
        player.setTexture(current_right_texture);
    }
}

void View::Player::UpdateSpringCollected() {
    current_right_texture = right_spring_texture;
    current_left_texture = left_spring_texture;
    this->setTexture();
}

void View::Player::UpdateJetpackCollected() {
    current_right_texture = right_jetpack_texture;
    current_left_texture = left_jetpack_texture;
    this->setTexture();
}

void View::Player::ResetTexture() {
    current_right_texture = right_texture;
    current_left_texture = left_texture;
    this->setTexture();
}

View::Player::~Player() {
    cout << "destructor Player" << endl;
}