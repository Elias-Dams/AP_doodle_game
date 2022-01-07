
#ifndef AP_DOODLE_GAME_ABSTRACT_FACTORY_H
#define AP_DOODLE_GAME_ABSTRACT_FACTORY_H

#include "../Camera.h"
#include "../Entity_Model/M_Bonus_Types/M_Jetpack.h"
#include "../Entity_Model/M_Bonus_Types/M_Spring.h"
#include "../Entity_Model/M_Platform_Types/M_Blue_Platform.h"
#include "../Entity_Model/M_Platform_Types/M_Green_Platform.h"
#include "../Entity_Model/M_Platform_Types/M_White_Platform.h"
#include "../Entity_Model/M_Platform_Types/M_Yellow_Platform.h"
#include "../Entity_Model/M_BG_Tile.h"
#include "../Entity_Model/M_Bonus.h"
#include "../Entity_Model/M_Player.h"
#include "../Score.h"
#include <iostream>
#include <list>
#include <memory>
#include <string>

/**
 * @class Abstract_Factory
 *
 * @brief Creates the entity's used in the World.
 */
class Abstract_Factory {

public:
    /**
     * Player constructor.
     * Constructs the Player with a certain
     * - width
     * - height
     * - startposition
     * - camera
     */
    virtual shared_ptr<Model::Player> createPlayer(float player_width, float player_height, float startposx, float startposy, shared_ptr<Camera> camera) = 0;

    /**
     * Background_Tile constructor.
     * Constructs a Background_Tile with a certain
     * - width
     * - height
     * - startposition
     * - camera
     */
    virtual shared_ptr<Model::BG_Tile> createBackground(float background_width, float background_height, float startposx, float startposy, shared_ptr<Camera> camera) = 0;

    /**
     * Green_Platform constructor.
     * Constructs a Green_Platform with a certain
     * - width
     * - height
     * - camera
     */
    virtual shared_ptr<Model::Green_Platform> createGreenPlatform(float platform_width, float platform_height, shared_ptr<Camera> camera) = 0;

    /**
     * Blue_Platform constructor.
     * Constructs a Blue_Platform with a certain
     * - width
     * - height
     * - move width
     * - camera
     */
    virtual shared_ptr<Model::Blue_Platform> createBluePlatform(float platform_width, float platform_height, float move_width, shared_ptr<Camera> camera) = 0;

    /**
     * White_Platform constructor.
     * Constructs a White_Platform with a certain
     * - width
     * - height
     * - camera
     */
    virtual shared_ptr<Model::White_Platform> createWhitePlatform(float platform_width, float platform_height, shared_ptr<Camera> camera) = 0;

    /**
     * Yellow_Platform constructor.
     * Constructs a Yellow_Platform with a certain
     * - width
     * - height
     * - move height
     * - camera
     */
    virtual shared_ptr<Model::Yellow_Platform> createYellowPlatform(float platform_width, float platform_height, float move_height, shared_ptr<Camera> camera) = 0;

    /**
     * Spring constructor.
     * Constructs the Spring with a certain
     * - width
     * - height
     * - camera
     */
    virtual shared_ptr<Model::Spring> createSpring(float spring_width, float spring_height, shared_ptr<Camera> camera) = 0;

    /**
     * Jetpack constructor.
     * Constructs the Jetpack with a certain
     * - width
     * - height
     * - camera
     */
    virtual shared_ptr<Model::Jetpack> createJetpack(float jetpack_width, float jetpack_height, shared_ptr<Camera> camera) = 0;

    /**
     * Camera constructor.
     * Constructs the Camera.
     */
    virtual shared_ptr<Camera> createCamera(float camera_width, float camera_height) = 0;

    /**
     * @brief Deletes a platform
     *
     * This function deletes a platform from the map of platforms.
     * In this map the view is being saved.
     *
     * @param platform: weak pointer to the platform that must be deleted
     */
    virtual void delete_platform(weak_ptr<Model::Platform> platform) = 0;

    /**
     * @brief Deletes a bonus
     *
     * This function deletes a bonus from the map of bonuses.
     * In this map the view is being saved.
     *
     * @param platform: weak pointer to the bonus that must be deleted
     */
    virtual void delete_bonus(weak_ptr<Model::Bonus> bonus) = 0;
};


#endif//AP_DOODLE_GAME_ABSTRACT_FACTORY_H
