
#include "World.h"

World::World(const shared_ptr<Abstract_Factory> &factory) : factory(factory) {
    WIDTH = 400;
    HEIGHT = 600;
    platforms_per_view = 20;
    last_max_of_radius = 0;
    height_of_the_last_platform = 0;
    camera = make_shared<Camera>(WIDTH, HEIGHT);
    player = factory->createPlayer((float) WIDTH / 8.0f, (float) HEIGHT / 12.0f, 150.0f, 300.0f, camera);
    background.first = factory->createBackground((float) WIDTH, (float) HEIGHT, 0.0f, 0.0f, camera);
    background.second = factory->createBackground((float) WIDTH, (float) HEIGHT, 0.0f, (float) HEIGHT + 0.0f, camera);
    random = unique_ptr<Random>(Random::GetInstance());
    GameOver = false;
    constant = 1;
}

void World::create_start_platform() {

    shared_ptr<EM_Green_Platform> platform = factory->createGreenPlatform(WIDTH / 5.5f, HEIGHT / 32.0f, camera);
    platform->setPosition(45.0f, 100.0f);
    platforms.push_back(platform);

}

void World::create_platforms() {
    int radius_per_platform = (HEIGHT * 2) / platforms_per_view;

    for (int i = 0; i < platforms_per_view; i++) {

        int from = last_max_of_radius;
        int to = last_max_of_radius + radius_per_platform;
        shared_ptr<EM_Green_Platform> platform = factory->createGreenPlatform(WIDTH / 5.5f, HEIGHT / 32.0f, camera);
        platform->setPosition(random->generate_between(0, (float) WIDTH - platform->getWidth()),
                              random->generate_between((float) from + platform->getHeight(), (float) to));
        platforms.push_back(platform);
        last_max_of_radius = last_max_of_radius + radius_per_platform;
        height_of_the_last_platform = platform->getPosition().second;
    }

}

void World::add_platforms() {

    int platforms_to_add = platforms_per_view - (int) platforms.size();

    if (platforms_to_add > 0) {
        //cout << camera->getHeight() << "   " << last_max_of_radius << endl;

        int radius_per_platform = (float) 2 * HEIGHT / platforms_per_view;

        //cout << radius_per_platform << endl;
        for (int i = 0; i < platforms_to_add; i++) {

            int from = last_max_of_radius;
            int to = last_max_of_radius + radius_per_platform;


            shared_ptr<EM_Platform> platform;
            shared_ptr<EM_Bonus> bonus;
            bool has_bonus = false;
            // randomly choose a type of platform
            float platform_chance = random->generate_between(0.0f, 10.0f);
            float bonus_chance = random->generate_between(0.0f, 10.0f);

            /// green platform
            // the constant is used to reduce the platform_chances of a green platform at a big height
            if (platform_chance <= (7.0f - (0.4375f) * (constant - 1))) {
                platform = factory->createGreenPlatform((float) WIDTH / 5.5f, (float) HEIGHT / 32.0f, camera);

                /// determine whether the platform has a bonus
                if (bonus_chance <= 1.0f) {
                    bonus = factory->createSpring((float) WIDTH / 21.5f, (float) HEIGHT / 32.0f, camera);
                    has_bonus = true;
                } else if (bonus_chance >= 9.5f) {
                    bonus = factory->createJetpack((float) WIDTH / 14.0f, (float) HEIGHT / 14.0f, camera);
                    has_bonus = true;
                }
            }
                /// white platform
                // the constant is used to reduce the platform_chances of a green platform at a big height
            else if (platform_chance <= (9.00f - (0.5f) * (constant - 1))) {
                platform = factory->createWhitePlatform((float) WIDTH / 5.5f, (float) HEIGHT / 32.0f, camera);

            }
                /// yellow platform
                // the constant is used to reduce the platform_chances of a green platform at a big height
            else if (platform_chance <= (9.50f - (0.25f) * (constant - 1))) {
                platform = factory->createBluePlatform((float) WIDTH / 5.5f, (float) HEIGHT / 32.0f, camera);

                /// determine whether the platform has a bonus
                if (bonus_chance <= 0.5f) {
                    bonus = factory->createSpring((float) WIDTH / 21.5f, (float) HEIGHT / 32.0f, camera);
                    has_bonus = true;
                } else if (bonus_chance >= 9.5f) {
                    bonus = factory->createJetpack((float) WIDTH / 14.0f, (float) HEIGHT / 14.0f, camera);
                    has_bonus = true;
                }

            }
                /// blue platform
                // the constant is used to reduce the platform_chances of a green platform at a big height
            else if (platform_chance <= 10.0f) {
                platform = factory->createYellowPlatform((float) WIDTH / 5.5f, (float) HEIGHT / 32.0f, 200.0f, camera);

                /// determine whether the platform has a bonus
                if (bonus_chance <= 0.5f) {
                    bonus = factory->createSpring((float) WIDTH / 21.5f, (float) HEIGHT / 32.0f, camera);
                    has_bonus = true;
                } else if (bonus_chance >= 9.5f) {
                    bonus = factory->createJetpack((float) WIDTH / 14.0f, (float) HEIGHT / 14.0f, camera);
                    has_bonus = true;
                }
            }

            platform->setPosition(random->generate_between(0, (float) WIDTH - platform->getWidth()),
                                  random->generate_between((float) from + platform->getHeight(), (float) to));

            if ((int) height_of_the_last_platform + 200.0f < platform->getPosition().second) {
                // we have to correct the height of the platform, so it is reachable

                platform->setPosition(platform->getPosition().first, (int) height_of_the_last_platform + 200.0f);

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


bool World::colisionCheck(shared_ptr<Entity_Model> entity) {
    // the left side of the player
    if (entity->getPosition().first <= player->getPosition().first and
        player->getPosition().first <= entity->getPosition().first + entity->getWidth()) {

        if (player->getPosition().second - (entity->getPosition().second + entity->getHeight()) <= 0 and
            player->getPosition().second - entity->getPosition().second >= 0 and player->isfalling()) {

            return true;
        }
    }
    // right side of the player
    else if (entity->getPosition().first <= player->getPosition().first + player->getWidth() and
             player->getPosition().first + player->getWidth() <= entity->getPosition().first + entity->getWidth()) {

        if (player->getPosition().second - (entity->getPosition().second + entity->getHeight()) <= 0 and
            player->getPosition().second - entity->getPosition().second >= 0 and player->isfalling()) {

            return true;
        }
    }

    // between the player
    else if (entity->getPosition().first >= player->getPosition().first and
             player->getPosition().first + player->getWidth() >= entity->getPosition().first + entity->getWidth()) {

        if (player->getPosition().second - (entity->getPosition().second + entity->getHeight()) <= 0 and
            player->getPosition().second - entity->getPosition().second >= 0 and player->isfalling()) {

            return true;
        }
    }
    return false;
}

void World::startstate(float dt) {
    if (platforms.empty()) {
        this->create_start_platform();
        player->PlayerReset(50.0f, 300.0f);
    }

    bool hit = false;
    auto it = platforms.begin();
    while (it != platforms.end()) {

        (*it)->update(dt, WIDTH);

        if (this->colisionCheck(*it)) {
            hit = true;
        }
        ++it;

    }

    player->jump(dt, hit, false, "");
}

void World::update(float dt, const char &key) {
    if (platforms.size() == 1) {
        this->create_platforms();
    }
    /// game over;
    if (player->getPosition().second < (camera->getNomalisedHeight() - HEIGHT / 2)) {
        GameOver = true;
    }

    /// update the camera pos
    if (player->getPosition().second >= camera->getNomalisedHeight()) {
        camera->setHeight(player->getPosition().second);
    }

    /// update the background
    if (background.second->getPosition().second + HEIGHT / 2 <= camera->getNomalisedHeight()) {
        background.first->setPosition(background.second->getPosition().first,
                                      background.second->getPosition().second + HEIGHT);

        auto temp = background.second;
        background.second = background.first;
        background.first = temp;
    }

    /// move the player
    if (key == 'Q') {
        player->move(-5.f * dt * 60.f, 0.f * dt * 60.f);
    }
    if (key == 'D') {
        player->move(5.f * dt * 60.f, 0.f * dt * 60.f);
    }

    /// if player goes out of the screen to the left it wil go to the right.
    if (player->getPosition().first <= -player->getWidth()) {
        player->setPosition(WIDTH - player->getWidth(), player->getPosition().second);
    }
    /// if player goes out of the screen to the right it wil go to the left.
    if (player->getPosition().first >= WIDTH) {
        player->setPosition(0, player->getPosition().second);
    }

    /// check colision
    bool bonus_hit = false;
    string bonustype = "";
    bool hit = false;
    auto it = platforms.begin();
    while (it != platforms.end()) {
        bool current_hit = false;

        (*it)->update(dt, WIDTH);

        if (bonusses.count((*it))) {
            bonusses[(*it)]->update(
                    (*it)->getPosition().first + (*it)->getWidth() / 2 - bonusses[(*it)]->getWidth() / 2,
                    (*it)->getPosition().second + (*it)->getHeight());
            if (this->colisionCheck(bonusses[(*it)])) {
                bonus_hit = true;
                current_hit = true;
                bonustype = bonusses[(*it)]->getType();
            }
        }

        if (this->colisionCheck(*it) and !bonus_hit) {
            hit = true;
            current_hit = true;
        }

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
            if (bonusses[(*it)]->getType() == "jetpack") {
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

    /// if we het higher there need to be less platforms
    // because of the way draw my platforms the constant has to be smaller or equil to
    // the height if the world * 2 /100 <= platforms per 2 views - constant
    // |---------600 * 2 / 100--------| <= |--------20 - constant------------| ==> 12 <= 20 - constant
    // if the constant becomes more than it is almost impossible to draw platforms that are reachable bij the player
    if ((int) player->getMaxheight() >= 3000 * constant && constant <= 16) {
        constant += 1;
        platforms_per_view -= 1;
        /*
        cout << "green: " << 0 << "-----" <<  (7.0f -(0.4375f)*(constant-1)) << endl;
        cout << "white: " << (7.0f -(0.4375f)*(constant-1)) << "-----" <<(9.00f -(0.5f)*(constant-1)) << endl;
        cout << "blue: " << (9.00f -(0.5f)*(constant-1)) << "-----" <<(9.50f-(0.25f)*(constant-1)) << endl;
        cout << "yellow: " << (9.50f-(0.25f)*(constant-1)) << "-----" <<10 << endl;
        cout << "----------------------------" << endl;
        */
    }

    /// add platforms
    this->add_platforms();

    player->jump(dt, hit, bonus_hit, bonustype);

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

void World::Reset() {
    player->PlayerReset(50.0f, 300.0f);
    camera->CameraReset();
    last_max_of_radius = 0;
    height_of_the_last_platform = 0;
    platforms_per_view = 20;

    for (auto platform: platforms) {
        if (bonusses.count(platform)) {
            factory->delete_bonus(bonusses[platform]);
            bonusses[platform].reset();
            bonusses.erase(platform);
        }
        factory->delete_platform(platform);
        platform.reset();
    }
    platforms.clear();

    GameOver = false;

    background.first->setPosition(0.0f, 0.0f);
    background.second->setPosition(0.0f, (float) HEIGHT + 0.0f);

    constant = 1;

    platforms.clear();
    bonusses.clear();

}

World::~World() {
    cout << "-----destructor of World-----" << endl;
    cout << "factory: " << factory.use_count() << endl;
    cout << "player: " << player.use_count() << endl;
    for (std::map<shared_ptr<EM_Platform>, shared_ptr<EM_Bonus> >::iterator it = bonusses.begin();
         it != bonusses.end(); it++) {
        cout << "bonus: " << it->second.use_count() << "-->";
        factory->delete_bonus(it->second);
        it->second.reset();
        cout << "bonus: " << it->second.use_count() << endl;
    }
    for (auto platform: platforms) {
        cout << "platform: " << platform.use_count() << " --> ";
        bonusses.erase(platform);
        factory->delete_platform(platform);
        cout << "platform: " << platform.use_count() << endl;
    }

    cout << "background: " << background.first.use_count() << endl;
    cout << "background: " << background.second.use_count() << endl;
    cout << "-----------------------------" << endl;

    factory->delete_player(player);

    platforms.clear();
    bonusses.clear();

    factory.reset();

    background.first.reset();
    background.second.reset();

}

const pair<shared_ptr<EM_BG_Tile>, shared_ptr<EM_BG_Tile>> &World::getBackground() const {
    return background;
}

const map<shared_ptr<EM_Platform>, shared_ptr<EM_Bonus>> &World::getBonusses() const {
    return bonusses;
}





