
#include "Abstract_Factory.h"

Abstract_Factory::Abstract_Factory() {}

shared_ptr<EM_Player> Abstract_Factory::createPlayer(float player_widht, float player_height){
    shared_ptr<EM_Player> player(new EM_Player(player_widht, player_height));
    return player;
}


shared_ptr<EM_Platform> Abstract_Factory::createPlatform(float platform_widht, float platform_height){
    shared_ptr<EM_Platform> platform(new EM_Platform(platform_widht, platform_height));
    return platform;
}