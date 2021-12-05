
#include "EM_Player.h"

EM_Player::EM_Player(float player_width_, float player_height_) : player_width(player_width_), player_height(player_height_){
    position.first = 150;
    position.second = 299;
    gravity = 0.20f;
    falling = true;
}

EM_Player::~EM_Player() {

}

void EM_Player::move(const float &xpos, const float &ypos){
    position.first += xpos;
    position.second += ypos;

    Notify(position.first, position.second);

}


void EM_Player::jump(const float &dt,const bool &hit){


    if(position.second >= -0){

        // we jump in a range from -11 to 11
        // -11 --------------- 0 --------------- 11 ----------- ( until the player hits a platform )
        //           up               down

        gravity += 0.2f * dt * 60.0f;
        //cout << gravity << "\t" << position.second << endl;
        position.second -= gravity * dt * 60.0f;
        if(gravity > 0){
            falling = true;
        }
        if(gravity < 0){
            falling = false;
        }
        if (hit or position.second <= 0){
            gravity = -10.0f;
        }

    }

    Notify(position.first, position.second);
}

float EM_Player::getPlayerWidth() const {
    return player_width;
}

float EM_Player::getPlayerHeight() const {
    return player_height;
}

const pair<float, float> &EM_Player::getPosition() const {
    return position;
}

void EM_Player::setPosition(const float &x, const float &y) {
    EM_Player::position = make_pair(x,y);
}

bool EM_Player::isfalling(){
    return falling;
}