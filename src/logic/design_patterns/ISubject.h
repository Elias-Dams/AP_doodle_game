
#ifndef AP_DOODLE_GAME_ISUBJECT_H
#define AP_DOODLE_GAME_ISUBJECT_H

#include <iostream>
#include <list>
#include <string>
#include <memory>
#include "IObserver.h"

// For this design pattern I used https://refactoring.guru/design-patterns/observer/cpp/example as a reference.

class ISubject {
public:

    /**
    * @brief Attach an observer to the subject
    *
    * This function attaches a pointer to an observer to the subject.
    * Because the subject has full control over the deletion of the observer this is a shared pointer.
    * e.g. if the platform disappears the view also gets destroyed.
    *
    * @param observer: pointer to an observer
    */
    virtual void Attach(std::shared_ptr<IObserver> observer) = 0;

    /**
    * @brief Detach an observer from the subject.
    *
    * This function removes a pointer to an observer from the list.
    *
    * @param observer: pointer to an observer.
    */
    virtual void Detach(std::shared_ptr<IObserver> observer) = 0;

    /**
    * @brief Gets the list of observers.
    *
    * This function gets the list of observers attached to this subject.
    *
    * @return a list of observers.
    */
    virtual const std::list<std::shared_ptr<IObserver>> getListObserver() const = 0;

    /**
    * @brief Notifies the observers to change the position.
    *
    * This function notifies the observers to change the position.
    *
    * @param xpos: position of the subject.
    * @param ypos: position of the subject.
    */
    virtual void NotifyPosition(float xpos, float ypos) = 0;

    /**
    * @brief Notifies the observers that a new maxheight is reached.
    *
    * This function notifies the observers that a new maxheight is reached so it can update the score.
    *
    * @param ypos: new height of the subject.
    */
    virtual void NewMaxHeigh(float ypos) = 0;

    /**
    * @brief Notifies the observers to reset
    *
    * This function notifies the observers to reset themselves.
    * (go back to the state they were in when they where first initialised)
    *
    */
    virtual void NotifyReset() = 0;

    /**
    * @brief Notifies the observers to change texture to normal
    *
    * This function notifies the observers to change their texture back to normal.
    * This texture is used for a normal jump height of up to 500 units
    *
    */
    virtual void NotifyNormal() = 0;

    /**
    * @brief Notifies the observers to change texture to medium
    *
    * This function notifies the observers to change their texture to the medium jump texture.
    * This texture is used for a medium jump height of up to 1500 units.
    *
    */
    virtual void NotifyMedium() = 0;

    /**
    * @brief Notifies the observers to change texture to high
    *
    * This function notifies the observers to change their texture to the high jump texture.
    * This texture is used for a high jump of more than 1500 units.
    *
    */
    virtual void NotifyHigh() = 0;

    /**
    * @brief Notifies the observers to increase the score
    *
    * This function notifies the observers to increase the score.
    *
    * @param points: that need to be added from the score
    */
    virtual void NotifyIncreaseScore(const int points) = 0;

    /**
    * @brief Notifies the observers to decrease the score
    *
    * This function notifies the observers to decrease the score
    *
    * @param points: that need to be subtracted from the score
    */
    virtual void NotifyDecreaseScore(const int points) = 0;

    virtual ~ISubject(){};
};


#endif //AP_DOODLE_GAME_ISUBJECT_H
