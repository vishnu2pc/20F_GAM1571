#include "GamePCH.h"

#include "Objects/Enemy.h"

#include "Events/GameEvents.h"

Enemy::Enemy(fw::Materials* pMaterials, fw::PhysicsController* pPhysicsController, fw::GameCore* pGameCore) :
	GameObject(pPhysicsController, pGameCore)
{
	m_pMaterials = pMaterials;
	
	InitialPlayerPosition = m_pGameCore->GetPlayerPosition();
	DistanceFromPlayer = m_pPhysicsController->GetPosition() - InitialPlayerPosition;
	DirectionToPlayer = DistanceFromPlayer.GetNormalizedVector();
}

Enemy::~Enemy()
{

}


void Enemy::Update(float deltaTime)
{

	vec2 OldPos = m_pPhysicsController->GetPosition();
	vec2 NewPos = OldPos - DirectionToPlayer * m_pPhysicsController->GetMaxVelocity() * deltaTime;
	
	m_pPhysicsController->SetPosition(NewPos);
	vec2 ArenaPosition = m_pGameCore->GetArenaPosition();
	float ArenaRadius = m_pGameCore->GetArenaRadius();

	if (NewPos.Distance(ArenaPosition) > ArenaRadius )
	{
		DeleteEnemyEvent* pEvent = new DeleteEnemyEvent(this);
		m_pGameCore->GetEventManager()->AddEvent(pEvent);
	}

	vec2 CurrentPlayerPosition = m_pGameCore->GetPlayerPosition();
	float PlayerRadius = m_pGameCore->GetPlayerRadius();
	
	if (m_pPhysicsController->GetPosition().Distance(CurrentPlayerPosition) < PlayerRadius + m_pPhysicsController->GetRadius())
	{
		LoseEvent* pEvent2 = new LoseEvent();
		m_pGameCore->GetEventManager()->AddEvent(pEvent2);
	}
}

void Enemy::Draw()
{
	m_pMaterials->Draw(m_pPhysicsController->GetPosition(), m_pPhysicsController->GetRadius());
}

