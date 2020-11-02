#pragma once
class Enemy;
class SpawnEnemyEvent :public fw::Event
{
public:
    SpawnEnemyEvent() {}
    ~SpawnEnemyEvent() {}

    static EVENT_TYPE GetStaticEventType() { return EVENT_TYPE::SPAWN_ENEMY; }
    virtual EVENT_TYPE GetType() override { return GetStaticEventType(); }

protected:

};

class DeleteEnemyEvent : public fw::Event
{
    
public:
    DeleteEnemyEvent(Enemy* pEnemy)
    {
        m_pEnemy = pEnemy;
    }
    virtual ~DeleteEnemyEvent() {}

    static EVENT_TYPE GetStaticEventType() { return EVENT_TYPE::DELETE_ENEMY; }
    virtual EVENT_TYPE GetType() override { return GetStaticEventType(); }

    Enemy* GetEnemy() { return m_pEnemy; }

protected:
    Enemy* m_pEnemy;
};
class NextLevelEvent : public fw::Event
{
public:
    NextLevelEvent() {}
    ~NextLevelEvent() {}

    static EVENT_TYPE GetStaticEventType() { return EVENT_TYPE::NEXT_LEVEL; }
    virtual EVENT_TYPE GetType() override { return GetStaticEventType(); }
	
protected:
};

class WinEvent : public fw::Event
{
public:
    WinEvent() {}
    ~WinEvent() {}

    static EVENT_TYPE GetStaticEventType() { return EVENT_TYPE::WIN; }
    virtual EVENT_TYPE GetType() override { return GetStaticEventType(); }

protected:
};
