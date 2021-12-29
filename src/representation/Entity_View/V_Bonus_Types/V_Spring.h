
#ifndef AP_DOODLE_GAME_V_SPRING_H
#define AP_DOODLE_GAME_V_SPRING_H

#include "../../../logic/Entity_Model/Entity_Model.h"
#include "../V_Bonus.h"

class View::Spring : public View::Bonus {
public:
    /**
     * Spring constructor.
     * constructs the spring whit
     * a given width and height and the camera to convert the coordinates to sfml coordinates
     */
    Spring(float Width, float Height, shared_ptr<Camera> camera);

    void UpdatePosition(float xpos, float ypos) override;

    sf::Sprite getBonus() const override;

    ~Spring() override;

private:
    unique_ptr<sf::Sprite> spring; ///< sfml sprite of the spring
    unique_ptr<sf::Texture> texture; ///< sfml texture of the spring
    shared_ptr<Camera> camera; ///< the camera to convert the coordinates to sfml coordinates
    float spring_Width; ///< width of the Spring
    float spring_Height; ///< height of the Spring
};


#endif//AP_DOODLE_GAME_SPRING_H
