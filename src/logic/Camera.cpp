
#include "Camera.h"

Camera::Camera(const float &cameraWidth, const float &cameraHeight) :
    CameraWidth(cameraWidth), CameraHeight(cameraHeight) {
    height = cameraHeight / 2.0f;
}

float Camera::getNomalisedHeight() const {
    return height;
}

float Camera::getConvertedHeight() const {
    return CameraHeight - height;
}

void Camera::setHeight(const float &height_) {
    float temp = height_ - height;
    Camera::height = height_;
    NewMaxHeigh(temp);
}

float Camera::toGameheight(const float &position, const float &entity_height) {
    return CameraHeight - position - entity_height;
}

float Camera::toGamewidth(const float &position, const float &entity_height) {
    return position;
}

void Camera::CameraReset() {
    height = CameraHeight / 2.0f;
}

Camera::~Camera() {

}
float Camera::getCameraWidth() const {
    return CameraWidth;
}

float Camera::getCameraHeight() const {
    return CameraHeight;
}

