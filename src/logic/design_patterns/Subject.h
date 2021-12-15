
#ifndef AP_DOODLE_GAME_SUBJECT_H
#define AP_DOODLE_GAME_SUBJECT_H

#include <iostream>
#include <list>
#include <string>
#include <memory>
#include "ISubject.h"


class Subject : public ISubject{
public:
    virtual ~Subject();

    /**
     * The subscription management methods.
     */
    void Attach(std::shared_ptr<IObserver> observer) override;
    void Detach(std::shared_ptr<IObserver> observer) override;

    /// notifies all entity's to change their position
    void NotifyPosition(float xpos, float ypos) override;

    /// notifies the score if a new max height has been reached
    void NewMaxHeigh(float ypos) override;

    /// notifies the entity's who have to reset
    void NotifyReset() override;

private:
    std::list<std::shared_ptr<IObserver>> list_observer_;

};




#endif //AP_DOODLE_GAME_SUBJECT_H
