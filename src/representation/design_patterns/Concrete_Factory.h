
#ifndef AP_DOODLE_GAME_CONCRETE_FACTORY_H
#define AP_DOODLE_GAME_CONCRETE_FACTORY_H

#include <iostream>
#include <list>
#include <string>
#include <memory>
#include <map>
#include "../../logic/design_patterns/Abstract_Factory.h"
#include "../Entity_View/Player.h"
#include "../Entity_View/EV_Platform_Types/Green_Platform.h"
#include "../Entity_View/EV_Platform_Types/Blue_Platform.h"
#include "../Entity_View/EV_Platform_Types/Yellow_Platform.h"
#include "../Entity_View/EV_Platform_Types/White_Platform.h"
#include "../Entity_View/EV_Bonus_Types/Spring.h"
#include "../Entity_View/EV_Bonus_Types/Jetpack.h"
#include "../Entity_View/Player.h"
#include "../Entity_View/Bonus.h"
#include "../Entity_View/BG_Tile.h"


class Concrete_Factory : public Abstract_Factory{
private:
    map<shared_ptr<Model::Player>, weak_ptr<View::Player>> Playerviews;
    map<shared_ptr<Model::Platform>, weak_ptr<View::Platform>> Platformviews;
    map<shared_ptr<Model::Bonus>, weak_ptr<View::Bonus>> Bonusviews;
    vector<weak_ptr<View::BG_Tile>> backgrounds;
    shared_ptr<Score> score;

public:
    Concrete_Factory();
    /// create player
    shared_ptr<Model::Player> createPlayer(float player_width, float player_height, float startposx, float startposy,shared_ptr<Camera> camera) override;

    /// create platforms
    shared_ptr<Model::Green_Platform> createGreenPlatform(float platform_width, float platform_height,shared_ptr<Camera> camera) override;
    shared_ptr<Model::Blue_Platform> createBluePlatform(float platform_width, float platform_height,shared_ptr<Camera> camera) override;
    shared_ptr<Model::White_Platform> createWhitePlatform(float platform_width, float platform_height ,shared_ptr<Camera> camera) override;
    shared_ptr<Model::Yellow_Platform> createYellowPlatform(float platform_width, float platform_height, float move_height, shared_ptr<Camera> camera) override;

    ///  create bonuses
    shared_ptr<Model::Spring> createSpring(float spring_width, float spring_height,shared_ptr<Camera> camera) override;
    shared_ptr<Model::Jetpack> createJetpack(float jetpack_width, float jetpack_height,shared_ptr<Camera> camera) override;

    /// create background
    shared_ptr<Model::BG_Tile> createBackground(float background_width, float background_height, float startposx, float startposy,shared_ptr<Camera> camera) override;

    /// Model view getters
    weak_ptr<View::Player> get_player(const shared_ptr<Model::Player>& player);
    weak_ptr<View::Platform> get_platform(const shared_ptr<Model::Platform>& platform);
    weak_ptr<View::Bonus> get_bonus(const shared_ptr<Model::Bonus>& bonus);
    weak_ptr<Score> get_score();
    const vector<weak_ptr<View::BG_Tile>> &getBackgrounds() const;

    /// deleters
    void delete_platform(weak_ptr<Model::Platform> platform) override;
    void delete_player(weak_ptr<Model::Player> player) override;
    void delete_bonus(weak_ptr<Model::Bonus> bonus) override;


    virtual ~Concrete_Factory();


};


#endif //AP_DOODLE_GAME_CONCRETE_FACTORY_H
