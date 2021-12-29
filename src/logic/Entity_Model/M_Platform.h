
#ifndef AP_DOODLE_GAME_M_PLATFORM_H
#define AP_DOODLE_GAME_M_PLATFORM_H

#include "Entity_Model.h"
#include "Namespaces.cpp"

/**
 * @class Platform
 *
 * @brief An entity with which the Player can come into contact in order to move up in the World.
 */
class Model::Platform : public Entity_Model {

public:

    /**
    * @brief updates the position of the platform if it can move.
    *
    * This function makes the platform move.
    *
    * @param dt: delta time (time it takes to render a frame)
    */
    virtual void update(const float &d) = 0;

    /**
    * @brief gives the color of the platform.
    *
    * This function gives the color of the platform.
    * this is important because there are different types of platforms with various properties.
    *
    * @return color of the platform.
    */
    virtual const string &getColor() const = 0;

    // documentation in Enntity_model
    virtual const pair<float, float> &getPosition() const = 0;

    // documentation in Enntity_model
    virtual float getWidth() const = 0;

    // documentation in Enntity_model
    virtual float getHeight() const = 0;

    // documentation in Enntity_model
    virtual void setPosition(const float &x, const float &y) = 0;

    virtual ~Platform();
};


#endif//AP_DOODLE_GAME_PLATFORM_H
