
#ifndef AP_DOODLE_GAME_OBSERVER_H
#define AP_DOODLE_GAME_OBSERVER_H

#include <iostream>
#include <list>
#include <string>
#include <memory>
#include "IObserver.h"
#include "Subject.h"

class Observer: public IObserver{
public:

    Observer();

    virtual ~Observer();

    /// Updates the position of every entity
    virtual void UpdatePosition(const float &xpos, const float &ypos) override;

    /// Updates the score if a new max height is reached
    virtual void NewMaxheightReached(const float &ypos) override;

    /// Updates te score when a bonus is collected
    virtual void UpdateBonusScore(const int &points) override;

    /// Reduces the score
    virtual void UpdateReduceScore(const int &points) override;

    /// Resets the score
    virtual void Resetscore() override;

    /// Resets te texture of the player
    virtual void ResetTexture() override;

    /// Updates te texture of the player if a spring is collected
    virtual void UpdateMediumJump() override;

    /// Updates te texture of the player if a jetpack is collected
    virtual void UpdateHighJump() override;

    void RemoveMeFromTheList();


};


#endif //AP_DOODLE_GAME_OBSERVER_H
