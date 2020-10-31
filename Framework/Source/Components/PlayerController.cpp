#include "FrameworkPCH.h"

#include "PlayerController.h"

#include "EventSystem/Event.h"

namespace fw {

    PlayerController::PlayerController()
    {
    }

    PlayerController::~PlayerController()
    {
    }

    void PlayerController::OnEvent(fw::Event* pEvent)
    {
        fw::InputEvent* pInputEvent = static_cast<fw::InputEvent*>(pEvent);

        if (pInputEvent->GetDeviceType() == fw::InputEvent::DeviceType::Keyboard)
        {
            if (pInputEvent->GetDeviceState() == fw::InputEvent::DeviceState::Pressed)
            {
                if (pInputEvent->GetKeyCode() == 'W') { m_Flags = m_Flags| Up; }
                if (pInputEvent->GetKeyCode() == 'S') { m_Flags = m_Flags| Down;}
                if (pInputEvent->GetKeyCode() == 'A') { m_Flags = m_Flags| Left;}
                if (pInputEvent->GetKeyCode() == 'D') { m_Flags = m_Flags| Right; }
            }

            if (pInputEvent->GetDeviceState() == fw::InputEvent::DeviceState::Released)
            {
                if (pInputEvent->GetKeyCode() == 'W') { m_Flags = m_Flags & ~Up; }
                if (pInputEvent->GetKeyCode() == 'S') { m_Flags = m_Flags & ~Down; }
                if (pInputEvent->GetKeyCode() == 'A') { m_Flags = m_Flags & ~Left; }
                if (pInputEvent->GetKeyCode() == 'D') { m_Flags = m_Flags & ~Right; }
            }
        }

    }
}