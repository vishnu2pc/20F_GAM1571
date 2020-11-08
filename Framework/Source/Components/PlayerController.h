#pragma once

namespace fw {
    class Event;


    class PlayerController
    {
    public:
        enum class Button
        {
            Up = 1,
			Down = 2,
			Left = 4,
			Right = 8,
        	RESET = 16,
        	SHIFT = 32
        };
    	
    	PlayerController();
        virtual ~PlayerController();

        void StartFrame() { m_PastFlags = m_Flags; }
        void OnEvent(fw::Event* pEvent);

        bool IsButtonHeld(Button button) { return (m_Flags & (unsigned int)button) != 0; }
        bool IsNewButtonPress(Button button) { return !(m_Flags & (unsigned int)button) && (m_PastFlags & (unsigned int)button); }
        bool IsNewButtonRelease(Button button) { return (m_Flags & (unsigned int)button) && !(m_PastFlags & (unsigned int)button); }

    	
    protected:
        unsigned int m_Flags = 0;
        unsigned int m_PastFlags = 0;
    };
}