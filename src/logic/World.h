
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
     * constructs the World whit a pointer to the Abstract factory
     */
    World(const shared_ptr<Abstract_Factory> &factory);

    /**
    * @brief handles the start state and gameover state of the game.
    *
    * This function handles the start state gameover state of the game.
    * It makes a platform and lets the player jump in place.
    * The player can't move in this state so there is no need for a key variable.
    *
    * @param dt: delta time (time it takes to render a frame).
    */
    void startstate(float dt);

    /**
    * @brief updates the world in teh actual game state.
    *
    * This function updates the world in teh actual game state.
    * - updates the camera position
    * - updates the background
    * - move the player (whit given key)
    * - check collision
    * - destroys and adds platforms
    *
    * @param dt: delta time (time it takes to render a frame).
    * @param key: key that is pressed.
    */
    void update(float dt, const char &key);

    /**
    * @brief returns the player.
    *
    * This function returns shared pointer of the player.
    *
    * @return shared pointer of the player.
    */
    shared_ptr<Player> getPlayer() const;

    /**
    * @brief returns the game width.
    *
    * This function returns the game width.
    *
    * @return the game width.
    */
    int getWidth() const;

    /**
    * @brief returns the game height.
    *
    * This function returns the game height.
    *
    * @return the game height.
    */
    int getHeight() const;

    /**
    * @brief returns the background.
    *
    * This function returns the background.
    * It is a pair of 2 tiles that updates when the player moves up in the world.
    *
    * @return pair of background Tiles.
    */
    const pair<shared_ptr<BG_Tile>, shared_ptr<BG_Tile>> &getBackground() const;

    /**
    * @brief returns the camera.
    *
    * This function returns shared pointer of the camera.
    *
    * @return shared pointer of the camera.
    */
    shared_ptr<Camera> getCamera() const;

    /**
    * @brief returns the platforms.
    *
    * This function returns a vector of shared pointers of platforms.
    *
    * @return a vector of shared pointers of platforms.
    */
    const vector<shared_ptr<Platform>> &getPlatforms() const;

    /**
    * @brief returns the bonusses.
    *
    * This function returns a map whit
    * - key a shared pointer to a platform
    * - van a shared pointer to a bonus
    *
    * @return a map of bonuses.
    */
    const map<shared_ptr<Platform>, shared_ptr<Bonus>> &getBonuses() const;

    /**
    * @brief resets the world.
    *
    * This function resets the world to the state it was in when it was first initialized.
    * it handles:
    * - reset of the player
    * - reset of the camera
    * - reset of all the members of the wordl
    * - clears the vector of platforms
    * - clears the map of bonuses
    *
    */
    void Reset();

    /**
    * @brief checks if the game is over.
    *
    * This function checks if the game is over.
    *
    * @return True if the game is over. False if the game is not over.
    */
    bool isGameOver() const;

    virtual ~World();


private:
    void create_start_platform();

    void create_platforms();

    void add_platforms();

    bool colisionCheck(shared_ptr<Entity_Model> entity, bool can_update_score);

    shared_ptr<Abstract_Factory> factory; ///< abstract factory

    shared_ptr<Player> player; ///< the player
    vector<shared_ptr<Platform>> platforms; ///< the platforms
    map<shared_ptr<Platform>, shared_ptr<Bonus>> bonusses; ///< the bonusses
    pair<shared_ptr<BG_Tile>, shared_ptr<BG_Tile>> background; ///< the backgrounds
    shared_ptr<Camera> camera; ///< the camera

    bool GameOver; ///< game over check
    int constant; ///< constant that is used to change de difficulty (less platforms and differant types of platforms)

    int last_max_of_radius; ///< last max of radius the radius a platform could spawn in
    int height_of_the_last_platform; ///< height of the last platform that was created
    int platforms_per_view; ///< the amount of platforms in a view
    int WIDTH; ///< width of the wordl
    int HEIGHT; ///< height of the wordl
};


#endif//AP_DOODLE_GAME_WORLD_H
