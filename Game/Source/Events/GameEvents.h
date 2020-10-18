#pragma once

class SpawnPlayer : public fw::Event
{
public:
    SpawnPlayer(Player* pPlayer)
    {
        m_pPlayer = pPlayer;
    }
    virtual ~SpawnPlayer() {}

    static EVENT_TYPE GetStaticEventType() { return EVENT_TYPE::SPAWN_PLAYER; }
    virtual EVENT_TYPE GetType() override { return GetStaticEventType(); }

    Player* GetPlayer() { return m_pPlayer; }

protected:
    Player* m_pPlayer;
};