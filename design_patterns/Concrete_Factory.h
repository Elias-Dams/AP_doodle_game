
#ifndef AP_DOODLE_GAME_CONCRETE_FACTORY_H
#define AP_DOODLE_GAME_CONCRETE_FACTORY_H

#include <iostream>
#include <list>
#include <string>
#include <memory>
#include "Abstract_Factory.h"
#include "../Entity_View/EV_Player.h"
#include "../Entity_View/EV_Platform.h"


class Concrete_Factory : public Abstract_Factory{
public:
    Concrete_Factory();

    shared_ptr<EV_Player>createPlayerView(shared_ptr<EM_Player> subject, float player_width, float player_height);

    shared_ptr<EV_Platform> createPlatformView(shared_ptr<EM_Platform> subject, float platform_width, float platform_height);
};


#endif //AP_DOODLE_GAME_CONCRETE_FACTORY_H
