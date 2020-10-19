#pragma once

namespace fw {
	class FWCore;
    class Event;
    class EventManager;

    class GameCore
{    
public:
    GameCore(FWCore* pFramework);
    virtual ~GameCore();

    virtual void OnEvent(Event* pEvent) = 0;
    virtual void Update(float deltaTime) = 0; 
    virtual void Draw() = 0;
		
    FWCore* GetFramework() { return m_pFramework; }
    EventManager* GetEventManager() { return m_pEventManager; }
    float GetArenaRadius() { return m_ArenaRadius; }
		
protected:
    FWCore* m_pFramework = nullptr;
    EventManager* m_pEventManager = nullptr;
    float m_ArenaRadius = 0;
};

} // namespace fw
