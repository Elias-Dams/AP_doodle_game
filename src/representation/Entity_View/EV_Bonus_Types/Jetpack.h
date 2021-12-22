
#ifndef AP_DOODLE_GAME_V_JETPACK_H
#define AP_DOODLE_GAME_V_JETPACK_H

#include "../../../logic/Entity_Model/Entity_Model.h"
#include "../Bonus.h"

class View::Jetpack : public View::Bonus {
public:
    Jetpack(Entity_Model &subject, float Width, float Height, shared_ptr<Camera> camera);

    void UpdatePosition(float xpos, float ypos) override;

    sf::Sprite getBonus() const override;

    ~Jetpack() override;

private:
    unique_ptr<sf::Sprite> jetpack;
    unique_ptr<sf::Texture> texture;
    shared_ptr<Camera> camera;
    float jetpack_Width;
    float jetpack_Height;
};


#endif//AP_DOODLE_GAME_JETPACK_H
