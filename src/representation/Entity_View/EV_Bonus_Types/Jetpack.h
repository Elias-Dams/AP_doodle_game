
#ifndef AP_DOODLE_GAME_V_JETPACK_H
#define AP_DOODLE_GAME_V_JETPACK_H

#include "../../../logic/Entity_Model/Entity_Model.h"
#include "../Bonus.h"

class View::Jetpack : public View::Bonus {
public:
    /**
     * Jetpack constructor.
     * constructs the jetpack whit given Entity model (this wil act as the subject whereby this jetpack will observere)
     * a given width and height and the camera to convert the coordinates to sfml coordinates
     */
    Jetpack(Entity_Model &subject, float Width, float Height, shared_ptr<Camera> camera);

    void UpdatePosition(float xpos, float ypos) override;

    sf::Sprite getBonus() const override;

    ~Jetpack() override;

private:
    unique_ptr<sf::Sprite> jetpack; ///< sfml sprite of the jetpack
    unique_ptr<sf::Texture> texture; ///< sfml texture of jetpack
    shared_ptr<Camera> camera; ///< the camera to convert the coordinates to sfml coordinates
    float jetpack_Width; ///< width of the jetpack
    float jetpack_Height; ///< height of the jetpack
};


#endif//AP_DOODLE_GAME_JETPACK_H
