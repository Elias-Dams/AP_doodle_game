
#ifndef AP_DOODLE_GAME_EV_JETPACK_H
#define AP_DOODLE_GAME_EV_JETPACK_H

#include "../EV_Bonus.h"
#include "../../../logic/Entity_Model/Entity_Model.h"

class View::EV_Jetpack : public View::EV_Bonus{
public:
    EV_Jetpack(Entity_Model &subject, float Width, float Height, shared_ptr<Camera> camera);

    void UpdatePosition(float xpos, float ypos) override;

    sf::Sprite getBonus() const override;

    ~EV_Jetpack() override;

private:
    unique_ptr<sf::Sprite> jetpack;
    unique_ptr<sf::Texture> texture;
    shared_ptr<Camera> camera;
    float jetpack_Width;
    float jetpack_Height;
};



#endif //AP_DOODLE_GAME_EV_JETPACK_H
