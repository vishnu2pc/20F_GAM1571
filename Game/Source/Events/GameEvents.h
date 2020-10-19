#pragma once

class CollisionEvent : public fw::Event
{
public:
	enum class COLLISION_TYPE
	{
		ARENA,
		ENEMY,
		NONE
	};

	CollisionEvent(COLLISION_TYPE CollisionType) {}
	virtual ~CollisionEvent() {};

	static EVENT_TYPE GetStaticEventType() { return EVENT_TYPE::COLLISION; }
	virtual EVENT_TYPE GetType() override { return GetStaticEventType(); }

	COLLISION_TYPE GetCollisionType() {return m_COLLISION_TYPE;}
	
protected:
	COLLISION_TYPE m_COLLISION_TYPE;
	
};

class SpawnEnemyEvent:public fw::Event
{
public:
	SpawnEnemyEvent() {}
	~SpawnEnemyEvent() {}

	static EVENT_TYPE GetStaticEventType() { return EVENT_TYPE::SPAWN_ENEMY; }
	virtual EVENT_TYPE GetType() override { return GetStaticEventType(); }

protected:
	
};
