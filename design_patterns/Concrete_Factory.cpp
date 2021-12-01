
#include "Concrete_Factory.h"

Concrete_Factory::Concrete_Factory() {}

shared_ptr<EV_Player> Concrete_Factory::createPlayerView(shared_ptr<EM_Player> subject, float player_width, float player_height){
    shared_ptr<EV_Player> playerView = make_shared<EV_Player>(*subject, player_width, player_height);
    subject->Attach(playerView);
    return playerView;
}

shared_ptr<EV_Platform> Concrete_Factory::createPlatformView(shared_ptr<EM_Platform> subject, float platform_width, float platform_height){
    shared_ptr<EV_Platform> platformView = make_shared<EV_Platform>(*subject, platform_width, platform_height);
    subject->Attach(platformView);
    return platformView;
}