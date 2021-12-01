
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


class Abstract_Factory {

public:
    Abstract_Factory();

    shared_ptr<EM_Player> createPlayer(float player_widht, float player_height);
    shared_ptr<EM_Platform> createPlatform(float platform_widht, float platform_height);
};


#endif //AP_DOODLE_GAME_ABSTRACT_FACTORY_H
