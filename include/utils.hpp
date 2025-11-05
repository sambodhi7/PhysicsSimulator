#include <chrono>
#pragma once
namespace utils {
    float getCurrentTimeInSeconds()
    {
        using Clock = std::chrono::high_resolution_clock;
        static auto startTime = Clock::now();

        auto now = Clock::now();
        std::chrono::duration<float> elapsed = now - startTime;
        return elapsed.count();
    }
}