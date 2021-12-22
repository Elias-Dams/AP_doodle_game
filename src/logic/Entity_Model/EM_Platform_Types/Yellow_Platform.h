
#ifndef AP_DOODLE_GAME_M_YELLOW_PLATFORM_H
#define AP_DOODLE_GAME_M_YELLOW_PLATFORM_H

#include "../Platform.h"

/**
 * @class Yellow_Platform
 *
 * An entity with which the player can come into contact in order to move up in the world.
 * The yellow platform moves up and down within a certain range
 */

class Model::Yellow_Platform : public Model::Platform {

public:
    /**
     * Yellow_Platform constructor.
     * constructs a Yellow_Platform whit a certain width and height and moveheight
     */
    Yellow_Platform(float platformWidth, float platformHeight, float moveheight);

    const pair<float, float> &getPosition() const override;

    void setPosition(const float &x, const float &y) override;

    void update(float dt) override;

    float getWidth() const override;

    float getHeight() const override;

    const string &getColor() const override;

    ~Yellow_Platform() override;


private:
    pair<float, float> position; ///< position of the platform

    float platform_width; ///< the width of the platform
    float platform_height; ///< the height of the platform
    float virtual_pos; ///< virtual pos if the platform in a certain range
    float min; ///< minimum val of the range
    float max; ///< maximum val of the range

    bool up; ///< keep track of whether the platform is moving up/down

    string color; ///< the color of the platform
};


#endif//AP_DOODLE_GAME_YELLOW_PLATFORM_H