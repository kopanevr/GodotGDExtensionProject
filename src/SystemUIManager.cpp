#include "SystemUIManager.hpp"

SystemUIManager::SystemUIManager()
{
}

void SystemUIManager::_bind_methods()
{
}

void _bind_methods()
{
}

void SystemUIManager::startUp()
{
    m_startUpState = true;
}

void SystemUIManager::shutDown()
{
    if (m_startUpState == true)
    {
        m_startUpState = false;
    }
}
