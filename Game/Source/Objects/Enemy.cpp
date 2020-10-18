#include "GamePCH.h"

#include "Objects/Enemy.h"


Enemy::Enemy(fw::Materials* pMaterials, fw::PhysicsController* pPhysicsController, fw::GameCore* pGameCore):
	GameObject(pPhysicsController, pGameCore)
{
	m_pMaterials = pMaterials;
	
}

Enemy::~Enemy()
{
	
}


void Enemy::Update(float deltaTime)
{
	
}

void Enemy::Draw()
{
	m_pMaterials->Draw(m_pPhysicsController->GetPosition(), m_pPhysicsController->GetRadius());
}

