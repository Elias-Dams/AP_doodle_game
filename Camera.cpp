
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

float Camera::toGameheight(float position, float entity_height){
    std::cout << "position: " << position << std::endl;
    std::cout << "new position: " << CameraHeight - position - entity_height << std::endl;
    return CameraHeight - position - entity_height;
}

float Camera::toGamewidth(float position, float entity_height){
    return position;
}