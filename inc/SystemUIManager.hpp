#pragma once

#include <godot_cpp/classes/control.hpp>
#include <godot_cpp/classes/label.hpp>

class SystemUIManager final : public godot::Control
{
    GDCLASS(SystemUIManager, godot::Control)

private:
    bool m_startUpState = false;

    godot::Label* m_scoreLabel = nullptr;

    // ОСНОВНОЕ ТЕЛО
    void _body();
public:
    SystemUIManager() = default;
    ~SystemUIManager();

    void startUp();
    void shutDown();

    static void _bind_methods();

    void _process(double delta);

    void _ready();
    void _exit_tree();
};
