
#ifndef AP_DOODLE_GAME_V_BG_TILE_H
#define AP_DOODLE_GAME_V_BG_TILE_H

#include "Entity_View.h"
#include "../../logic/Namespaces.cpp"

class View::BG_Tile : public Entity_View {
public:
    BG_Tile(Subject &subject, float width, float height, shared_ptr<Camera> camera_);

    void UpdatePosition(float xpos, float ypos) override;

    const sf::Sprite &getBackground() const;

    ~BG_Tile() override;

private:

    float width;
    float height;
    sf::Texture texture;
    sf::Sprite background;
    shared_ptr<Camera> camera;
};


#endif //AP_DOODLE_GAME_BG_TILE_H
