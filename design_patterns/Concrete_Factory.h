
#ifndef AP_DOODLE_GAME_CONCRETE_FACTORY_H
#define AP_DOODLE_GAME_CONCRETE_FACTORY_H

#include <iostream>
#include <list>
#include <string>
#include <memory>
#include <map>
#include "Abstract_Factory.h"



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
    shared_ptr<EV_Player> get_player(const shared_ptr<EM_Player> player) override;
    shared_ptr<EV_Platform> get_platform(const shared_ptr<EM_Platform> platform) override;
    shared_ptr<EV_Bonus> get_bonus(const shared_ptr<EM_Bonus> bonus) override;
    shared_ptr<Score> get_score() override;
    const vector<shared_ptr<EV_BG_Tile>> &getBackgrounds() const override;


    virtual ~Concrete_Factory();


};


#endif //AP_DOODLE_GAME_CONCRETE_FACTORY_H
