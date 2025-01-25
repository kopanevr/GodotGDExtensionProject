#pragma once

#include <chrono>

class Timer final
{
private:
    std::chrono::steady_clock::time_point m_cnt;
    std::chrono::steady_clock::time_point m_cmp;

    bool m_isRunning = false;
public:
    Timer() = default;
    ~Timer() = default;

    void start(const std::chrono::steady_clock::duration& duration);
    void stop();

    void reset();

    bool isFinished() const;
    bool isRunning() const;
};
