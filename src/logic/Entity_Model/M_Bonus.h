
#ifndef AP_DOODLE_GAME_M_BONUS_H
#define AP_DOODLE_GAME_M_BONUS_H

#include "Entity_Model.h"
#include "Namespaces.cpp"

/**
 * @class Bonus
 *
 * @brief A Bonus (temporarily) modifies the state or behaviour of an Entity.
 */
class Model::Bonus : public Entity_Model {
public:
    virtual const pair<float, float> &getPosition() const = 0;

    virtual float getWidth() const = 0;

    virtual float getHeight() const = 0;

    virtual void setPosition(const float &x, const float &y) = 0;

    /**
    * @brief Updates the position of the bonus if it can move.
    *
    * This function updates the position of the bonus if it can move.
    * This is the case if it is on a moving platform.
    *
    * @param x: position of the platform the bonus is on.
    * @param y: position of the platform the bonus is on.
    */
    virtual void update(const float &x, const float &y) = 0;

    /**
    * @brief Get the bonuspower.
    *
    * This function gets the power of a certain bonus.
    * E.g. the spring makes the player jump x5 higher.
    *
    * @return Gets the type of the bonus
    */
    virtual int getBonuspower() const = 0;

    virtual ~Bonus();
};


#endif//AP_DOODLE_GAME_BONUS_H
