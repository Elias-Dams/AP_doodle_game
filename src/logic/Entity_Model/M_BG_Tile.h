
#ifndef AP_DOODLE_GAME_M_BG_TILE_H
#define AP_DOODLE_GAME_M_BG_TILE_H

#include "Entity_Model.h"
#include "Namespaces.cpp"

/**
 * @class Background_Tile
 *
 * @brief This is the background of the game.
 * It moves with the World to make it seem that is stays static with the platforms.
 */

class Model::BG_Tile : public Entity_Model {
public:
    /**
     * Background_Tile constructor.
     * constructs a Background_Tile whit a certain width and height.
     */
    BG_Tile(float width, float height);

    virtual ~BG_Tile();

    // documentation in Enntity_model
    float getWidth() const;

    // documentation in Enntity_model
    float getHeight() const;

    // documentation in Enntity_model
    const pair<float, float> &getPosition() const;

    // documentation in Enntity_model
    void setPosition(const float &posx, const float &posy);

private:
    pair<float, float> position; ///< position of the background
    float width; ///< width of the background
    float height; ///< height of the background
};


#endif//AP_DOODLE_GAME_BG_TILE_H
