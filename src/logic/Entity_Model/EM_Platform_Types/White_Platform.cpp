
#include "White_Platform.h"

Model::White_Platform::White_Platform(float platformWidth, float platformHeight) :
    platform_width(platformWidth),
    platform_height(platformHeight) {
    position.first = 0;
    position.second = 0;
    color = "White";
}

const pair<float, float> &Model::White_Platform::getPosition() const {
    return position;
}

void Model::White_Platform::setPosition(const float &x, const float &y) {
    White_Platform::position = make_pair(x, y);
    NotifyPosition(position.first, position.second);
}

void Model::White_Platform::update(float dt) {
    // the platform doesn't move
    NotifyPosition(position.first, position.second);
}

float Model::White_Platform::getWidth() const {
    return platform_width;
}

float Model::White_Platform::getHeight() const {
    return platform_height;
}

const string &Model::White_Platform::getColor() const {
    return color;
}

Model::White_Platform::~White_Platform() {

}
