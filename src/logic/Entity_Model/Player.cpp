
#include "Player.h"

Model::Player::Player(float player_width_, float player_height_) :
    player_width(player_width_), player_height(player_height_) {
    gravity = 0.20f;
    falling = true;
    jumpheigt = 250.0f;
}

void Model::Player::move(const float &x, const float &y) {
    position.first += x;
    position.second += y;

    NotifyPosition(position.first, position.second);
}


void Model::Player::jump(const float &dt, const bool &hit, int height_modifier) {

    if (position.second >= 0) {

        if (hit) {
            float height = jumpheigt * (float)height_modifier;
            float temp = sqrtf((2.0f/5.0f)*height);
            if(height < 500){
                // normal
            }
            else if(height < 1500){
                NotifyMedium();
                // increase the score when bonus is collected
                NotifyIncreaseScore(100);
            }
            else {
                NotifyHigh();
                // increase the score when bonus is collected
                NotifyIncreaseScore(300);
            }
            gravity = -temp;
        }

        // jump in with a gravity constant range from -10 to 10
        // -10 --------------- 0 --------------- 10 ----------- ( until the player hits a platform )
        //           up               down

        gravity += 0.2f * dt * 60.0f;

        // subtract the gravity from the y pos

        position.second -= gravity * dt * 60.0f;

        if (gravity > 0) {
            falling = true;
            NotifyNormal();
        } else if (gravity <= 0) {
            falling = false;
        }


    }

    //cout << "(" << position.first << ", " << position.second << ")" << endl;
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

bool Model::Player::isfalling() const {
    return falling;
}

void Model::Player::PlayerReset(float startposx, float startposy) {
    position.first = startposx;
    position.second = startposy;
    gravity = 0.20f;
    falling = true;
    platfom_touched.reset();
    NotifyPosition(startposx, startposy);
    NotifyReset();
}

Model::Player::~Player() {

}
void Model::Player::setPlatfomTouched(const shared_ptr<Entity_Model> &platfomTouched) {

    if(platfomTouched.get() == platfom_touched.get()){
        // if the same platform is hit decrease the score bij 100
        NotifyDecreaseScore(100);
    }
    platfom_touched = platfomTouched;
}
