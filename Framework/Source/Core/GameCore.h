#pragma once
#include "Math/Vector.h"

namespace fw {
	class PlayerController;
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
    vec2 GetArenaPosition() { return m_ArenaPosition; }
    vec2 GetPlayerPosition() { return m_PlayerPosition; }
    PlayerController* GetPlayerController() { return m_pPlayerController; }
    
		
protected:
    FWCore* m_pFramework = nullptr;
    EventManager* m_pEventManager = nullptr;
    float m_ArenaRadius = 0;
    vec2 m_ArenaPosition;
    vec2 m_PlayerPosition;
    PlayerController* m_pPlayerController;
    	
};

} // namespace fw
