
#include "EM_Player.h"

EM_Player::EM_Player(float player_width_, float player_height_) : player_width(player_width_), player_height(player_height_){
    gravity = 0.20f;
    falling = true;
    maxheight = 0;
}

void EM_Player::move(const float &xpos, const float &ypos){
    position.first += xpos;
    position.second += ypos;

    NotifyPosition(position.first, position.second);

}


void EM_Player::jump(const float &dt,const bool &hit, const bool &bonus_hit, const string& bonustype){

    if(position.second >= 0){

        // jump in with a gravity constant range from -10 to 10
        // -10 --------------- 0 --------------- 10 ----------- ( until the player hits a platform )
        //           up               down

        gravity += 0.2f * dt * 60.0f;

        // subtract the gravity from the y pos

        position.second -= gravity * dt * 60.0f;
        if(gravity > 0){
            falling = true;
            NotifyNormal();
        }
        else if(gravity < 0){
            falling = false;
        }

        if (hit and !bonus_hit){
            gravity = -10.0f; // jumpheight = 250
        }
        else if (bonus_hit and !hit and bonustype == "spring" ){
            gravity = -23.0f; // jumpheight = 1250
            NotifySpting();
        }
        else if (bonus_hit and !hit and bonustype == "jetpack" ){
            gravity = -34.6f; // jumpheight = 3000
            NotifyJetpack();
        }

    }
    if(position.second >= maxheight){
        maxheight = position.second;
        NewMaxHeigh(maxheight);
    }

    NotifyPosition(position.first, position.second);
}

float EM_Player::getWidth() const {
    return player_width;
}

float EM_Player::getHeight() const {
    return player_height;
}

const pair<float, float> &EM_Player::getPosition() const {
    return position;
}

void EM_Player::setPosition(const float &x, const float &y) {
    EM_Player::position = make_pair(x,y);
    NotifyPosition(x, y);
}

bool EM_Player::isfalling(){
    return falling;
}

void EM_Player::resetmaxheight(){
    maxheight = 0;
    NotifyReset();
}

void EM_Player::PlayerReset(float startposx, float startposy){
    position.first = startposx;
    position.second = startposy;
    gravity = 0.20f;
    falling = true;
    maxheight = 0;
    NotifyPosition(startposx, startposy);
    NotifyReset();
}

float EM_Player::getMaxheight() const {
    return maxheight;
}

EM_Player::~EM_Player() {
    cout << "destructor of EM_Player" << endl;
}