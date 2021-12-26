
#include "Concrete_Factory.h"

Concrete_Factory::Concrete_Factory() {}

shared_ptr<Model::Player> Concrete_Factory::createPlayer(float player_width, float player_height, float startposx, float startposy, shared_ptr<Camera> camera) {
    shared_ptr<Model::Player> player = make_shared<Model::Player>(player_width, player_height);
    shared_ptr<View::Player> playerView = make_shared<View::Player>(*player, player_width, player_height, camera);
    score = make_shared<Score>(*player);

    Playerviews[player] = playerView;

    // attach an observer to the player
    player->Attach(playerView);
    player->Attach(score);

    // set the playerposition (after it has an observer)
    player->setPosition(startposx, startposy);

    return player;
}

shared_ptr<Model::Green_Platform> Concrete_Factory::createGreenPlatform(float platform_width, float platform_height, shared_ptr<Camera> camera) {

    shared_ptr<Model::Green_Platform> platform = make_shared<Model::Green_Platform>(platform_width, platform_height);
    shared_ptr<View::Green_Platform> platformView = make_shared<View::Green_Platform>(*platform, platform_width, platform_height, camera);

    Platformviews[platform] = platformView;

    // attach an observer to the platform
    platform->Attach(platformView);

    return platform;
}

shared_ptr<Model::Blue_Platform> Concrete_Factory::createBluePlatform(float platform_width, float platform_height, float move_width, shared_ptr<Camera> camera) {

    shared_ptr<Model::Blue_Platform> platform = make_shared<Model::Blue_Platform>(platform_width, platform_height, move_width);
    shared_ptr<View::Blue_Platform> platformView = make_shared<View::Blue_Platform>(*platform, platform_width, platform_height, camera);

    Platformviews[platform] = platformView;

    // attach an observer to the platform
    platform->Attach(platformView);

    return platform;
}

shared_ptr<Model::Yellow_Platform> Concrete_Factory::createYellowPlatform(float platform_width, float platform_height, float move_height, shared_ptr<Camera> camera) {

    shared_ptr<Model::Yellow_Platform> platform = make_shared<Model::Yellow_Platform>(platform_width, platform_height, move_height);
    shared_ptr<View::Yellow_Platform> platformView = make_shared<View::Yellow_Platform>(*platform, platform_width, platform_height, camera);

    Platformviews[platform] = platformView;

    // attach an observer to the platform
    platform->Attach(platformView);

    return platform;
}

shared_ptr<Model::White_Platform> Concrete_Factory::createWhitePlatform(float platform_width, float platform_height, shared_ptr<Camera> camera) {

    shared_ptr<Model::White_Platform> platform = make_shared<Model::White_Platform>(platform_width, platform_height);
    shared_ptr<View::White_Platform> platformView = make_shared<View::White_Platform>(*platform, platform_width, platform_height, camera);

    Platformviews[platform] = platformView;

    // attach an observer to the platform
    platform->Attach(platformView);

    return platform;
}

shared_ptr<Model::Spring> Concrete_Factory::createSpring(float spring_width, float spring_height, shared_ptr<Camera> camera) {
    shared_ptr<Model::Spring> spring = make_shared<Model::Spring>(spring_width, spring_height);
    shared_ptr<View::Spring> springView = make_shared<View::Spring>(*spring, spring_width, spring_height, camera);

    Bonusviews[spring] = springView;

    spring->Attach(springView);

    return spring;
}

shared_ptr<Model::Jetpack> Concrete_Factory::createJetpack(float jetpack_width, float jetpack_height, shared_ptr<Camera> camera) {
    shared_ptr<Model::Jetpack> jetpack = make_shared<Model::Jetpack>(jetpack_width, jetpack_height);
    shared_ptr<View::Jetpack> jetpackView = make_shared<View::Jetpack>(*jetpack, jetpack_width, jetpack_height, camera);

    Bonusviews[jetpack] = jetpackView;

    jetpack->Attach(jetpackView);

    return jetpack;
}


shared_ptr<Model::BG_Tile> Concrete_Factory::createBackground(float background_width, float background_height, float startposx, float startposy, shared_ptr<Camera> camera) {
    shared_ptr<Model::BG_Tile> background = make_shared<Model::BG_Tile>(background_width, background_height);
    shared_ptr<View::BG_Tile> backgroundView = make_shared<View::BG_Tile>(*background, background_width, background_height, camera);

    backgrounds.push_back(backgroundView);

    background->Attach(backgroundView);

    // set the backgroundposition (after it has an observer)
    background->setPosition(startposx, startposy);

    return background;
}

weak_ptr<View::Player> Concrete_Factory::get_player(const shared_ptr<Model::Player> &player) {

    return Playerviews[player];
}

weak_ptr<View::Platform> Concrete_Factory::get_platform(const shared_ptr<Model::Platform> &platform) {

    return Platformviews[platform];
}

weak_ptr<View::Bonus> Concrete_Factory::get_bonus(const shared_ptr<Model::Bonus> &bonus) {

    return Bonusviews[bonus];
}

weak_ptr<Score> Concrete_Factory::get_score() {

    return score;
}

const vector<weak_ptr<View::BG_Tile>> &Concrete_Factory::getBackgrounds() const {
    return backgrounds;
}

void Concrete_Factory::delete_platform(weak_ptr<Model::Platform> platform) {
    Platformviews[platform.lock()].reset();
    Platformviews.erase(platform.lock());
}

void Concrete_Factory::delete_player(weak_ptr<Model::Player> player) {
    Playerviews[player.lock()].reset();
    Playerviews.erase(player.lock());
}

void Concrete_Factory::delete_bonus(weak_ptr<Model::Bonus> bonus) {
    Bonusviews[bonus.lock()].reset();
    Bonusviews.erase(bonus.lock());
}

Concrete_Factory::~Concrete_Factory() {
    
    Playerviews.clear();
    Platformviews.clear();
    Bonusviews.clear();
    backgrounds.clear();
}
