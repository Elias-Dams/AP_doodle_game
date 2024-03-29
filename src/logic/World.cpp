
#include "World.h"

World::World(const shared_ptr<Abstract_Factory> &factory) : factory(factory) {
    WIDTH = 400;
    HEIGHT = 600;
    platforms_per_view = 20;
    last_max_of_radius = 0;
    height_of_the_last_platform = 0;
    exeption_width = {0.0f,0.0f};
    exeption_height = 0;
    camera = factory->createCamera((float)WIDTH, (float)HEIGHT);
    player = factory->createPlayer((float) WIDTH / 8.0f, (float) HEIGHT / 12.0f, 150.0f, 300.0f, camera);
    background.first = factory->createBackground((float) WIDTH, (float) HEIGHT, 0.0f, 0.0f, camera);
    background.second = factory->createBackground((float) WIDTH, (float) HEIGHT, 0.0f, (float) HEIGHT + 0.0f, camera);
    weak_ptr<Random> random = Random::GetInstance(); // initialize the singleton
    GameOver = false;
    constant = 1;
}

void World::create_start_platform() {

    shared_ptr<Green_Platform> platform = factory->createGreenPlatform((float)WIDTH / 5.5f, (float)HEIGHT / 32.0f, camera);
    platform->setPosition(45.0f, 100.0f);
    platforms.push_back(platform);
}

void World::create_platforms() {
    int radius_per_platform = (HEIGHT * 2) / platforms_per_view;
    weak_ptr<Random> random = Random::GetInstance();

    // at the start of the game we create green platforms
    for (int i = 0; i < platforms_per_view; i++) {

        int from = last_max_of_radius;
        int to = last_max_of_radius + radius_per_platform;
        shared_ptr<Green_Platform> platform = factory->createGreenPlatform((float)WIDTH / 5.5f, (float)HEIGHT / 32.0f, camera);
        platform->setPosition(random.lock()->generate_between(0, (float) WIDTH - platform->getWidth()),
                              random.lock()->generate_between((float) from + platform->getHeight(), (float) to));
        platforms.push_back(platform);
        last_max_of_radius = last_max_of_radius + radius_per_platform;
        height_of_the_last_platform = (int)platform->getPosition().second;
    }
}

void World::add_platforms() {

    int platforms_to_add = platforms_per_view - (int) platforms.size();

    if (platforms_to_add > 0) {

        weak_ptr<Random> random = Random::GetInstance();

        // radius in witch a platform can generate
        int radius_per_platform = 2.0f * (float)HEIGHT / (float)platforms_per_view;

        for (int i = 0; i < platforms_to_add; i++) {

            int from = last_max_of_radius;
            int to = last_max_of_radius + radius_per_platform;

            shared_ptr<Platform> platform;
            shared_ptr<Bonus> bonus;
            bool has_bonus = false;
            // randomly choose a type of platform
            float platform_chance = random.lock()->generate_between(0.0f, 10.0f);
            float bonus_chance = random.lock()->generate_between(0.0f, 10.0f);

            // green platform
            // the constant is used to reduce the platform_chances of a green platform at a big height
            if (platform_chance <= (7.0f - (0.4375f) * (float)(constant - 1))) {
                platform = factory->createGreenPlatform((float) WIDTH / 5.5f, (float) HEIGHT / 32.0f, camera);

                // determine whether the platform has a bonus
                if (bonus_chance <= 1.0f) {
                    bonus = factory->createSpring((float) WIDTH / 21.5f, (float) HEIGHT / 32.0f, camera);
                    has_bonus = true;
                } else if (bonus_chance >= 9.5f) {
                    bonus = factory->createJetpack((float) WIDTH / 14.0f, (float) HEIGHT / 14.0f, camera);
                    has_bonus = true;
                }
            }
            // white platform
            // the constant is used to reduce the platform_chances of a green platform at a big height
            else if (platform_chance <= (9.00f - (0.5f) * (constant - 1))) {
                platform = factory->createWhitePlatform((float) WIDTH / 5.5f, (float) HEIGHT / 32.0f, camera);

            }
            // blue platform
            // the constant is used to reduce the platform_chances of a green platform at a big height
            else if (platform_chance <= (9.50f - (0.25f) * (constant - 1))) {
                platform = factory->createBluePlatform((float) WIDTH / 5.5f, (float) HEIGHT / 32.0f, WIDTH, camera);

                // determine whether the platform has a bonus
                if (bonus_chance <= 0.5f) {
                    bonus = factory->createSpring((float) WIDTH / 21.5f, (float) HEIGHT / 32.0f, camera);
                    has_bonus = true;
                } else if (bonus_chance >= 9.5f) {
                    bonus = factory->createJetpack((float) WIDTH / 14.0f, (float) HEIGHT / 14.0f, camera);
                    has_bonus = true;
                }

            }
            // yellow platform
            // the constant is used to reduce the platform_chances of a green platform at a big height
            else if (platform_chance <= 10.0f and exeption_height <= 0) {
                platform = factory->createYellowPlatform((float) WIDTH / 5.5f, (float) HEIGHT / 32.0f, 200.0f, camera);

                // determine whether the platform has a bonus
                if (bonus_chance <= 0.5f) {
                    bonus = factory->createSpring((float) WIDTH / 21.5f, (float) HEIGHT / 32.0f, camera);
                    has_bonus = true;
                } else if (bonus_chance >= 9.5f) {
                    bonus = factory->createJetpack((float) WIDTH / 14.0f, (float) HEIGHT / 14.0f, camera);
                    has_bonus = true;
                }
            }
            else{
                platform = factory->createGreenPlatform((float) WIDTH / 5.5f, (float) HEIGHT / 32.0f, camera);
            }


            if(exeption_height <= 0){
                platform->setPosition(random.lock()->generate_between(0, (float) WIDTH - platform->getWidth()),
                                      random.lock()->generate_between((float) from + platform->getHeight(), (float) to));

            }
            else{
                platform->setPosition(random.lock()->generate_between_exeption(0, (float) WIDTH - platform->getWidth(), exeption_width.first - platform->getWidth(), exeption_width.second),
                                      random.lock()->generate_between((float) from + platform->getHeight(), (float) to));
                exeption_height -= radius_per_platform;
            }

            // yellow platform exeption:
            if(platform->getColor() == "Yellow"){
                platform->setPosition(this->getFreeSpace(),random.lock()->generate_between((float) from + platform->getHeight(), (float) to));
                exeption_width.first = platform->getPosition().first;
                exeption_width.second = platform->getPosition().first + platform->getWidth();
                exeption_height = 100.0f + platform->getHeight();
            }

            if (height_of_the_last_platform + 200.0f < platform->getPosition().second) {
                // we have to correct the height of the platform, so it is reachable

                platform->setPosition(platform->getPosition().first, height_of_the_last_platform + 200.0f);

                last_max_of_radius = last_max_of_radius + radius_per_platform;
                height_of_the_last_platform = (int) platform->getPosition().second;
                platforms.push_back(platform);
                if (has_bonus) {
                    bonus->setPosition(platform->getPosition().first + platform->getWidth() / 2 - bonus->getWidth() / 2,
                                       platform->getPosition().second + platform->getHeight());
                    bonusses[platform] = bonus;
                }

            } else {
                last_max_of_radius = last_max_of_radius + radius_per_platform;
                height_of_the_last_platform = (int) platform->getPosition().second;
                platforms.push_back(platform);
                if (has_bonus) {
                    bonus->setPosition(platform->getPosition().first + platform->getWidth() / 2 - bonus->getWidth() / 2,
                                       platform->getPosition().second + platform->getHeight());
                    bonusses[platform] = bonus;
                }
            }
        }
    }
}


bool World::colisionCheck(shared_ptr<Entity_Model> entity, const bool can_update_score) {
    // the left side of the player
    if (entity->getPosition().first <= player->getPosition().first and
        player->getPosition().first <= entity->getPosition().first + entity->getWidth()) {

        if (player->getPosition().second - (entity->getPosition().second + entity->getHeight()) <= 0 and
            player->getPosition().second - entity->getPosition().second >= 0 and player->isfalling()) {

            if(can_update_score){
                player->setPlatfomTouched(entity);
            }

            return true;
        }
    }
    // right side of the player
    else if (entity->getPosition().first <= player->getPosition().first + player->getWidth() and
             player->getPosition().first + player->getWidth() <= entity->getPosition().first + entity->getWidth()) {

        if (player->getPosition().second - (entity->getPosition().second + entity->getHeight()) <= 0 and
            player->getPosition().second - entity->getPosition().second >= 0 and player->isfalling()) {

            if(can_update_score){
                player->setPlatfomTouched(entity);
            }

            return true;
        }
    }

    // between the player
    else if (entity->getPosition().first >= player->getPosition().first and
             player->getPosition().first + player->getWidth() >= entity->getPosition().first + entity->getWidth()) {

        if (player->getPosition().second - (entity->getPosition().second + entity->getHeight()) <= 0 and
            player->getPosition().second - entity->getPosition().second >= 0 and player->isfalling()) {

            if(can_update_score){
                player->setPlatfomTouched(entity);
            }

            return true;
        }
    }
    return false;
}

float World::getFreeSpace(){
    weak_ptr<Platform> platform1 = platforms.end()[-1];
    weak_ptr<Platform> platform2 = platforms.end()[-2];
    if(platform1.lock()->getPosition().first > platform2.lock()->getPosition().first){
        platform1 = platforms.end()[-2];
        platform2 = platforms.end()[-1];
    }
    weak_ptr<Random> random = Random::GetInstance();

    float freeSpace1 = 0.0f;
    float freeSpace2 = 0.0f;
    float freeSpace3 = 0.0f;
    if(0 < platform1.lock()->getPosition().first - platform1.lock()->getWidth()){
        freeSpace1 = random.lock()->generate_between(0, platform1.lock()->getPosition().first - platform1.lock()->getWidth());
    }
    if(platform1.lock()->getPosition().first + platform1.lock()->getWidth() < platform2.lock()->getPosition().first - platform2.lock()->getWidth()){
        freeSpace2 = random.lock()->generate_between(platform1.lock()->getPosition().first + platform1.lock()->getWidth(), platform2.lock()->getPosition().first - platform2.lock()->getWidth());
    }
    if(platform2.lock()->getPosition().first + platform2.lock()->getWidth() < WIDTH -  platform2.lock()->getWidth()){
        freeSpace3 = random.lock()->generate_between(platform2.lock()->getPosition().first + platform2.lock()->getWidth(), WIDTH -  platform2.lock()->getWidth());
    }
    float choice = random.lock()->generate_between(0.0f,3.0f);

    if(choice <= 1.0f and freeSpace1 != 0.0f){
        return freeSpace1;
    }
    else if(choice <= 2.0f and freeSpace2 != 0.0f){
        return freeSpace2;
    }
    else{
        return freeSpace3;
    }

}

void World::startstate(const float dt) {
    if (platforms.empty()) {
        this->create_start_platform();
        player->PlayerReset(50.0f, 300.0f);
    }

    bool hit = false;
    vector<shared_ptr<Platform>>::iterator it = platforms.begin();
    while (it != platforms.end()) {

        (*it)->update(dt);

        // false because we can't alter the score
        if (this->colisionCheck(*it, false)) {
            hit = true;
        }
        ++it;
    }

    player->jump(dt, hit, 1);
}

void World::update(const float dt, const char key) {
    if (platforms.empty()) {
        this->create_platforms();
    }
    // game over;
    if (player->getPosition().second < (camera->getNomalisedHeight() - HEIGHT / 2)) {
        GameOver = true;
    }

    // update the background
    if (background.second->getPosition().second + HEIGHT / 2 <= camera->getNomalisedHeight()) {
        background.first->setPosition(background.second->getPosition().first,
                                      background.second->getPosition().second + HEIGHT);

        shared_ptr<BG_Tile> temp = background.second;
        background.second = background.first;
        background.first = temp;
    }

    // move the player
    if (key == 'Q') {
        player->move(-5.f * dt * 60.f, 0.f * dt * 60.f);
    }
    if (key == 'D') {
        player->move(5.f * dt * 60.f, 0.f * dt * 60.f);
    }

    // if player goes out of the screen to the left it will go to the right.
    if (player->getPosition().first <= -player->getWidth()) {
        player->setPosition(WIDTH - player->getWidth(), player->getPosition().second);
    }
    // if player goes out of the screen to the right it will go to the left.
    if (player->getPosition().first >= WIDTH) {
        player->setPosition(0, player->getPosition().second);
    }

    // check collision
    int height_modification = 1;

    bool hit = false;
    bool bonus_hit = false;

    vector<shared_ptr<Platform>>::iterator it = platforms.begin();
    while (it != platforms.end()) {
        bool current_hit = false;

        (*it)->update(dt);

        // if the platform has a bonus we update the bonuses position.
        if (bonusses.count((*it))) {
            bonusses[(*it)]->update(
                    (*it)->getPosition().first + (*it)->getWidth() / 2 - bonusses[(*it)]->getWidth() / 2,
                    (*it)->getPosition().second + (*it)->getHeight());
            // true because we can alter the score
            if (this->colisionCheck(bonusses[(*it)], true)) {
                hit = true;
                bonus_hit = true;
                current_hit = true;
                height_modification = bonusses[(*it)]->getBonuspower();
            }
        }
        // true because we can alter the score
        if (this->colisionCheck(*it, true) and !hit) {
            hit = true;
            current_hit = true;
        }
        // if the platform goes out of the view we delete it.
        if ((*it)->getPosition().second < (camera->getNomalisedHeight() - HEIGHT / 2) - (*it)->getHeight()) {
            if (bonusses.count((*it))) {
                factory->delete_bonus(bonusses[(*it)]);
                bonusses[(*it)].reset();
                bonusses.erase((*it));
            }
            factory->delete_platform((*it));
            (*it).reset();
            platforms.erase(it);

        } else if (current_hit and (*it)->getColor() == "White") {
            factory->delete_platform((*it));
            (*it).reset();
            platforms.erase(it);

        } else if (current_hit and bonus_hit and bonusses.count((*it))) {
            // make the jetpack disappear
            if (bonusses[(*it)]->getBonuspower() == 12) {
                factory->delete_bonus(bonusses[(*it)]);
                bonusses[(*it)].reset();
                bonusses.erase((*it));
            } else {
                ++it;
            }
        } else {
            ++it;
        }
    }


    // If we get higher there are fewer platforms needed
    // Because of the way I draw my platforms the constant has to be smaller or equal to
    // the height if the world * 2 /100 <= platforms per 2 views - constant
    // |---------600 * 2 / 100--------| <= |--------20 - constant------------| ==> 12 <= 20 - constant
    // if the constant becomes more, it is almost impossible to draw platforms that are reachable by the player
    if ((int) camera->getNomalisedHeight() >= 3000 * constant && constant <= 16) {
        constant += 1;
        platforms_per_view -= 1;
    }

    // add platforms
    this->add_platforms();

    player->jump(dt, hit, height_modification);

    // update the camera pos
    if (player->getPosition().second >= camera->getNomalisedHeight()) {
        camera->setHeight(player->getPosition().second);
    }
}

shared_ptr<Player> World::getPlayer() const {
    return player;
}

int World::getWidth() const {
    return WIDTH;
}

int World::getHeight() const {
    return HEIGHT;
}

const vector<shared_ptr<Platform>> &World::getPlatforms() const {
    return platforms;
}

shared_ptr<Camera> World::getCamera() const {
    return camera;
}

bool World::isGameOver() const {
    return GameOver;
}

void World::deletePlatforms(){
    for (shared_ptr<Platform> platform : platforms) {
        if (bonusses.count(platform)) {
            factory->delete_bonus(bonusses[platform]);
            bonusses[platform].reset();
            bonusses.erase(platform);
        }
        factory->delete_platform(platform);
        platform.reset();
    }
    platforms.clear();
}

void World::Reset() {
    player->PlayerReset(50.0f, 300.0f);
    camera->CameraReset();
    last_max_of_radius = 0;
    height_of_the_last_platform = 0;
    platforms_per_view = 20;
    exeption_width = {0.0f,0.0f};
    exeption_height = 0;

    this->deletePlatforms();

    GameOver = false;

    background.first->setPosition(0.0f, 0.0f);
    background.second->setPosition(0.0f, (float) HEIGHT + 0.0f);

    constant = 1;

    platforms.clear();
    bonusses.clear();
}

World::~World() {

    for (std::map<shared_ptr<Platform>, shared_ptr<Bonus>>::iterator it = bonusses.begin(); it != bonusses.end(); it++) {
        factory->delete_bonus(it->second);
        it->second.reset();
    }

    for (shared_ptr<Platform> platform : platforms) {
        bonusses.erase(platform);
        factory->delete_platform(platform);
    }

    platforms.clear();
    bonusses.clear();

    factory.reset();

    background.first.reset();
    background.second.reset();
}

const pair<shared_ptr<BG_Tile>, shared_ptr<BG_Tile>> &World::getBackground() const {
    return background;
}

const map<shared_ptr<Platform>, shared_ptr<Bonus>> &World::getBonuses() const {
    return bonusses;
}
