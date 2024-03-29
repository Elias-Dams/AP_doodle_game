
#ifndef AP_DOODLE_GAME_WORLD_H
#define AP_DOODLE_GAME_WORLD_H

#include "Camera.h"
#include "Random.h"
#include "design_patterns/Abstract_Factory.h"
#include <iostream>
#include <list>
#include <map>
#include <memory>
#include <string>
#include <typeinfo>
#include <vector>

using namespace Model;
/**
* @class World
*
* @brief Responsible for orchestrating the overall game logic and the interactions between the entities.
*/
class World {
public:
    /**
     * World constructor.
     * vonstructs the World with a pointer to the Abstract factory.
     */
    World(const shared_ptr<Abstract_Factory> &factory);

    /**
    * @brief Handles the start state and game-over state of the game.
    *
    * This function handles the start state game-over state of the game.
    * It makes a platform and lets the player jump in place.
    * The player can't move in this state so there is no need for a key variable.
    *
    * @param dt: delta time (time it takes to render a frame).
    */
    void startstate(const float dt);

    /**
    * @brief Updates the world in the actual game state.
    *
    * This function updates the world in the actual game state.
    * - updates the camera position
    * - updates the background
    * - move the player (with given key)
    * - check collision
    * - destroys and adds platforms
    *
    * @param dt: delta time (time it takes to render a frame).
    * @param key: key that is pressed.
    */
    void update(const float dt, const char key);

    /**
    * @brief Returns the player.
    *
    * This function returns shared pointer of the player.
    *
    * @return shared pointer of the player.
    */
    shared_ptr<Player> getPlayer() const;

    /**
    * @brief Returns the game width.
    *
    * This function returns the game width.
    *
    * @return the game width.
    */
    int getWidth() const;

    /**
    * @brief Returns the game height.
    *
    * This function returns the game height.
    *
    * @return the game height.
    */
    int getHeight() const;

    /**
    * @brief Returns the background.
    *
    * This function returns the background.
    * It is a pair of 2 tiles that updates when the player moves up in the world.
    *
    * @return pair of background Tiles.
    */
    const pair<shared_ptr<BG_Tile>, shared_ptr<BG_Tile>> &getBackground() const;

    /**
    * @brief Returns the camera.
    *
    * This function returns shared pointer of the camera.
    *
    * @return shared pointer of the camera.
    */
    shared_ptr<Camera> getCamera() const;

    /**
    * @brief Returns the platforms.
    *
    * This function returns a vector of shared pointers of platforms.
    *
    * @return a vector of shared pointers of platforms.
    */
    const vector<shared_ptr<Platform>> &getPlatforms() const;

    /**
    * @brief Returns the bonusses.
    *
    * This function returns a map with:
    * - key a shared pointer to a platform
    * - van a shared pointer to a bonus
    *
    * @return a map of bonuses.
    */
    const map<shared_ptr<Platform>, shared_ptr<Bonus>> &getBonuses() const;

    /**
    * @brief Resets the world.
    *
    * This function resets the world to the state it was in when it was first initialized.
    * It handles:
    * - reset of the player
    * - reset of the camera
    * - reset of all the members of the world
    * - clears the vector of platforms
    * - clears the map of bonuses
    *
    */
    void Reset();

    /**
    * @brief Checks if the game is over.
    *
    * This function checks if the game is over.
    *
    * @return True if the game is over. False if the game is not over.
    */
    bool isGameOver() const;

    /**
    * @brief deletes the platforms.
    *
    * This function deletes the platforms.
    */
    void deletePlatforms();

    virtual ~World();


private:
    void create_start_platform();

    void create_platforms();

    void add_platforms();

    bool colisionCheck(shared_ptr<Entity_Model> entity, const bool can_update_score);

    float getFreeSpace();

    shared_ptr<Abstract_Factory> factory; ///< abstract factory

    shared_ptr<Player> player; ///< the player
    vector<shared_ptr<Platform>> platforms; ///< the platforms
    map<shared_ptr<Platform>, shared_ptr<Bonus>> bonusses; ///< the bonusses
    pair<shared_ptr<BG_Tile>, shared_ptr<BG_Tile>> background; ///< the backgrounds
    shared_ptr<Camera> camera; ///< the camera

    bool GameOver; ///< game-over check
    int constant; ///< constant that is used to change de difficulty (less platforms and different types of platforms)


    pair<float,float> exeption_width; ///< Width where no other platforms can occur
    int exeption_height; ///< height for which the exception applies
    int last_max_of_radius; ///< last max of radius the radius a platform could spawn in
    int height_of_the_last_platform; ///< height of the last platform that was created
    int platforms_per_view; ///< the amount of platforms in a view
    int WIDTH; ///< width of the world
    int HEIGHT; ///< height of the world
};


#endif//AP_DOODLE_GAME_WORLD_H
