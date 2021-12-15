
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

    Observer(Subject &subject);

    virtual ~Observer();

    /// updates the position of every entity
    virtual void UpdatePosition(float xpos, float ypos) override;

    /// updates the score if a new max height is reached
    virtual void NewMaxheightReached(float ypos) override;

    /// resets the score
    virtual void Resetscore() override;

    void RemoveMeFromTheList();


private:
    Subject &subject_;

};


#endif //AP_DOODLE_GAME_OBSERVER_H
