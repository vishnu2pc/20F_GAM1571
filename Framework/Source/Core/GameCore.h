#pragma once
#include "Math/Vector.h"


enum class ENEMY_BEHAVIOUR;

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

    virtual void StartFrame(float deltaTime);
    virtual void OnEvent(Event* pEvent) = 0;
    virtual void Update(float deltaTime) = 0; 
    virtual void Draw() = 0;
		
    FWCore* GetFramework() { return m_pFramework; }
    EventManager* GetEventManager() { return m_pEventManager; }
    PlayerController* GetPlayerController() { return m_pPlayerController; }
    
    	
    float GetArenaRadius() { return m_ArenaRadiusControl; }
    vec2 GetArenaPosition() { return m_ArenaPosition; }
    vec2 GetPlayerPosition() { return m_PlayerPosition; }
    float GetPlayerRadius() { return m_PlayerRadiusControl; }
    float GetPlayerSpeed() { return m_PlayerVelocity; }
    float GetEnemyRadius() { return m_EnemyRadiusControl; }
    float GetEnemySpeed() { return m_EnemySpeed; }
    vec4 GetPlayerColor() { return PlayerInnerColor; }
    vec4 GetArenaColor() { return ArenaInnerColor; }
    vec4 GetEnemyColor() { return EnemyColor; }

    void SetArenaRadius(float ArenaRadius) { m_ArenaRadiusControl = ArenaRadius; }
    void SetArenaPosition(vec2 ArenaPosition) {  m_ArenaPosition = ArenaPosition; }
    void SetPlayerPosition(vec2 PlayerPosition) {  m_PlayerPosition = PlayerPosition; }
    void SetPlayerRadius(float PlayerRadius) { m_PlayerRadiusControl = PlayerRadius; }
    void SetPlayerSpeed(float PlayerVelocity) {  m_PlayerVelocity = PlayerVelocity; }
    void SetEnemyRadius(float EnemyRadiusControl) {  m_EnemyRadiusControl = EnemyRadiusControl; }
    void SetEnemySpeed(float EnemySpeed) {  m_EnemySpeed = EnemySpeed; }
    void SetPlayerColor(vec4 PlayerColor) {  PlayerInnerColor = PlayerColor; }
    void SetArenaColor(vec4 ArenaColor) {  ArenaInnerColor = ArenaColor; }
    void SetEnemyColor(vec4 Enemy_Color) {  EnemyColor = Enemy_Color; }

    void SetLevelDuration(float LevelDuration) { m_LevelTimer = LevelDuration; }
    void SetEnemySpawnDuration(float LevelDuration) { m_EnemyTimer = LevelDuration; }

    void SetEnemyBehaviour(ENEMY_BEHAVIOUR enemy_behaviour) { m_Enemy_Behaviour = enemy_behaviour; }
    	
protected:
    FWCore* m_pFramework = nullptr;
    EventManager* m_pEventManager = nullptr;
    
    ENEMY_BEHAVIOUR m_Enemy_Behaviour;
    vec2 m_ArenaPosition;
    vec2 m_PlayerPosition;
    float m_PlayerVelocity = 5;
    float m_EnemySpeed = 5.0f;
    float m_EnemyRadiusControl = 0.2f;
    float m_ArenaRadiusControl = 4.0f;
    float m_PlayerRadiusControl = 0.4f;

    PlayerController* m_pPlayerController;

    vec4 PlayerInnerColor = vec4::Red();
    vec4 ArenaInnerColor = vec4::White();
    vec4 EnemyColor = vec4::LightBlue();

    float m_EnemyTimer = 1;
    float m_LevelTimer = 10;

  
};

} // namespace fw
