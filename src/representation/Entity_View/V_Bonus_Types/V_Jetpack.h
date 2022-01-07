
#ifndef AP_DOODLE_GAME_V_JETPACK_H
#define AP_DOODLE_GAME_V_JETPACK_H

#include "../../../logic/Entity_Model/Entity_Model.h"
#include "../V_Bonus.h"

class View::Jetpack : public View::Bonus {
public:
    /**
     * Jetpack constructor.
     * Constructs the jetpack with 
     * a given width and height and the camera to convert the coordinates to sfml coordinates
     */
    Jetpack(const float &Width, const float &Height, const shared_ptr<Camera> &camera);

    void UpdatePosition(const float &xpos, const float &ypos) override;

    sf::Sprite getBonus() const override;

    virtual ~Jetpack();

private:
    unique_ptr<sf::Sprite> jetpack; ///< sfml sprite of the jetpack
    unique_ptr<sf::Texture> texture; ///< sfml texture of jetpack
    shared_ptr<Camera> camera; ///< the camera to convert the coordinates to sfml coordinates
    float jetpack_Width; ///< width of the jetpack
    float jetpack_Height; ///< height of the jetpack
};


#endif//AP_DOODLE_GAME_JETPACK_H
