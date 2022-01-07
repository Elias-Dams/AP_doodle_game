
#ifndef AP_DOODLE_GAME_RANDOM_H
#define AP_DOODLE_GAME_RANDOM_H

#include <iostream>
#include <list>
#include <random>
#include <string>
#include <vector>
#include <memory>

// I used https://refactoring.guru/design-patterns/singleton/cpp/example as inspiration for the singleton design pattern

using namespace std;

/**
 * @class Random
 *
 * @brief Generates random numbers.
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
    * @brief Creates unique instance of Random.
    *
    * This function creates unique instance of Random.
    *
    * @return pointer to the Random.
    */
    static shared_ptr<Random> GetInstance();

    /**
    * @brief Generates a float number between a given range.
    *
    * This function generates a float number between a given range.
    *
    * @param min: minimum of the range.
    * @param max: maximum of the range.
    * @return random float number.
    */
    float generate_between(const float min, const float max);

    /**
    * @brief generates a float number between a given range whit an exception range.
    *
    * This function generates a float number between a given range whit an exception range.
    * This means it wil generate a number between the given range but outside the exeption range.
    *
    * @param min: minimum of the range.
    * @param max: maximum of the range.
    * @param exeptionmin: min of the exception range.
    * @param exeptionmax: max of the exception range.
    * @return random float number.
    */
    float generate_between_exeption(const float min, const float max, const float exeptionmin,  const float exeptionmax);

    Random();

    virtual ~Random();
};


#endif//AP_DOODLE_GAME_RANDOM_H
