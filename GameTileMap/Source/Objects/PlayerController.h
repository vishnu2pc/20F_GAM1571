#pragma once

class PlayerController
{
public:
    enum Mask
    {
        Up = 1,
        Down = 2,
        Left = 4,
        Right = 8,
    };

    PlayerController();
    virtual ~PlayerController();

    void StartFrame();
    void OnEvent(fw::Event* pEvent);

    bool IsHeld(Mask mask);
    bool WasNewlyPressed(Mask mask);
    bool WasNewlyReleased(Mask mask);

protected:
    unsigned int m_Flags = 0;
    unsigned int m_OldFlags = 0;
};
