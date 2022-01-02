
#ifndef AP_DOODLE_GAME_V_SPRING_H
#define AP_DOODLE_GAME_V_SPRING_H

#include "../../../logic/Entity_Model/Entity_Model.h"
#include "../V_Bonus.h"

class View::Spring : public View::Bonus {
public:
    /**
     * Spring constructor.
     * constructs the spring with
     * a given width and height and the camera to convert the coordinates to sfml coordinates
     */
    Spring(const float &Width, const float &Height, const shared_ptr<Camera> &camera);

    void UpdatePosition(const float &xpos, const float &ypos) override;

    sf::Sprite getBonus() const override;

    virtual ~Spring();

private:
    unique_ptr<sf::Sprite> spring; ///< sfml sprite of the spring
    unique_ptr<sf::Texture> texture; ///< sfml texture of the spring
    shared_ptr<Camera> camera; ///< the camera to convert the coordinates to sfml coordinates
    float spring_Width; ///< width of the Spring
    float spring_Height; ///< height of the Spring
};


#endif//AP_DOODLE_GAME_SPRING_H
