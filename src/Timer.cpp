#include "Timer.hpp"

void Timer::start(const std::chrono::steady_clock::duration& duration)
{
    m_cnt = std::chrono::steady_clock::now();

    m_cmp = m_cnt + duration;

    m_isRunning = true;
}

void Timer::stop()
{
    m_isRunning = false;
}

void Timer::reset()
{
    m_isRunning = false;
}

bool Timer::isFinished() const
{
    if (m_isRunning == false)
    {
        return false;
    }

    return std::chrono::steady_clock::now() >= m_cmp;
}

bool Timer::isRunning() const
{
    return m_isRunning;
}
