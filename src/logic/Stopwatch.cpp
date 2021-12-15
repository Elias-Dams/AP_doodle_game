
#include "Stopwatch.h"

Stopwatch::Stopwatch(){
    now = std::chrono::steady_clock::now();
}

shared_ptr<Stopwatch> Stopwatch::singleton_= nullptr;

shared_ptr<Stopwatch> Stopwatch::GetInstance() {
    if(singleton_ == nullptr){
        singleton_ = make_shared<Stopwatch>();
    }
    return singleton_;
}

float Stopwatch::mark_time(){
    std::chrono::steady_clock::time_point old_time_point = now;
    now = std::chrono::steady_clock::now();
    const std::chrono::duration<float> frameTime = now - old_time_point;
    return frameTime.count();
}
