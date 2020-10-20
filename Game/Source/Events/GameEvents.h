#pragma once

class SpawnEnemyEvent:public fw::Event
{
public:
	SpawnEnemyEvent() {}
	~SpawnEnemyEvent() {}

	static EVENT_TYPE GetStaticEventType() { return EVENT_TYPE::SPAWN_ENEMY; }
	virtual EVENT_TYPE GetType() override { return GetStaticEventType(); }

protected:
	
};
class DeleteEnemyEvent: public fw::Event
{
public:
	DeleteEnemyEvent() {}
	~DeleteEnemyEvent() {}

	static EVENT_TYPE GetStaticEventType() { return EVENT_TYPE::DELETE_ENEMY; }
	virtual EVENT_TYPE GetType() override { return GetStaticEventType(); }

protected:
};