#pragma once

#include <godot_cpp/classes/control.hpp>
#include <godot_cpp/classes/label.hpp>

class SystemUIManager : public godot::Control
{
    GDCLASS(SystemUIManager, godot::Control)

private:
    bool m_startUpState = false;

    godot::Label* m_scoreLabel = nullptr;
    godot::Label* m_healthLabel = nullptr;

    // ОСНОВНОЕ ТЕЛО
    void _body();
protected:
    static void _bind_methods();
public:
    SystemUIManager() = default;
    ~SystemUIManager();

    void startUp();
    void shutDown();

    void _process([[maybe_unused]] double delta);

    void _ready();
    void _exit_tree();
};
