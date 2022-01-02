
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

    /// Notifies all entity's to change their position
    void NotifyPosition(float xpos, float ypos) override;

    /// Notifies the score if a new max height has been reached
    void NewMaxHeigh(float ypos) override;

    /// Notifies the entity's who have to reset
    void NotifyReset() override;

    /// Notifies the view of the player to reset it als the normal texture
    void NotifyNormal() override;

    /// Notifies the view of the player if a spring is collected
    void NotifyMedium() override;

    /// Notifies the view of the player if a jetpack is collected
    void NotifyHigh() override;

    /// Notifies the observers to increase the score
    void NotifyIncreaseScore(const int &points) override;

    /// Notifies the observers to decrease the score
    void NotifyDecreaseScore(const int &points) override;

    const std::list<std::shared_ptr<IObserver>> getListObserver() const;

private:
    /// Shared pointer because the Subject gets full control over the observer
    std::list<std::shared_ptr<IObserver>> list_observer_;

};

#endif //AP_DOODLE_GAME_SUBJECT_H
