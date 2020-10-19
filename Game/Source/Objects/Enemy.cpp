#include "GamePCH.h"

#include "Objects/Enemy.h"

#include "Game.h"


Enemy::Enemy(fw::Materials* pMaterials, fw::PhysicsController* pPhysicsController, fw::GameCore* pGameCore) :
	GameObject(pPhysicsController, pGameCore)
{
	m_pMaterials = pMaterials;
	
	PlayerPosition = static_cast<Game*>(m_pGameCore)->GetPlayerPosition();
	DistanceFromPlayer = m_pPhysicsController->GetPosition() - PlayerPosition - vec2(5.0f,5.0f);
	DirectionToPlayer = DistanceFromPlayer.GetNormalizedVector();
}

Enemy::~Enemy()
{

}


void Enemy::Update(float deltaTime)
{
	vec2 OldPos = m_pPhysicsController->GetPosition();
	vec2 NewPos = OldPos - DirectionToPlayer * m_pPhysicsController->GetMaxVelocity() * deltaTime ;
	m_pPhysicsController->SetPosition(NewPos);
}

void Enemy::Draw()
{
	m_pMaterials->Draw(m_pPhysicsController->GetPosition(), m_pPhysicsController->GetRadius());
}

