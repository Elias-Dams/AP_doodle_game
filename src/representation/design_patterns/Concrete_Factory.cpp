
#include "Concrete_Factory.h"

Concrete_Factory::Concrete_Factory() {}

shared_ptr<EM_Player> Concrete_Factory::createPlayer(float player_width, float player_height, float startposx, float startposy, shared_ptr<Camera> camera){
    shared_ptr<EM_Player> player = make_shared<EM_Player>(player_width, player_height);
    shared_ptr<EV_Player> playerView = make_shared<EV_Player>(*player, player_width, player_height, camera);
    score = make_shared<Score>(*player);

    Playerviews[player] = playerView;

    // attach an observer to the player
    player->Attach(playerView);
    player->Attach(score);

    // set the playerposition (after it has an observer)
    player->setPosition( startposx, startposy);

    return player;
}

shared_ptr<EM_Green_Platform> Concrete_Factory::createGreenPlatform(float platform_width, float platform_height, shared_ptr<Camera> camera){

    shared_ptr<EM_Green_Platform> platform = make_shared<EM_Green_Platform>(platform_width, platform_height);
    shared_ptr<EV_Green_Platform> platformView = make_shared<EV_Green_Platform>(*platform, platform_width, platform_height,camera);

    Platformviews[platform] = platformView;

    // attach an observer to the platform
    platform->Attach(platformView);

    return platform;
}

shared_ptr<EM_Blue_Platform> Concrete_Factory::createBluePlatform(float platform_width, float platform_height, shared_ptr<Camera> camera){

    shared_ptr<EM_Blue_Platform> platform = make_shared<EM_Blue_Platform>(platform_width, platform_height);
    shared_ptr<EV_Blue_Platform> platformView = make_shared<EV_Blue_Platform>(*platform, platform_width, platform_height, camera);

    Platformviews[platform] = platformView;

    // attach an observer to the platform
    platform->Attach(platformView);

    return platform;
}

shared_ptr<EM_Yellow_Platform> Concrete_Factory::createYellowPlatform(float platform_width, float platform_height, float move_height, shared_ptr<Camera> camera){

    shared_ptr<EM_Yellow_Platform> platform = make_shared<EM_Yellow_Platform>(platform_width, platform_height, move_height);
    shared_ptr<EV_Yellow_Platform> platformView = make_shared<EV_Yellow_Platform>(*platform, platform_width, platform_height, camera);

    Platformviews[platform] = platformView;

    // attach an observer to the platform
    platform->Attach(platformView);

    return platform;
}

shared_ptr<EM_White_Platform> Concrete_Factory::createWhitePlatform(float platform_width, float platform_height, shared_ptr<Camera> camera){

    shared_ptr<EM_White_Platform> platform = make_shared<EM_White_Platform>(platform_width, platform_height);
    shared_ptr<EV_White_Platform> platformView = make_shared<EV_White_Platform>(*platform, platform_width, platform_height, camera);

    Platformviews[platform] = platformView;

    // attach an observer to the platform
    platform->Attach(platformView);

    return platform;
}

shared_ptr<EM_Spring> Concrete_Factory::createSpring(float spring_width, float spring_height,shared_ptr<Camera> camera) {
    shared_ptr<EM_Spring> spring = make_shared<EM_Spring>(spring_width, spring_height);
    shared_ptr<EV_Spring> springView = make_shared<EV_Spring>(*spring, spring_width, spring_height, camera);

    Bonusviews[spring] = springView;

    spring->Attach(springView);

    return spring;
}

shared_ptr<EM_Jetpack> Concrete_Factory::createJetpack(float jetpack_width, float jetpack_height,shared_ptr<Camera> camera){
    shared_ptr<EM_Jetpack> jetpack = make_shared<EM_Jetpack>(jetpack_width, jetpack_height);
    shared_ptr<EV_Jetpack> jetpackView = make_shared<EV_Jetpack>(*jetpack, jetpack_width, jetpack_height, camera);

    Bonusviews[jetpack] = jetpackView;

    jetpack->Attach(jetpackView);

    return jetpack;
}


shared_ptr<EM_BG_Tile>  Concrete_Factory::createBackground(float background_width, float background_height, float startposx, float startposy,shared_ptr<Camera> camera) {
    shared_ptr<EM_BG_Tile> background = make_shared<EM_BG_Tile>(background_width, background_height);
    shared_ptr<EV_BG_Tile> backgroundView = make_shared<EV_BG_Tile>(*background, background_width, background_height, camera);

    backgrounds.push_back(backgroundView);

    background->Attach(backgroundView);

    // set the backgroundposition (after it has an observer)
    background->setPosition(startposx, startposy);

    return background;
}

weak_ptr<EV_Player> Concrete_Factory::get_player(const shared_ptr<EM_Player> player) {

    return Playerviews[player];
}

weak_ptr<EV_Platform> Concrete_Factory::get_platform(const shared_ptr<EM_Platform> platform){

    return Platformviews[platform];
}

weak_ptr<EV_Bonus> Concrete_Factory::get_bonus(const shared_ptr<EM_Bonus> bonus){

    return Bonusviews[bonus];
}

weak_ptr<Score> Concrete_Factory::get_score(){

    return score;
}

const vector<weak_ptr<EV_BG_Tile>> &Concrete_Factory::getBackgrounds() const {
    return backgrounds;
}

void Concrete_Factory::delete_platform(weak_ptr<EM_Platform> platform){
    Platformviews[platform.lock()].reset();
    Platformviews.erase(platform.lock());

}

void Concrete_Factory::delete_player(weak_ptr<EM_Player> player) {
    Playerviews[player.lock()].reset();
    Playerviews.erase(player.lock());
}

void Concrete_Factory::delete_bonus(weak_ptr<EM_Bonus> bonus) {
    Bonusviews[bonus.lock()].reset();
    Bonusviews.erase(bonus.lock());
}

Concrete_Factory::~Concrete_Factory() {
    cout << "destructor of Concrete_Factory" << endl;

    cout << "\t clear Playerviews" << endl;
    Playerviews.clear();
    cout << "\t clear Platformviews" << endl;
    Platformviews.clear();
    cout << "\t clear Bonusviews" << endl;
    Bonusviews.clear();
    cout << "\t clear backgrounds" << endl;
    backgrounds.clear();

}

