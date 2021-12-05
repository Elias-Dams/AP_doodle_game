
#ifndef AP_DOODLE_GAME_ABSTRACT_FACTORY_H
#define AP_DOODLE_GAME_ABSTRACT_FACTORY_H

#include <iostream>
#include <list>
#include <string>
#include <memory>
#include "../Entity_Model/EM_Player.h"
#include "../Entity_Model/EM_Platform.h"
#include "../Entity_Model/EM_BG_Tile.h"
#include "../Entity_Model/EM_Bonus.h"
#include "../Entity_View/EV_Player.h"
#include "../Entity_View/EV_Platform.h"
#include "../Entity_View/EV_Bonus.h"
#include "../Entity_View/EV_BG_Tile.h"


class Abstract_Factory {

public:

    virtual shared_ptr<EM_Player> createPlayer(float player_width, float player_height) = 0;
    virtual shared_ptr<EM_Platform> createPlatform(float platform_width, float platform_height) = 0;

    virtual shared_ptr<EV_Player> get_player(const shared_ptr<EM_Player> player) = 0;
    virtual shared_ptr<EV_Platform> get_platform(const shared_ptr<EM_Platform> platform) = 0;
};


#endif //AP_DOODLE_GAME_ABSTRACT_FACTORY_H
