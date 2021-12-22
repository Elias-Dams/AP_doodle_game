
#ifndef AP_DOODLE_GAME_V_SPRING_H
#define AP_DOODLE_GAME_V_SPRING_H

#include "../Bonus.h"
#include "../../../logic/Entity_Model/Entity_Model.h"

class View::Spring : public View::Bonus {
public:
    Spring(Entity_Model &subject, float Width, float Height, shared_ptr<Camera> camera);

    void UpdatePosition(float xpos, float ypos) override;

    sf::Sprite getBonus() const override;

    ~Spring() override;

private:
    unique_ptr<sf::Sprite> spring;
    unique_ptr<sf::Texture> texture;
    shared_ptr<Camera> camera;
    float spring_Width;
    float spring_Height;
};


#endif //AP_DOODLE_GAME_SPRING_H
