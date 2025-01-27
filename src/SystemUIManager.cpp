#include "SystemUIManager.hpp"

#include "Timer.hpp"

#include <chrono>
#include <string>
#include <cassert>

#include <godot_cpp/core/memory.hpp>
#include <godot_cpp/variant/string.hpp>
#include <godot_cpp/core/class_db.hpp>

#define DURATION_0  (5)
#define DURATION_1  (1)

// ОСНОВНОЕ ТЕЛО
void SystemUIManager::_body()
{
    static Timer timer_0 = Timer();
    static Timer timer_1 = Timer();

    static unsigned score = 0U;
    static unsigned health = 0U;

    static bool state_0 = true;
    static bool state_1 = true;

    if (m_startUpState == false)
    {
        score = 0U;
        health = 0U;

        state_0 = true;
        state_1 = true;

        timer_0.stop();
        timer_1.stop();

        return;
    }

    if (timer_0.isRunning() == false)
    {
        assert(m_scoreLabel != nullptr);

        if (m_scoreLabel != nullptr)
        {
            static std::string score_str = "Score: " + std::to_string(score);

            m_scoreLabel->set_text(godot::String(score_str.c_str()));

            //

            timer_0.start(std::chrono::seconds(DURATION_0));
        }

    }

    if (timer_1.isRunning() == false)
    {
        assert(m_healthLabel != nullptr);

        if (m_healthLabel != nullptr)
        {
            static std::string health_str = "Health: " + std::to_string(health);

            m_healthLabel->set_text(godot::String(health_str.c_str()));

            //

            timer_1.start(std::chrono::seconds(DURATION_1));
        }
    }

    if (timer_0.isFinished() == true)
    {
        if (state_0 == true)
        {
            score++;
        }
        else
        {
            score--;
        }

        if (score >= 10U)
        {
            state_0 = false;
        }
        else if (score <= 0U)
        {
            state_0 = true;
        }

        timer_0.reset();
    }

    if (timer_1.isFinished() == true)
    {
        if (state_1 == true)
        {
            health += 10;
        }
        else
        {
            health -= 10;
        }

        if (health >= 100U)
        {
            state_1 = false;
        }
        else if (health <= 0U)
        {
            state_1 = true;
        }

        timer_1.reset();
    }
}

void SystemUIManager::_bind_methods()
{
    godot::ClassDB::bind_method(godot::D_METHOD("startUp"), SystemUIManager::startUp);
    godot::ClassDB::bind_method(godot::D_METHOD("shutDown"), SystemUIManager::shutDown);
}

SystemUIManager::~SystemUIManager()
{
    assert(m_scoreLabel != nullptr);
    assert(m_healthLabel != nullptr);

    if (m_scoreLabel != nullptr && m_healthLabel != nullptr)
    {
        m_scoreLabel = nullptr;
        m_healthLabel = nullptr;
    }
}

void SystemUIManager::startUp()
{
    m_scoreLabel = memnew(godot::Label);
    m_healthLabel = memnew(godot::Label);

    assert(m_scoreLabel != nullptr);
    assert(m_healthLabel != nullptr);

    if (m_scoreLabel != nullptr && m_healthLabel != nullptr)
    {
        m_scoreLabel->set_name("ScoreLabel");
        m_scoreLabel->set_text("Score: ");
        m_scoreLabel->set_uppercase(true);
        m_scoreLabel->set_position(godot::Vector2(20, 10));

        m_healthLabel->set_name("HealthLabel");
        m_healthLabel->set_text("Health: ");
        m_healthLabel->set_uppercase(true);
        m_healthLabel->set_position(godot::Vector2(20, 50));

        add_child(m_scoreLabel);
        add_child(m_healthLabel);

        m_startUpState = true;
    }
}

void SystemUIManager::shutDown()
{
    if (m_startUpState == true)
    {
        assert(m_scoreLabel != nullptr);
        assert(m_healthLabel != nullptr);

        if (m_scoreLabel != nullptr && m_healthLabel != nullptr)
        {
            remove_child(m_scoreLabel);
            remove_child(m_healthLabel);

            memdelete(m_scoreLabel);
            memdelete(m_healthLabel);

            m_startUpState = false;
        }
    }
}

void SystemUIManager::_process([[maybe_unused]] double delta)
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
