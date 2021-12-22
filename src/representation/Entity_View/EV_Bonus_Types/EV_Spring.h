
#ifndef AP_DOODLE_GAME_EV_SPRING_H
#define AP_DOODLE_GAME_EV_SPRING_H

#include "../EV_Bonus.h"
#include "../../../logic/Entity_Model/Entity_Model.h"

class View::EV_Spring : public View::EV_Bonus {
public:
    EV_Spring(Entity_Model &subject, float Width, float Height, shared_ptr<Camera> camera);

    void UpdatePosition(float xpos, float ypos) override;

    sf::Sprite getBonus() const override;

    ~EV_Spring() override;

private:
    unique_ptr<sf::Sprite> spring;
    unique_ptr<sf::Texture> texture;
    shared_ptr<Camera> camera;
    float spring_Width;
    float spring_Height;
};


#endif //AP_DOODLE_GAME_EV_SPRING_H
