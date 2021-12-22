
#ifndef AP_DOODLE_GAME_CONCRETE_FACTORY_H
#define AP_DOODLE_GAME_CONCRETE_FACTORY_H

#include <iostream>
#include <list>
#include <string>
#include <memory>
#include <map>
#include "../../logic/design_patterns/Abstract_Factory.h"
#include "../Entity_View/EV_Player.h"
#include "../Entity_View/EV_Platform_Types/EV_Green_Platform.h"
#include "../Entity_View/EV_Platform_Types/EV_Blue_Platform.h"
#include "../Entity_View/EV_Platform_Types/EV_Yellow_Platform.h"
#include "../Entity_View/EV_Platform_Types/EV_White_Platform.h"
#include "../Entity_View/EV_Bonus_Types/EV_Spring.h"
#include "../Entity_View/EV_Bonus_Types/EV_Jetpack.h"
#include "../Entity_View/EV_Player.h"
#include "../Entity_View/EV_Bonus.h"
#include "../Entity_View/EV_BG_Tile.h"


class Concrete_Factory : public Abstract_Factory{
private:
    map<shared_ptr<Model::EM_Player>, weak_ptr<View::EV_Player>> Playerviews;
    map<shared_ptr<Model::EM_Platform>, weak_ptr<View::EV_Platform>> Platformviews;
    map<shared_ptr<Model::EM_Bonus>, weak_ptr<View::EV_Bonus>> Bonusviews;
    vector<weak_ptr<View::EV_BG_Tile>> backgrounds;
    shared_ptr<Score> score;

public:
    Concrete_Factory();
    /// create player
    shared_ptr<Model::EM_Player> createPlayer(float player_width, float player_height, float startposx, float startposy,shared_ptr<Camera> camera) override;

    /// create platforms
    shared_ptr<Model::EM_Green_Platform> createGreenPlatform(float platform_width, float platform_height,shared_ptr<Camera> camera) override;
    shared_ptr<Model::EM_Blue_Platform> createBluePlatform(float platform_width, float platform_height,shared_ptr<Camera> camera) override;
    shared_ptr<Model::EM_White_Platform> createWhitePlatform(float platform_width, float platform_height ,shared_ptr<Camera> camera) override;
    shared_ptr<Model::EM_Yellow_Platform> createYellowPlatform(float platform_width, float platform_height, float move_height, shared_ptr<Camera> camera) override;

    ///  create bonuses
    shared_ptr<Model::EM_Spring> createSpring(float spring_width, float spring_height,shared_ptr<Camera> camera) override;
    shared_ptr<Model::EM_Jetpack> createJetpack(float jetpack_width, float jetpack_height,shared_ptr<Camera> camera) override;

    /// create background
    shared_ptr<Model::EM_BG_Tile> createBackground(float background_width, float background_height, float startposx, float startposy,shared_ptr<Camera> camera) override;

    /// Model view getters
    weak_ptr<View::EV_Player> get_player(const shared_ptr<Model::EM_Player> player);
    weak_ptr<View::EV_Platform> get_platform(const shared_ptr<Model::EM_Platform> platform);
    weak_ptr<View::EV_Bonus> get_bonus(const shared_ptr<Model::EM_Bonus> bonus);
    weak_ptr<Score> get_score();
    const vector<weak_ptr<View::EV_BG_Tile>> &getBackgrounds() const;

    /// deleters
    void delete_platform(weak_ptr<Model::EM_Platform> platform) override;
    void delete_player(weak_ptr<Model::EM_Player> player) override;
    void delete_bonus(weak_ptr<Model::EM_Bonus> bonus) override;


    virtual ~Concrete_Factory();


};


#endif //AP_DOODLE_GAME_CONCRETE_FACTORY_H
