
#include "EM_Jetpack.h"

Model::EM_Jetpack::EM_Jetpack(float Width, float Height) : jetpack_width(Width), jetpack_height(Height) {
    position.first = 0;
    position.second = 0;
}

const pair<float, float> &Model::EM_Jetpack::getPosition() const {
    return position;
}

void Model::EM_Jetpack::setPosition(const float &x, const float &y) {
    EM_Jetpack::position = make_pair(x, y);
    NotifyPosition(position.first, position.second);
}

void Model::EM_Jetpack::update(float x, float y){
    position.first = x;
    position.second = y;
    NotifyPosition(position.first, position.second);
}

float Model::EM_Jetpack::getWidth() const {
    return jetpack_width;
}

float Model::EM_Jetpack::getHeight() const {
    return jetpack_height;
}

string Model::EM_Jetpack::getType() const{
    return "jetpack";
}

Model::EM_Jetpack::~EM_Jetpack() {
    cout << "destructor of EM_Jetpack" << endl;
}
