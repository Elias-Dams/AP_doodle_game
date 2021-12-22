
#ifndef AP_DOODLE_GAME_V_BONUS_H
#define AP_DOODLE_GAME_V_BONUS_H

#include "../../logic/Namespaces.cpp"
#include "Entity_View.h"

class View::Bonus : public Entity_View {

public:
    Bonus(Subject &subject);

    virtual sf::Sprite getBonus() const = 0;

    virtual ~Bonus() override;
};


#endif//AP_DOODLE_GAME_BONUS_H
