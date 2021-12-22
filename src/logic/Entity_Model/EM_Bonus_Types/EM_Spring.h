
#ifndef AP_DOODLE_GAME_EM_SPRING_H
#define AP_DOODLE_GAME_EM_SPRING_H

#include "../EM_Bonus.h"

class Model::EM_Spring : public Model::EM_Bonus{
public:

    EM_Spring(float Width, float Height);

    const pair<float, float> &getPosition() const override;

    void setPosition(const float &x, const float &y) override;

    void update(float x, float y) override;

    float getWidth() const override;

    float getHeight() const override;

    string getType() const override;

    ~EM_Spring();

private:
    pair<float, float> position;
    float spring_width;
    float spring_height;
};


#endif //AP_DOODLE_GAME_EM_SPRING_H
