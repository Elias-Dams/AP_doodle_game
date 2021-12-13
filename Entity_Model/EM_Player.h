
#ifndef AP_DOODLE_GAME_EM_PLAYER_H
#define AP_DOODLE_GAME_EM_PLAYER_H

#include <vector>
#include <cmath>
#include "Entity_Model.h"


class EM_Player : public Entity_Model {

public:

    EM_Player(float player_width, float player_height);

    virtual ~EM_Player();

    void move(const float &xpos, const float &ypos);

    void jump(const float &dt,const bool &hit);

    float getPlayerWidth() const;

    float getPlayerHeight() const;

    const pair<float, float> &getPosition() const;

    void setPosition(const float &x, const float &y);

    bool isfalling();

    void resetmaxheight();

    void PlayerReset(float startposx, float startposy);

private:
    float maxheight;
    pair<float, float> position;
    float gravity;
    float player_width;
    float player_height;
    bool falling;


};


#endif //AP_DOODLE_GAME_EM_PLAYER_H
