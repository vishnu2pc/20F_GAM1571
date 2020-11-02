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

    virtual void StartFrame(float deltaTime);
    virtual void OnEvent(Event* pEvent) = 0;
    virtual void Update(float deltaTime) = 0; 
    virtual void Draw() = 0;
		
    FWCore* GetFramework() { return m_pFramework; }
    EventManager* GetEventManager() { return m_pEventManager; }
    PlayerController* GetPlayerController() { return m_pPlayerController; }
    	
    float GetArenaRadius() { return m_ArenaRadius; }
    vec2 GetArenaPosition() { return m_ArenaPosition; }
    vec2 GetPlayerPosition() { return m_PlayerPosition; }
    float GetPlayerRadius() { return m_PlayerRadius; }
    float GetPlayerSpeed() { return m_PlayerVelocity; }
    float GetEnemyRadius() { return m_EnemyRadiusControl; }
    float GetEnemySpeed() { return m_EnemySpeed; }
    vec4 GetPlayerColor() { return PlayerInnerColor; }
    vec4 GetArenaColor() { return ArenaInnerColor; }
    vec4 GetEnemyColor() { return EnemyColor; }

    void SetArenaRadius(float ArenaRadius) {  m_ArenaRadius = ArenaRadius; }
    void SetArenaPosition(vec2 ArenaPosition) {  m_ArenaPosition = ArenaPosition; }
    void SetPlayerPosition(vec2 PlayerPosition) {  m_PlayerPosition = PlayerPosition; }
    void SetPlayerRadius(float PlayerRadius) {  m_PlayerRadius = PlayerRadius; }
    void SetPlayerSpeed(float PlayerVelocity) {  m_PlayerVelocity = PlayerVelocity; }
    void SetEnemyRadius(float EnemyRadiusControl) {  m_EnemyRadiusControl = EnemyRadiusControl; }
    void SetEnemySpeed(float EnemySpeed) {  m_EnemySpeed = EnemySpeed; }
    void SetPlayerColor(vec4 PlayerColor) {  PlayerInnerColor = PlayerColor; }
    void SetArenaColor(vec4 ArenaColor) {  ArenaInnerColor = ArenaColor; }
    void SetEnemyColor(vec4 Enemy_Color) {  EnemyColor = Enemy_Color; }

    void SetLevelDuration(float LevelDuration) { m_LevelTimer = LevelDuration; }
    void SetEnemySpawnDuration(float LevelDuration) { m_EnemyTimer = LevelDuration; }

 
protected:
    FWCore* m_pFramework = nullptr;
    EventManager* m_pEventManager = nullptr;
    float m_ArenaRadius;
    float m_PlayerRadius;
    vec2 m_ArenaPosition;
    vec2 m_PlayerPosition;
    float m_PlayerVelocity = 5;
    float m_EnemySpeed = 5.0f;
    float m_EnemyRadiusControl = 0.2f;
    PlayerController* m_pPlayerController;

    vec4 PlayerInnerColor = vec4::Red();
    vec4 ArenaInnerColor = vec4::White();
    vec4 EnemyColor = vec4::LightBlue();

    float m_EnemyTimer = 1;
    float m_LevelTimer = 10;

  
};

} // namespace fw
