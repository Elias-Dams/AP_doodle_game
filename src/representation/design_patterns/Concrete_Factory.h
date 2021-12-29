
#ifndef AP_DOODLE_GAME_CONCRETE_FACTORY_H
#define AP_DOODLE_GAME_CONCRETE_FACTORY_H

#include "../../logic/design_patterns/Abstract_Factory.h"
#include "../Entity_View/V_Bonus_Types/V_Jetpack.h"
#include "../Entity_View/V_Bonus_Types/V_Spring.h"
#include "../Entity_View/V_Platform_Types/V_Blue_Platform.h"
#include "../Entity_View/V_Platform_Types/V_Green_Platform.h"
#include "../Entity_View/V_Platform_Types/V_White_Platform.h"
#include "../Entity_View/V_Platform_Types/V_Yellow_Platform.h"
#include "../Entity_View/V_BG_Tile.h"
#include "../Entity_View/V_Bonus.h"
#include "../Entity_View/V_Player.h"
#include <iostream>
#include <list>
#include <map>
#include <memory>
#include <string>

/**
 * @class Abstract_Factory
 *
 * @brief Creates the views used in the Game.
 */
class Concrete_Factory : public Abstract_Factory {

public:
    /**
     * Concrete_Factory constructor.
     * constructs the Concrete_Factory
     */
    Concrete_Factory();
    // create player
    shared_ptr<Model::Player> createPlayer(float player_width, float player_height, float startposx, float startposy, shared_ptr<Camera> camera) override;

    // create platforms
    shared_ptr<Model::Green_Platform> createGreenPlatform(float platform_width, float platform_height, shared_ptr<Camera> camera) override;
    shared_ptr<Model::Blue_Platform> createBluePlatform(float platform_width, float platform_height, float move_width, shared_ptr<Camera> camera) override;
    shared_ptr<Model::White_Platform> createWhitePlatform(float platform_width, float platform_height, shared_ptr<Camera> camera) override;
    shared_ptr<Model::Yellow_Platform> createYellowPlatform(float platform_width, float platform_height, float move_height, shared_ptr<Camera> camera) override;

    //  create bonuses
    shared_ptr<Model::Spring> createSpring(float spring_width, float spring_height, shared_ptr<Camera> camera) override;
    shared_ptr<Model::Jetpack> createJetpack(float jetpack_width, float jetpack_height, shared_ptr<Camera> camera) override;

    // create background
    shared_ptr<Model::BG_Tile> createBackground(float background_width, float background_height, float startposx, float startposy, shared_ptr<Camera> camera) override;

    shared_ptr<Camera> createCamera(float camera_width, float camera_height) override;

    // Model view getters

    /**
    * @brief returns the view of the player
    *
    * This function returns the view of the player
    *
    * @return the view of the player
    */
    weak_ptr<View::Player> get_player();

    /**
    * @brief returns the view of the platform
    *
    * This function returns the view of the platform
    *
    * @param player the platform whose view we want to get
    * @return the view of the platform
    */
    weak_ptr<View::Platform> get_platform(const shared_ptr<Model::Platform> &platform);

    /**
    * @brief returns the view of the bonus
    *
    * This function returns the view of the bonus
    *
    * @param player the bonus whose view we want to get
    * @return the view of the bonus
    */
    weak_ptr<View::Bonus> get_bonus(const shared_ptr<Model::Bonus> &bonus);

    /**
    * @brief returns the score
    *
    * This function returns the score
    *
    * @return the score
    */
    weak_ptr<Score> get_score();

    /**
    * @brief returns the vector of background tiles
    *
    * This function returns the vector of background tiles
    *
    * @return the vector of background tiles
    */
    const vector<weak_ptr<View::BG_Tile>> &getBackgrounds() const;

    // deleters
    void delete_platform(weak_ptr<Model::Platform> platform) override;
    void delete_bonus(weak_ptr<Model::Bonus> bonus) override;


    virtual ~Concrete_Factory();

private:
    weak_ptr<View::Player> Playerview; ///< Player view
    map<shared_ptr<Model::Platform>, weak_ptr<View::Platform>> Platformviews; ///< Platform views
    map<shared_ptr<Model::Bonus>, weak_ptr<View::Bonus>> Bonusviews; ///< Bonus views
    vector<weak_ptr<View::BG_Tile>> backgrounds; ///< Background views
    weak_ptr<Score> score; ///< score

};


#endif//AP_DOODLE_GAME_CONCRETE_FACTORY_H
