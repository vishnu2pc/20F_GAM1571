#pragma once

namespace fw {
    class Event;


    class PlayerController
    {
    public:
        enum Button
        {
            Up = 1,
			Down = 2,
			Left = 4,
			Right = 8
        };
    	
    	PlayerController();
        virtual ~PlayerController();

        void OnEvent(fw::Event* pEvent);

        bool IsButtonHeld(Button button) { return (m_Flags & button) != 0; }
		

    protected:
        unsigned int m_Flags = 0;
    };
}