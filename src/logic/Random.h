
#ifndef AP_DOODLE_GAME_RANDOM_H
#define AP_DOODLE_GAME_RANDOM_H

#include <iostream>
#include <list>
#include <random>
#include <string>
#include <vector>
#include <memory>

// i used https://refactoring.guru/design-patterns/singleton/cpp/example as inspiration for the singleton design pattern

using namespace std;

/**
 * @class Random
 *
 * @brief generates random numbers.
 */
class Random {

private:

    static shared_ptr<Random> singleton_;  ///< pointer to Random


public:
    //Singletons should not be cloneable.
    Random(Random &other) = delete;

    //Singletons should not be assignable.
    void operator=(const Random &) = delete;

    /**
    * @brief creates unique instance of Random.
    *
    * This function creates unique instance of Random.
    *
    * @return pointer to the Random.
    */
    static shared_ptr<Random> GetInstance();

    /**
    * @brief generates a float number between a given range.
    *
    * This function generates a float number between a given range.
    *
    * @param min: minimum of the range.
    * @param max: mqximum of the range.
    * @return random float number.
    */
    float generate_between(const float &min, const float &max);

    Random();

    virtual ~Random();
};


#endif//AP_DOODLE_GAME_RANDOM_H
