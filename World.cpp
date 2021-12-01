
#include "World.h"

World::World() {
    WIDTH = 400;
    HEIGHT = 600;
    platforms_per_view = 6;
    player = factory.createPlayer(100.0f, 100.0f);
    random = unique_ptr<Random>(Random::GetInstance());
    camera = make_shared<Camera>(WIDTH, HEIGHT);
    height_of_last_platform = 0;
    this->create_platforms();
}

void World::create_platforms(){
    int radius_per_platform = HEIGHT / platforms_per_view;
    for(int i = 0; i < platforms_per_view; i++){
        int temp = height_of_last_platform;
        height_of_last_platform += radius_per_platform;
        shared_ptr<EM_Platform> platform = factory.createPlatform(100.0f, 30.0f);
        platform->setPosition( random->generate_between(0,(float)WIDTH - platform->getPlatformWidht()), random->generate_between((float)temp+platform->getPlatformHeight(), (float)height_of_last_platform));
        platforms.push_back(platform);
    }

}

void World::add_platforms(){

    int platforms_ot_add = platforms_per_view - platforms.size();
    if(platforms_ot_add > 0){
        //cout << camera->getHeight() << "   " << height_of_last_platform << endl;
        int radius_per_platform = camera->getHeight()+HEIGHT/2 - height_of_last_platform / platforms_ot_add;
        //cout << radius_per_platform << endl;
        for(int i = 0; i < platforms_ot_add; i++){
            int temp = height_of_last_platform;
            height_of_last_platform += radius_per_platform;
            shared_ptr<EM_Platform> platform = factory.createPlatform(100.0f, 30.0f);;
            platform->setPosition( random->generate_between(0,(float)WIDTH - platform->getPlatformWidht()), random->generate_between((float)temp+platform->getPlatformHeight(), (float)height_of_last_platform));
            platforms.push_back(platform);
        }
    }
}

bool World::colisionCheck(shared_ptr<EM_Platform> platform){
    // the left side of the player
    if(platform->getPosition().first <= player->getPosition().first and player->getPosition().first <= platform->getPosition().first+platform->getPlatformWidht()){

        if(player->getPosition().second - (platform->getPosition().second + platform->getPlatformHeight()) <= 0 and player->getPosition().second - platform->getPosition().second >= 0 and player->isfalling()){

            return true;
        }
    }
        // right side of the player
    else if(platform->getPosition().first <= player->getPosition().first+player->getPlayerWidht() and player->getPosition().first+player->getPlayerWidht() <= platform->getPosition().first+platform->getPlatformWidht()){

        if(player->getPosition().second - (platform->getPosition().second + platform->getPlatformHeight()) <= 0 and player->getPosition().second - platform->getPosition().second >= 0 and player->isfalling()){

            return true;
        }
    }
}

void World::update(float dt, const char &key){

    if(player->getPosition().second > camera->getHeight()){
        camera->setHeight(player->getPosition().second);
    }

    if(key == 'Q'){
        player->move(-5.f * dt * 60.f, 0.f  * dt * 60.f);
    }
    if(key == 'D'){
        player->move(5.f * dt * 60.f, 0.f  * dt * 60.f);
    }
    // if player goes out of the screen to the left it wil go to the right.
    if (player->getPosition().first <= -player->getPlayerWidht()){
        player->setPosition(WIDTH - player->getPlayerWidht(), player->getPosition().second) ;
    }
    // if player goes out of the screen to the right it wil go to the left.
    if(player->getPosition().first >= WIDTH){
        player->setPosition(0, player->getPosition().second);
    }
    // check colision
    bool hit = false;
    int counter = 0;
    for(const auto& platform : platforms){

        if(this->colisionCheck(platform)){
            hit = true;
        }

        if(platform->getPosition().second < (camera->getHeight()-HEIGHT/2)-platform->getPlatformHeight()){
            cout << platform->getPosition().second << "  " << camera->getHeight()-HEIGHT/2 << endl;
            platforms.erase(platforms.begin() + counter);
            counter -= 1;
            cout << "delete" << endl;
            break;
        }
        else{
            platform->update();
        }
        counter += 1;
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

