
#ifndef AP_DOODLE_GAME_STOPWATCH_H
#define AP_DOODLE_GAME_STOPWATCH_H

#include <chrono>
#include <iostream>
#include <list>
#include <memory>
#include <string>

using namespace std;

// I used https://refactoring.guru/design-patterns/singleton/cpp/example as inspiration for the singleton design pattern

class Stopwatch {

private:
    static shared_ptr<Stopwatch> singleton_; ///< pointer to the Stopwatch

    std::chrono::steady_clock::time_point now; ///< current time


public:
    //Singletons should not be cloneable.
    Stopwatch(Stopwatch &other) = delete;

    //Singletons should not be assignable.
    void operator=(const Stopwatch &) = delete;

    /**
    * @brief Creates unique instance of Stopwatch.
    *
    * This function creates unique instance of Stopwatch.
    *
    * @return pointer to the stopwatch.
    */
    static shared_ptr<Stopwatch> GetInstance();

    /**
    * @brief Creates unique instance of Stopwatch.
    *
    * This function marks the time.
    * It also calculates the differance between the prev mark and now.
    * It is returned under the name delta time.
    *
    * @return delta time
    */
    float mark_time();

    Stopwatch();

    virtual ~Stopwatch();
};


#endif//AP_DOODLE_GAME_STOPWATCH_H
