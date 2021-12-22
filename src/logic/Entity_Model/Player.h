
#ifndef AP_DOODLE_GAME_M_PLAYER_H
#define AP_DOODLE_GAME_M_PLAYER_H

#include <vector>
#include <cmath>
#include "Entity_Model.h"
#include "Namespaces.cpp"


class Model::Player : public Entity_Model {

public:

    Player(float player_width, float player_height);

    void move(const float &xpos, const float &ypos);

    void jump(const float &dt,const bool &hit, const bool &bonus_hit, const string& bonustype);

    float getWidth() const override;

    float getHeight() const override;

    const pair<float, float> &getPosition() const override;

    void setPosition(const float &x, const float &y) override;

    bool isfalling();

    void resetmaxheight();

    void PlayerReset(float startposx, float startposy);

    float getMaxheight() const;

    ~Player();

private:
    float maxheight;
    pair<float, float> position;
    float gravity;
    float player_width;
    float player_height;
    bool falling;


};


#endif //AP_DOODLE_GAME_PLAYER_H
