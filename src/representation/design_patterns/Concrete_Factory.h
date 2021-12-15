
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
    map<shared_ptr<EM_Player>, weak_ptr<EV_Player>> Playerviews;
    map<shared_ptr<EM_Platform>, weak_ptr<EV_Platform>> Platformviews;
    map<shared_ptr<EM_Bonus>, weak_ptr<EV_Bonus>> Bonusviews;
    vector<shared_ptr<EV_BG_Tile>> backgrounds;
    shared_ptr<Score> score;

public:
    Concrete_Factory();
    /// create player
    shared_ptr<EM_Player> createPlayer(float player_width, float player_height, float startposx, float startposy,shared_ptr<Camera> camera) override;

    /// create platforms
    shared_ptr<EM_Green_Platform> createGreenPlatform(float platform_width, float platform_height,shared_ptr<Camera> camera) override;
    shared_ptr<EM_Blue_Platform> createBluePlatform(float platform_width, float platform_height,shared_ptr<Camera> camera) override;
    shared_ptr<EM_White_Platform> createWhitePlatform(float platform_width, float platform_height ,shared_ptr<Camera> camera) override;
    shared_ptr<EM_Yellow_Platform> createYellowPlatform(float platform_width, float platform_height, float move_height, shared_ptr<Camera> camera) override;

    ///  create bonuses
    shared_ptr<EM_Spring> createSpring(float spring_width, float spring_height,shared_ptr<Camera> camera) override;

    /// create background
    shared_ptr<EM_BG_Tile> createBackground(float background_width, float background_height, float startposx, float startposy,shared_ptr<Camera> camera) override;

    /// Entity view getters
    shared_ptr<EV_Player> get_player(const shared_ptr<EM_Player> player);
    shared_ptr<EV_Platform> get_platform(const shared_ptr<EM_Platform> platform);
    shared_ptr<EV_Bonus> get_bonus(const shared_ptr<EM_Bonus> bonus);
    shared_ptr<Score> get_score();
    const vector<shared_ptr<EV_BG_Tile>> &getBackgrounds() const;


    virtual ~Concrete_Factory();


};


#endif //AP_DOODLE_GAME_CONCRETE_FACTORY_H
