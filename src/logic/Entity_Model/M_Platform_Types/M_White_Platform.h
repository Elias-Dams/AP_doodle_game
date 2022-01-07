
#ifndef AP_DOODLE_GAME_M_WHITE_PLATFORM_H
#define AP_DOODLE_GAME_M_WHITE_PLATFORM_H

#include "../M_Platform.h"

/**
 * @class White_Platform
 *
 * @brief An entity with which the Player can come into contact in order to move up in the World.
 * The white platform disappears when the player has jumped onto it.
 */
class Model::White_Platform : public Model::Platform {

public:
    /**
     * White_Platform constructor.
     * constructs a White_Platform with a certain width and height.
     */
    White_Platform(float platformWidth, float platformHeight);

    const pair<float, float> &getPosition() const override;

    void setPosition(const float x, const float y) override;

    void update(const float dt) override;

    float getWidth() const override;

    float getHeight() const override;

    const string &getColor() const override;

    virtual ~White_Platform() override;

private:
    pair<float, float> position; ///< position of the platform

    float platform_width; ///< the width of the platform
    float platform_height; ///< the height of the platform

    string color; ///< the color of the platform
};


#endif//AP_DOODLE_GAME_WHITE_PLATFORM_H
