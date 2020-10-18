#pragma once
#include "../../Game/Source/Constants.h"

namespace fw {

    class Event
    {
    public:
        Event();
        virtual ~Event();

        virtual EVENT_TYPE GetType() = 0;

    protected:
    };

    class InputEvent : public Event
    {
    public:
        enum class DeviceType
        {
            Keyboard,
        };

        enum class DeviceState
        {
            Pressed,
            Released,
        };

        InputEvent(DeviceType deviceType, DeviceState deviceState, unsigned int keyCode)
        {
            m_DeviceType = deviceType;
            m_DeviceState = deviceState;
            m_KeyCode = keyCode;
        }
        virtual ~InputEvent() {}

        EVENT_TYPE GetStaticEventType() { return EVENT_TYPE::INPUT_EVENT; }
        virtual EVENT_TYPE GetType() override { return GetStaticEventType(); }

        DeviceType GetDeviceType() { return m_DeviceType; }
        DeviceState GetDeviceState() { return m_DeviceState; }
        unsigned int GetKeyCode() { return m_KeyCode; }

    protected:
        DeviceType m_DeviceType;
        DeviceState m_DeviceState;
        unsigned int m_KeyCode;
    };

} // namespace fw