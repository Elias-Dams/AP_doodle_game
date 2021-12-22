
#ifndef AP_DOODLE_GAME_M_BLUE_PLATFORM_H
#define AP_DOODLE_GAME_M_BLUE_PLATFORM_H

#include "../Platform.h"

/**
 * @class Blue_Platform
 *
 * An entity with which the player can come into contact in order to move up in the world.
 * The Blue platform moves from left to right in a certain range (screen width)
 */
class Model::Blue_Platform : public Model::Platform {

public:
    /**
     *  Blue_Platform constructor.
     * constructs a  Blue_Platform whit a certain width and height and movewidth
     */
    Blue_Platform(float platformWidth, float platformHeight, int world_Width);

    const pair<float, float> &getPosition() const override;

    void setPosition(const float &x, const float &y) override;

    void update(float dt) override;

    float getWidth() const override;

    float getHeight() const override;

    const string &getColor() const override;

    ~Blue_Platform() override;


private:
    pair<float, float> position; ///< position of the platform

    float platform_width; ///< the width of the platform
    float platform_height; ///< the height of the platform
    float min; ///< minimum val of the range
    float max; ///< maximum val of the range

    bool left; ///< keep track of whether the platform is moving left/right

    string color; ///< the color of the platform
};


#endif//AP_DOODLE_GAME_BLUE_PLATFORM_H
