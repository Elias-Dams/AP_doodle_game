
#ifndef AP_DOODLE_GAME_SCORE_H
#define AP_DOODLE_GAME_SCORE_H

#include "Entity_Model/Entity_Model.h"
#include "design_patterns/Observer.h"
#include <iostream>
#include <list>
#include <string>


using namespace std;

/**
 * @class Score
 *
 * @brief Keep track of the Player's Score.
 */
class Score : public Observer {
public:
    /**
     * Score constructor.
     * constructs the Score.
     */
    Score();

    /**
    * @brief updates the score.
    *
    * This function updates the score if a new maximum height is reached.
    *
    * @param y: position on the y axis.
    */
    void NewMaxheightReached(const float y) override;

    /**
    * @brief updates the score.
    *
    * This function updates the score if a certain bonus is collected.
    *
    * @param points: that need to be added to the score.
    */
    void UpdateBonusScore(const int points) override;

    /**
    * @brief reduces the score.
    *
    * This function reduces the score when jumped on the same platform.
    *
    * @param points: that need to be subtracted from the score.
    */
    void UpdateReduceScore(const int points) override;

    /**
    * @brief fully resets the score.
    *
    * This function resets the score to the state it was in when it was first initialized.
    *
    */
    void Resetscore() override;

    /**
    * @brief get the score.
    *
    * This function is used to get the score of the player.
    *
    * @return the score of the player.
    */
    int getscore() const;

    virtual ~Score();

private:
    int score;
};


#endif//AP_DOODLE_GAME_SCORE_H
