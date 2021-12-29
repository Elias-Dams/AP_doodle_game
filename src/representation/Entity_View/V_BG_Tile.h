
#ifndef AP_DOODLE_GAME_V_BG_TILE_H
#define AP_DOODLE_GAME_V_BG_TILE_H

#include "../../logic/Namespaces.cpp"
#include "Entity_View.h"

class View::BG_Tile : public Entity_View {
public:
    /**
     * Background tile constructor.
     * constructs the background whit
     * a given width and height and the camera to convert the coordinates to sfml coordinates
     */
    BG_Tile(float width, float height, shared_ptr<Camera> camera_);

    /**
    * @brief gets the sfml sprite
    *
    * This function gets the sfml sprite of the background tile
    *
    * @return the sfml sprite of the background tile
    */
    const sf::Sprite &getBackground() const;

    void UpdatePosition(float xpos, float ypos) override;

    ~BG_Tile() override;

private:
    float width;
    float height;
    sf::Texture texture;
    sf::Sprite background;
    shared_ptr<Camera> camera;
};


#endif//AP_DOODLE_GAME_BG_TILE_H
