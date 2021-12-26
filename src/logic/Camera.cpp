
#include "Camera.h"

Camera::Camera(float cameraWidth, float cameraHeight) :
    CameraWidth(cameraWidth), CameraHeight(cameraHeight) {
    height = cameraHeight / 2;
}

float Camera::getNomalisedHeight() const {
    return height;
}

float Camera::getConvertedHeight() const {
    return CameraHeight - height;
}

void Camera::setHeight(float height_) {
    float temp = height_ - height;
    Camera::height = height_;
    NewMaxHeigh(temp);
}

float Camera::toGameheight(float position, float entity_height) {
    return CameraHeight - position - entity_height;
}

float Camera::toGamewidth(float position, float entity_height) {
    return position;
}

void Camera::CameraReset() {
    height = CameraHeight / 2;
}

Camera::~Camera() {

}
