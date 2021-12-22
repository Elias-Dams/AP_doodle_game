
#ifndef AP_DOODLE_GAME_EM_JETPACK_H
#define AP_DOODLE_GAME_EM_JETPACK_H

#include "../EM_Bonus.h"

class Model::EM_Jetpack : public Model::EM_Bonus{
public:

    EM_Jetpack(float Width, float Height);

    const pair<float, float> &getPosition() const override;

    void setPosition(const float &x, const float &y) override;

    void update(float x, float y) override;

    float getWidth() const override;

    float getHeight() const override;

    string getType() const override;

    ~EM_Jetpack();

private:
    pair<float, float> position;
    float jetpack_width;
    float jetpack_height;
};


#endif //AP_DOODLE_GAME_EM_JETPACK_H
