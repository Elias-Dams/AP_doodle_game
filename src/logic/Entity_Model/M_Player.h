
#ifndef AP_DOODLE_GAME_M_PLAYER_H
#define AP_DOODLE_GAME_M_PLAYER_H

#include "Entity_Model.h"
#include "Namespaces.cpp"
#include <cmath>
#include <vector>

/**
 * @class Player
 *
 * @brief An most important entity of the game.
 * The Player jumps on platforms collects bonuses and tries to move up in the World.
 */
class Model::Player : public Entity_Model {

public:
    /**
     * Player constructor.
     * Constructs the Player whit a certain width and height.
     */
    Player(const float &player_width, const float &player_height);

    /**
    * @brief Moves a player to a new position.
    *
    * This function updates the position of the player by adding the 
    * distance travelled on the x axis and the y axis to the current position.
    *
    * @param x: the distance travelled on the x axis.
    * @param y: the distance travelled on the y axis.
    */
    void move(const float &x, const float &y);

    /**
    * @brief Makes the player jump.
    *
    * This function makes the player jump bye adding a certain gravity to this player.
    * If a platorm is hit this gravity constant is reset and the player jumps up.
    *
    * @param dt: delta time (time it takes to render a frame)
    * @param hit: indication that a platform has been hit.
    * @param height_modifier: the height modification of the bonus;
    */
    void jump(const float &dt, const bool &hit,const int &height_modifier);

    /**
    * @brief Checks if the player is falling.
    *
    * This function is used to check if the player is falling so it can collide with another entity.
    *
    * @return True if the player is falling. False if the player is going up.
    */
    bool isfalling() const;

    /**
    * @brief Fully resets the player
    *
    * This function resets the player to the state it was in when it was first initialized.
    *
    * @param startposx: startposition of the player on the x axis.
    * @param startposy: startposition of the player on the y axis.
    */
    void PlayerReset(const float &startposx, const float &startposy);

    /**
    * @brief Sets the platform last touched by the player.
    *
    * This function sets the platform last touched by the player.
    *
    * @param platfomTouched: platform last touched by the player.
    */
    void setPlatfomTouched(const shared_ptr<Entity_Model> &platfomTouched);

    // documentation in Entity_model
    float getWidth() const override;

    // documentation in Entity_model
    float getHeight() const override;

    // documentation in Entity_model
    const pair<float, float> &getPosition() const override;

    // documentation in Entity_model
    void setPosition(const float &x, const float &y) override;

    virtual ~Player();


private:
    pair<float, float> position; ///< position of the player

    float gravity; ///< constant to calculate the jump
    float player_width; ///< the width of the player
    float player_height; ///< the height of the player
    float jumpheigt; ///< jumpheight of the player

    shared_ptr<Entity_Model> platfom_touched; ///< the platform last touched by the player

    bool falling; ///< keep track of whether the player falls
};


#endif//AP_DOODLE_GAME_PLAYER_H
