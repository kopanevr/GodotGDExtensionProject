#pragma once

class SystemUIManager
{
private:
    bool m_startUpState = false;
public:
    SystemUIManager();
    ~SystemUIManager() = default;

    void startUp();
    void shutDown();

    static void _bind_methods();

    void _process(double delta);
};
