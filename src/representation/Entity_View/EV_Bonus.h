
#ifndef AP_DOODLE_GAME_EV_BONUS_H
#define AP_DOODLE_GAME_EV_BONUS_H

#include "Entity_View.h"
#include "../../logic/namespaces.cpp"

class View::EV_Bonus : public Entity_View{

public:
    EV_Bonus(Subject &subject);

    virtual sf::Sprite getBonus() const = 0;

    virtual ~EV_Bonus() override;
};


#endif //AP_DOODLE_GAME_EV_BONUS_H
