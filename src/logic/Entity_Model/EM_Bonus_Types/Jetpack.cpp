
#include "Jetpack.h"

Model::Jetpack::Jetpack(float Width, float Height) : jetpack_width(Width), jetpack_height(Height) {
    position.first = 0;
    position.second = 0;
}

const pair<float, float> &Model::Jetpack::getPosition() const {
    return position;
}

void Model::Jetpack::setPosition(const float &x, const float &y) {
    Jetpack::position = make_pair(x, y);
    NotifyPosition(position.first, position.second);
}

void Model::Jetpack::update(float x, float y) {
    position.first = x;
    position.second = y;
    NotifyPosition(position.first, position.second);
}

float Model::Jetpack::getWidth() const {
    return jetpack_width;
}

float Model::Jetpack::getHeight() const {
    return jetpack_height;
}

int Model::Jetpack::getBonuspower() const {
    return 12; // jump 12 times higher
}

Model::Jetpack::~Jetpack() {
    cout << "destructor of Jetpack" << endl;
}
