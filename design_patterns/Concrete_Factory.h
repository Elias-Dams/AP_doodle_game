
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

public:
    Concrete_Factory();

    shared_ptr<EM_Player> createPlayer(float player_width, float player_height) override;
    shared_ptr<EM_Green_Platform> createGreenPlatform(float platform_width, float platform_height) override;
    shared_ptr<EM_Blue_Platform> createBluePlatform(float platform_width, float platform_height) override;
    shared_ptr<EM_White_Platform> createWhitePlatform(float platform_width, float platform_height) override;
    shared_ptr<EM_Yellow_Platform> createYellowPlatform(float platform_width, float platform_height, float move_height) override;

    shared_ptr<EV_Player> get_player(const shared_ptr<EM_Player> player) override;
    shared_ptr<EV_Platform> get_platform(const shared_ptr<EM_Platform> platform) override;

    virtual ~Concrete_Factory();
};


#endif //AP_DOODLE_GAME_CONCRETE_FACTORY_H
