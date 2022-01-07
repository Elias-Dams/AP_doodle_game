
#ifndef AP_DOODLE_GAME_CAMERA_H
#define AP_DOODLE_GAME_CAMERA_H

#include <iostream>
#include "design_patterns/Subject.h"

/**
 * @class Camera
 *
 * @brief Explicitly modelles the view of the Player.
 */
class Camera : public Subject{
public:
    /**
     * camera constructor.
     * constructs the camera whit a certain width and height
     */
    Camera(const float &cameraWidth, const float &cameraHeight);

    /**
    * @brief gives the normalised height
    *
    * This function gives the normalised height of a normalised coordinate system
    *
    * @return normalised height
    */
    float getNomalisedHeight() const;

    /**
    * @brief gives the converted height
    *
    * This function gives the converted height of a coordinates system
    * in this case the sfml coordinate system
    *
    * @return converted height
    */
    float getConvertedHeight() const;

    /**
    * @brief sets the height
    *
    * This function sets the height of the camera
    *
    * @param height: the hight the camera needt to be on
    */
    void setHeight(const float &height);

    /**
    * @brief converts the height to game height
    *
    * This function converts the height to game height
    * it is the height in the normalised coordinate stelsel
    *
    * @param position: the position of the entity
    * @param entity_height: the height of the entity
    */
    float toGameheight(const float &position, const float &entity_height);

    /**
    * @brief converts the height to game width
    *
    * This function converts the width to game width
    * it is the width in the normalised coordinate stelsel
    *
    * @param position: the position of the entity
    * @param entity_height: the width of the entity
    */
    float toGamewidth(const float &position, const float &entity_width);

    /**
    * @brief fully resets the camera
    *
    * This function resets the camera to the state it was in when it was first initialized
    *
    */
    void CameraReset();

    /**
    * @brief returns the camera width
    *
    * This function returns the camera width
    *
    * @return camera width
    */
    float getCameraWidth() const;

    /**
    * @brief returns the camera height
    *
    * This function returns the camera height
    *
    * @return camera height
    */
    float getCameraHeight() const;

    virtual ~Camera();




private:
    float CameraWidth; ///< the width of the camera (dimension)
    float CameraHeight; ///< the height  of the camera (dimension)
    float height; ///< height of the camera (position)
};


#endif//AP_DOODLE_GAME_CAMERA_H
