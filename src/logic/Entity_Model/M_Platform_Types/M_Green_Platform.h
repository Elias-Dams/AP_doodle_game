
#ifndef AP_DOODLE_GAME_M_GREEN_PLATFORM_H
#define AP_DOODLE_GAME_M_GREEN_PLATFORM_H

#include "../M_Platform.h"

/**
 * @class White_Platform
 *
 * @brief An entity with which the Player can come into contact in order to move up in the World.
 * The Green platform is the most basic platform, it has no special feature.
 */
class Model::Green_Platform : public Model::Platform {

public:
    /**
     * Green_Platform constructor.
     * constructs a Green_Platform with a certain width and height.
     */
    Green_Platform(float platformWidth, float platformHeight);

    const pair<float, float> &getPosition() const override;

    void setPosition(const float &x, const float &y) override;

    void update(const float &dt) override;

    float getWidth() const override;

    float getHeight() const override;

    const string &getColor() const override;

    virtual ~Green_Platform() override;


private:
    pair<float, float> position; ///< position of the platform

    float platform_width; ///< the width of the platform
    float platform_height; ///< the height of the platform

    string color; ///< the color of the platform
};


#endif//AP_DOODLE_GAME_GREEN_PLATFORM_H
