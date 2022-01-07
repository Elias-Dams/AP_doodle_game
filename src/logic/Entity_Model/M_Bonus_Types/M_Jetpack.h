
#ifndef AP_DOODLE_GAME_M_JETPACK_H
#define AP_DOODLE_GAME_M_JETPACK_H

#include "../M_Bonus.h"


/**
 * @class Jetpack
 *
 * @brief the Jetpack is a Bonus in the Game.
 * When this Bonus is collected the Player jumps/flies 12 times higher.
 */
class Model::Jetpack : public Model::Bonus {
public:
    /**
     * Jetpack constructor.
     * constructs a Jetpack whit a certain width and height
     */
    Jetpack(float Width, float Height);

    const pair<float, float> &getPosition() const override;

    void setPosition(const float x, const float y) override;

    void update(const float x, const float y) override;

    float getWidth() const override;

    float getHeight() const override;

    int getBonuspower() const override;

    virtual ~Jetpack();

private:
    pair<float, float> position; ///< position of the jetpack

    float jetpack_width; ///< the width of the jetpack
    float jetpack_height; ///< the height of the jetpack
};


#endif//AP_DOODLE_GAME_JETPACK_H
