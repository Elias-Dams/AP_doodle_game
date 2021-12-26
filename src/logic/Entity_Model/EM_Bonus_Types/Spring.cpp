
#include "Spring.h"

Model::Spring::Spring(float Width, float Height) :
    spring_width(Width), spring_height(Height) {
    position.first = 0;
    position.second = 0;
}

const pair<float, float> &Model::Spring::getPosition() const {
    return position;
}

void Model::Spring::setPosition(const float &x, const float &y) {
    Spring::position = make_pair(x, y);
    NotifyPosition(position.first, position.second);
}

void Model::Spring::update(float x, float y) {
    position.first = x;
    position.second = y;
    NotifyPosition(position.first, position.second);
}

float Model::Spring::getWidth() const {
    return spring_width;
}

float Model::Spring::getHeight() const {
    return spring_height;
}

int Model::Spring::getBonuspower() const {
    return 5; // jump x5 times higher
}

Model::Spring::~Spring() {

}
