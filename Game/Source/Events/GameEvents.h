#pragma once
class SpawnPlayer : public fw::Event
{
    class Player;
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

class SpawnEnemy : public fw::Event
{
    class Enemy;
public:
    SpawnEnemy(Enemy* pEnemy)
    {
        m_pEnemy = pEnemy;
    }
    virtual ~SpawnEnemy() {}

    static EVENT_TYPE GetStaticEventType() { return EVENT_TYPE::SPAWN_ENEMY; }
    virtual EVENT_TYPE GetType() override { return GetStaticEventType(); }

    Enemy* GetEnemy() { return m_pEnemy; }

protected:
    Enemy* m_pEnemy;
};

