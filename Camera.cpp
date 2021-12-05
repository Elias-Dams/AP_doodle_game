
#include "Camera.h"

Camera::Camera(float cameraWidth, float cameraHeight) : CameraWidth(cameraWidth), CameraHeight(cameraHeight) {
    height = cameraHeight/2;
}

float Camera::getHeight() const {
    return height;
}

void Camera::setHeight(float height_) {
    Camera::height = height_;
}

