
#ifndef AP_DOODLE_GAME_M_SPRING_H
#define AP_DOODLE_GAME_M_SPRING_H

#include "../M_Bonus.h"

/**
 * @class Spring
 *
 * @brief the Spring is a Bonus in the Game.
 * When this Bonus is collected the Player jumps/flies 5 times higher.
 */
class Model::Spring : public Model::Bonus {
public:
    /**
     * Spring constructor.
     * constructs a Spring whit a certain width and height
     */
    Spring(float Width, float Height);

    const pair<float, float> &getPosition() const override;

    void setPosition(const float &x, const float &y) override;

    void update(const float &x, const float &y) override;

    float getWidth() const override;

    float getHeight() const override;

    int getBonuspower() const override;

    virtual ~Spring();

private:
    pair<float, float> position ; ///< position of the Spring

    float spring_width; ///< the width of the Spring
    float spring_height; ///< the height of the Spring
};


#endif//AP_DOODLE_GAME_SPRING_H
