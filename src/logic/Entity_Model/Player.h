
#ifndef AP_DOODLE_GAME_M_PLAYER_H
#define AP_DOODLE_GAME_M_PLAYER_H

#include "Entity_Model.h"
#include "Namespaces.cpp"
#include <cmath>
#include <vector>

/**
 * @class Player
 *
 * An most important entity of the game.
 * The player jumps on platforms collects bonuses and tries to move up in the world.
 */
class Model::Player : public Entity_Model {

public:
    /**
     * Player constructor.
     * constructs the Player whit a certain width and height
     */
    Player(float player_width, float player_height);

    /**
    * @brief moves a player to a new position.
    *
    * This function updates the position of the player bye adding.
    * the the distance travelled on the x axis and the y axis to the current position.
    *
    * @param x: the distance travelled on the x axis.
    * @param y: the distance travelled on the y axis.
    */
    void move(const float &x, const float &y);

    /**
    * @brief makes the player jump.
    *
    * This function makes the player jump bye adding a certain gravity to player.
    * If a platorm is hit this gravity constant is reset and the player jumps up.
    *
    * @param dt: delta time (time it takes to render a frame)
    * @param hit: indication that a platform has been hit.
    */
    void jump(const float &dt, const bool &hit, const bool &bonus_hit, const string &bonustype);

    /**
    * @brief checks if the player is falling.
    *
    * This function is used to check if the player is falling so it can collide whit an other entity.
    *
    * @return true if the player is falling. False if the player is going up.
    */
    bool isfalling();

    /**
    * @brief resets the max height.
    *
    * this function resets max height reached bye the player.
    *
    */
    void resetmaxheight();

    /**
    * @brief fully resets the player
    *
    * This function resets the player to the state it was in when it was first initialized
    *
    * @param startposx startposition of the player on the x axis.
    * @param startposy startposition of the player on the y axis.
    */
    void PlayerReset(float startposx, float startposy);

    /**
    * @brief get the maxheight.
    *
    * This function is used to check the maxheight of the player.
    *
    * @return the maxheight of the player.
    */
    float getMaxheight() const;

    // documentation in Enntity_model
    float getWidth() const override;

    // documentation in Enntity_model
    float getHeight() const override;

    // documentation in Enntity_model
    const pair<float, float> &getPosition() const override;

    // documentation in Enntity_model
    void setPosition(const float &x, const float &y) override;

    ~Player();

private:
    pair<float, float> position; ///< position of the player

    float maxheight; ///< maxheight of the player
    float gravity; ///< constant to calculate the jump
    float player_width; ///< the width of the player
    float player_height; ///< the height of the player

    bool falling; ///< keep track of whether the player falls
};


#endif//AP_DOODLE_GAME_PLAYER_H
