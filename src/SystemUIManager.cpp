#include "SystemUIManager.hpp"

#include "Timer.hpp"

#include <stdint.h>

#include <chrono>
#include <string>

#include <godot_cpp/core/memory.hpp>
#include <godot_cpp/variant/string.hpp>

// ОСНОВНОЕ ТЕЛО
void SystemUIManager::_body()
{
    static Timer timer = Timer();

    static uint8_t score = 0U;

    if (m_startUpState == false)
    {
        score = 0U;

        timer.stop();

        return;
    }

    if (timer.isRunning() == false)
    {
        if (m_scoreLabel != nullptr)
        {
            static std::string score_str = "Score: " + std::to_string(score);

            m_scoreLabel->set_text(godot::String(score_str.c_str()));
        }

        //

        timer.start(std::chrono::seconds(5));
    }

    if (timer.isFinished() == true)
    {
        static bool state = true;

        if (state == true)
        {
            score++;
        }
        else
        {
            score--;
        }

        if (score == 10U)
        {
            state = false;
        }

        timer.reset();
    }
}

SystemUIManager::~SystemUIManager()
{
    if (m_scoreLabel != nullptr)
    {
        remove_child(m_scoreLabel);

        memdelete(m_scoreLabel);

        m_scoreLabel = nullptr;
    }
}

void SystemUIManager::startUp()
{
    m_startUpState = true;

    m_scoreLabel = memnew(godot::Label);

    m_scoreLabel->set_name("ScoreLabel");
    m_scoreLabel->set_text("Score: ");

    add_child(m_scoreLabel);
}

void SystemUIManager::shutDown()
{
    if (m_startUpState == true)
    {
        m_startUpState = false;
    }
}

void SystemUIManager::_bind_methods()
{
    godot::ClassDB::bind_method(godot::D_METHOD("startUp"), SystemUIManager::startUp);
    godot::ClassDB::bind_method(godot::D_METHOD("shutDown"), SystemUIManager::shutDown);
}

void SystemUIManager::_process(double delta)
{
    _body();
}

void SystemUIManager::_ready()
{
    startUp();
}

void SystemUIManager::_exit_tree()
{
    shutDown();
}
