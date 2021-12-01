
#include "Camera.h"

Camera::Camera(float cameraWidth, float cameraHeight) : CameraWidth(cameraWidth), CameraHeight(cameraHeight) {
    height = cameraHeight/2;
    prev_height = cameraHeight/2;
}

float Camera::getHeight() const {
    return height;
}

float Camera::getHeightdiff() const {
    if (height-prev_height < 2.0f){
        return 0;
    }
    else{
        return height - prev_height;
    }

}

void Camera::setHeight(float height_) {
    prev_height = height;
    Camera::height = height_;
}

