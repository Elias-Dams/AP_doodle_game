
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

shared_ptr<EM_Green_Platform> Concrete_Factory::createGreenPlatform(float platform_width, float platform_height){

    shared_ptr<EM_Green_Platform> platform = make_shared<EM_Green_Platform>(platform_width, platform_height);
    shared_ptr<EV_Green_Platform> platformView = make_shared<EV_Green_Platform>(*platform, platform_width, platform_height);

    Platformviews[platform] = platformView;

    // attach an observer to the platform
    platform->Attach(platformView);

    return platform;
}

shared_ptr<EM_Blue_Platform> Concrete_Factory::createBluePlatform(float platform_width, float platform_height){

    shared_ptr<EM_Blue_Platform> platform = make_shared<EM_Blue_Platform>(platform_width, platform_height);
    shared_ptr<EV_Blue_Platform> platformView = make_shared<EV_Blue_Platform>(*platform, platform_width, platform_height);

    Platformviews[platform] = platformView;

    // attach an observer to the platform
    platform->Attach(platformView);

    return platform;
}

shared_ptr<EM_Yellow_Platform> Concrete_Factory::createYellowPlatform(float platform_width, float platform_height, float move_height){

    shared_ptr<EM_Yellow_Platform> platform = make_shared<EM_Yellow_Platform>(platform_width, platform_height, move_height);
    shared_ptr<EV_Yellow_Platform> platformView = make_shared<EV_Yellow_Platform>(*platform, platform_width, platform_height);

    Platformviews[platform] = platformView;

    // attach an observer to the platform
    platform->Attach(platformView);

    return platform;
}

shared_ptr<EM_White_Platform> Concrete_Factory::createWhitePlatform(float platform_width, float platform_height){

    shared_ptr<EM_White_Platform> platform = make_shared<EM_White_Platform>(platform_width, platform_height);
    shared_ptr<EV_White_Platform> platformView = make_shared<EV_White_Platform>(*platform, platform_width, platform_height);

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

Concrete_Factory::~Concrete_Factory() {
    /*
    for (std::map<shared_ptr<EM_Player>, weak_ptr<EV_Player>>::iterator it = Playerviews.begin(); it != Playerviews.end(); it++){
        it->second.reset();
    }
    for (std::map<shared_ptr<EM_Platform>, weak_ptr<EV_Platform>>::iterator it = Platformviews.begin(); it != Platformviews.end(); it++){
        it->second.reset();
    }
    Playerviews.clear();
    Platformviews.clear();
     */
}
