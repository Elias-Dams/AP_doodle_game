
#include "Player.h"

Model::Player::Player(float player_width_, float player_height_) :
    player_width(player_width_), player_height(player_height_) {
    gravity = 0.20f;
    falling = true;
    maxheight = 0;
}

void Model::Player::move(const float &x, const float &y) {
    position.first += x;
    position.second += y;

    NotifyPosition(position.first, position.second);
}


void Model::Player::jump(const float &dt, const bool &hit, const bool &bonus_hit, const string &bonustype) {

    if (position.second >= 0) {

        // jump in with a gravity constant range from -10 to 10
        // -10 --------------- 0 --------------- 10 ----------- ( until the player hits a platform )
        //           up               down

        gravity += 0.2f * dt * 60.0f;

        // subtract the gravity from the y pos

        position.second -= gravity * dt * 60.0f;
        if (gravity > 0) {
            falling = true;
            NotifyNormal();
        } else if (gravity < 0) {
            falling = false;
        }

        if (hit and !bonus_hit) {
            gravity = -10.0f;// jumpheight = 250
        } else if (bonus_hit and !hit and bonustype == "spring") {
            gravity = -23.0f;// jumpheight = 1250
            NotifySpting();
        } else if (bonus_hit and !hit and bonustype == "jetpack") {
            gravity = -34.6f;// jumpheight = 3000
            NotifyJetpack();
        }
    }
    if (position.second >= maxheight) {
        maxheight = position.second;
        NewMaxHeigh(maxheight);
    }

    NotifyPosition(position.first, position.second);
}

float Model::Player::getWidth() const {
    return player_width;
}

float Model::Player::getHeight() const {
    return player_height;
}

const pair<float, float> &Model::Player::getPosition() const {
    return position;
}

void Model::Player::setPosition(const float &x, const float &y) {
    Player::position = make_pair(x, y);
    NotifyPosition(x, y);
}

bool Model::Player::isfalling() {
    return falling;
}

void Model::Player::resetmaxheight() {
    maxheight = 0;
    NotifyReset();
}

void Model::Player::PlayerReset(float startposx, float startposy) {
    position.first = startposx;
    position.second = startposy;
    gravity = 0.20f;
    falling = true;
    maxheight = 0;
    NotifyPosition(startposx, startposy);
    NotifyReset();
}

float Model::Player::getMaxheight() const {
    return maxheight;
}

Model::Player::~Player() {
    cout << "destructor of Player" << endl;
}