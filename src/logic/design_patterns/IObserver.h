
#ifndef AP_DOODLE_GAME_IOBSERVER_H
#define AP_DOODLE_GAME_IOBSERVER_H

#include <iostream>
#include <list>
#include <string>
#include <memory>

// for this design pattern i user https://refactoring.guru/design-patterns/observer/cpp/example as a reference

class IObserver {
public:

    /**
    * @brief Updates the position of the observers.
    *
    * This function updates the position of the observers.
    *
    * @param xpos: position of the subject.
    * @param ypos: position of the subject.
    */
    virtual void UpdatePosition(const float &xpos, const float &ypos) = 0;

    /**
    * @brief Updates the observers because a new maxheight is reached.
    *
    * This function updates the observers because a new maxheight is reached.
    *
    * @param ypos: new height of the subject.
    */
    virtual void NewMaxheightReached(const float &ypos) = 0;

    /**
    * @brief Updates the observers to reset
    *
    * This function updates the observers to reset themselves.
    * (go back to the state you were in, when you where first initialised)
    *
    */
    virtual void Resetscore() = 0;

    /**
    * @brief Resets the observers texture to normal
    *
    * This function resets the observers texture back to normal.
    * This texture is used for a normal jump height of up to 500 units.
    *
    */
    virtual void ResetTexture() = 0;

    /**
    * @brief Updates the observers texture to medium
    *
    * This function updates the observers texture to the medium jump texture.
    * This texture is used for a medium jump height of up to 1500 units.
    *
    */
    virtual void UpdateMediumJump() = 0;

    /**
    * @brief Updates the observers texture to high
    *
    * This function updates the observers texture to the high jump texture.
    * This texture is used for a high jump of more than 1500 units.
    *
    */
    virtual void UpdateHighJump() = 0;

    /**
    * @brief Updates te score when a bonus is collected
    *
    * This function updates te score when a bonus is collected
    *
    * @param points: that need to be added to the score
    */
    virtual void UpdateBonusScore(const int &points) = 0;

    /**
    * @brief Reduces the score
    *
    * This function reduces the score when jumped on the same platform
    *
    * @param points: that need to be subtracted from the score
    */
    virtual void UpdateReduceScore(const int &points) = 0;

    virtual ~IObserver(){};
};


#endif //AP_DOODLE_GAME_IOBSERVER_H
