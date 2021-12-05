
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
    shared_ptr<EM_Platform> createPlatform(float platform_width, float platform_height) override;

    shared_ptr<EV_Player> get_player(const shared_ptr<EM_Player> player) override;
    shared_ptr<EV_Platform> get_platform(const shared_ptr<EM_Platform> platform) override;
};


#endif //AP_DOODLE_GAME_CONCRETE_FACTORY_H
