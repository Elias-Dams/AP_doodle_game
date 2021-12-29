
#include "M_Blue_Platform.h"

Model::Blue_Platform::Blue_Platform(float platformWidth, float platformHeight, int world_Width) :
    platform_width(platformWidth),
    platform_height(platformHeight) {
    position.first = 0;
    position.second = 0;
    min = 0;
    max = world_Width;
    left = true;
    color = "Blue";
}

const pair<float, float> &Model::Blue_Platform::getPosition() const {
    return position;
}

void Model::Blue_Platform::setPosition(const float &x, const float &y) {
    Blue_Platform::position = make_pair(x, y);
    NotifyPosition(position.first, position.second);
}

void Model::Blue_Platform::update(float dt) {
    if (!left and position.first >= max - platform_width) {
        left = true;
    } else if (left and position.first <= min) {
        left = false;
    }

    if (left) {
        position.first -= (2.0f * dt * 60.0f);
    } else if (!left) {
        position.first += (2.0f * dt * 60.0f);
    }
    NotifyPosition(position.first, position.second);
}

float Model::Blue_Platform::getWidth() const {
    return platform_width;
}

float Model::Blue_Platform::getHeight() const {
    return platform_height;
}

const string &Model::Blue_Platform::getColor() const {
    return color;
}

Model::Blue_Platform::~Blue_Platform() {

}
