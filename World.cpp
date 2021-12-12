
#include "World.h"

World::World(const shared_ptr<Abstract_Factory> &factory) : factory(factory) {
    WIDTH = 400;
    HEIGHT = 600;
    platforms_per_view = 10;
    height_of_last_platform = 0;
    camera = make_shared<Camera>(WIDTH, HEIGHT);
    player = factory->createPlayer(WIDTH/8.0f, HEIGHT/12.0f, 150.0f, 300.0f, camera);
    random = unique_ptr<Random>(Random::GetInstance());
    GameOver = false;

    this->create_platforms();
}

void World::create_platforms(){
    int radius_per_platform = HEIGHT / platforms_per_view;

    for(int i = 0; i < platforms_per_view; i++){

        int temp = height_of_last_platform;
        height_of_last_platform += radius_per_platform;
        shared_ptr<EM_Green_Platform> platform = factory->createGreenPlatform(WIDTH/5.5f, HEIGHT/32.0f, camera);
        platform->setPosition( random->generate_between(0,(float)WIDTH - platform->getPlatformWidth()), random->generate_between((float)temp+platform->getPlatformHeight(), (float)height_of_last_platform));
        platforms.push_back(platform);

    }

}

void World::add_platforms(){

    int platforms_ot_add = platforms_per_view - platforms.size();

    if(platforms_ot_add > 0){
        //cout << camera->getHeight() << "   " << height_of_last_platform << endl;

        int radius_per_platform = camera->getNomalisedHeight()+HEIGHT/2 - height_of_last_platform / platforms_ot_add;
        //cout << radius_per_platform << endl;
        for(int i = 0; i < platforms_ot_add; i++){

            int temp = height_of_last_platform;
            height_of_last_platform += radius_per_platform;


            shared_ptr<EM_Platform> platform;
            // randomly choose a type of platform
            float chance = random->generate_between(0.0f, 10.0f);
            if (chance >= 9.0f){
                platform = factory->createWhitePlatform(WIDTH/5.5f, HEIGHT/32.0f, camera);
            }
            else if (chance <= 0.50f){
                platform = factory->createBluePlatform(WIDTH/5.5f, HEIGHT/32.0f, camera);
            }
            else if (chance <= 6.0f and chance >= 5.50f ){
                platform = factory->createYellowPlatform(WIDTH/5.5f, HEIGHT/32.0f, 200.0f, camera);
            }
            else{
                platform = factory->createGreenPlatform(WIDTH/5.5f, HEIGHT/32.0f, camera);
            }

            platform->setPosition( random->generate_between(0,(float)WIDTH - platform->getPlatformWidth()), random->generate_between((float)temp+platform->getPlatformHeight(), (float)height_of_last_platform));
            height_of_last_platform = platform->getPosition().second;
            platforms.push_back(platform);

        }

    }
}

bool World::colisionCheck(shared_ptr<EM_Platform> platform){
    // the left side of the player
    if(platform->getPosition().first <= player->getPosition().first and player->getPosition().first <= platform->getPosition().first+platform->getPlatformWidth()){

        if(player->getPosition().second - (platform->getPosition().second + platform->getPlatformHeight()) <= 0 and player->getPosition().second - platform->getPosition().second >= 0 and player->isfalling()){

            return true;
        }
    }
        // right side of the player
    else if(platform->getPosition().first <= player->getPosition().first+player->getPlayerWidth() and player->getPosition().first+player->getPlayerWidth() <= platform->getPosition().first+platform->getPlatformWidth()){

        if(player->getPosition().second - (platform->getPosition().second + platform->getPlatformHeight()) <= 0 and player->getPosition().second - platform->getPosition().second >= 0 and player->isfalling()){

            return true;
        }
    }
    return false;
}

void World::update(float dt, const char &key){
    // game over;
    if(player->getPosition().second < (camera->getNomalisedHeight()-HEIGHT/2)){
        //cout << "game over" << endl;
        GameOver = true;
    }

    // update the camera pos
    if(player->getPosition().second >= camera->getNomalisedHeight()){
        camera->setHeight(player->getPosition().second);
    }

    if(key == 'Q'){
        player->move(-5.f * dt * 60.f, 0.f  * dt * 60.f);
    }
    if(key == 'D'){
        player->move(5.f * dt * 60.f, 0.f  * dt * 60.f);
    }

    // if player goes out of the screen to the left it wil go to the right.
    if (player->getPosition().first <= -player->getPlayerWidth()){
        player->setPosition(WIDTH - player->getPlayerWidth(), player->getPosition().second) ;
    }
    // if player goes out of the screen to the right it wil go to the left.
    if(player->getPosition().first >= WIDTH){
        player->setPosition(0, player->getPosition().second);
    }

    // check colision
    bool hit = false;

    /*
    for(auto platform : platforms){

        if(this->colisionCheck(platform)){
            hit = true;
            platform_hit = platform
        }

        platform->update(dt, WIDTH, HEIGHT);

    }*/

    auto it = platforms.begin();
    while (it != platforms.end()){
        bool current_hit = false;

        (*it)->update(dt, WIDTH);

        if(this->colisionCheck(*it)){
            hit = true;
            current_hit = true;
        }

        if ((*it)->getPosition().second < (camera->getNomalisedHeight()-HEIGHT/2)-(*it)->getPlatformHeight()){
            it = platforms.erase(it);
        }
        else if (current_hit && (*it)->getColor() == "White"){
            it = platforms.erase(it);
        }
        else {
            ++it;
        }
    }

    this->add_platforms();

    player->jump(dt, hit);


    //cout << player->getPosition().second << endl;
}

shared_ptr<EM_Player> World::getPlayer() const {
    return player;
}

int World::getWidth() const {
    return WIDTH;
}

int World::getHeight() const {
    return HEIGHT;
}

const vector<shared_ptr<EM_Platform>> &World::getPlatforms() const {
    return platforms;
}

shared_ptr<Camera> World::getCamera() const {
    return camera;
}

bool World::isGameOver() const {
    return GameOver;
}

void World::Reset(){
    player->PlayerReset(camera->toGamewidth(150.0f, WIDTH/8.0f), camera->toGameheight(300.0f, HEIGHT/12.0f));
    camera->CameraReset();
    height_of_last_platform = 0;

    for (auto platform : platforms){
        platform.reset();
    }
    platforms.clear();

    GameOver = false;

    this->create_platforms();
}

World::~World() {

}





