#pragma once

#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/core/class_db.hpp>
#include <gen/include/godot_cpp/classes/label.hpp>

class SystemUIManager final : public godot::Node
{
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
