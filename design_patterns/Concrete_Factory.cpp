
#include "Concrete_Factory.h"

Concrete_Factory::Concrete_Factory() {}

shared_ptr<EM_Player> Concrete_Factory::createPlayer(float player_width, float player_height){
    shared_ptr<EM_Player> player = make_shared<EM_Player>(player_width, player_height);
    shared_ptr<EV_Player> playerView = make_shared<EV_Player>(*player, player_width, player_height);

    Playerviews[player] = playerView;

    // attach an observer to the player
    player->Attach(playerView);

    return player;
}

shared_ptr<EM_Platform> Concrete_Factory::createPlatform(float platform_width, float platform_height){

    shared_ptr<EM_Platform> platform = make_shared<EM_Platform>(platform_width, platform_height);
    shared_ptr<EV_Platform> platformView = make_shared<EV_Platform>(*platform, platform_width, platform_height);

    Platformviews[platform] = platformView;

    // attach an observer to the platform
    platform->Attach(platformView);

    return platform;
}

shared_ptr<EV_Player> Concrete_Factory::get_player(const shared_ptr<EM_Player> player) {

    return Playerviews[player].lock();
}

shared_ptr<EV_Platform> Concrete_Factory::get_platform(const shared_ptr<EM_Platform> platform){

    return Platformviews[platform].lock();
}

