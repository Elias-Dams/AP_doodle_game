
#ifndef AP_DOODLE_GAME_V_BONUS_H
#define AP_DOODLE_GAME_V_BONUS_H

#include "../../logic/Namespaces.cpp"
#include "Entity_View.h"

class View::Bonus : public Entity_View {

public:
    /**
     * Bonus constructor.
     * Constructs the bonus
     */
    Bonus();

    /**
    * @brief Gets the sfml sprite
    *
    * This function gets the sfml sprite of the bonus
    *
    * @return the sfml sprite of the bonus
    */
    virtual sf::Sprite getBonus() const = 0;

    virtual ~Bonus();
};


#endif//AP_DOODLE_GAME_BONUS_H
