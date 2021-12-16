
#ifndef AP_DOODLE_GAME_EV_BG_TILE_H
#define AP_DOODLE_GAME_EV_BG_TILE_H

#include "Entity_View.h"

class EV_BG_Tile : public Entity_View {
public:
    EV_BG_Tile(Subject &subject, float width, float height, shared_ptr<Camera> camera_);

    void UpdatePosition(float xpos, float ypos) override;

    const sf::Sprite &getBackground() const;

    ~EV_BG_Tile();

private:

    float width;
    float height;
    sf::Texture texture;
    sf::Sprite background;
    shared_ptr<Camera> camera;
};


#endif //AP_DOODLE_GAME_EV_BG_TILE_H
