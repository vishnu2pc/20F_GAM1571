#include "GamePCH.h"

#include "Objects/Enemy.h"
#include "Components/Materials.h"
#include "Components/PhysicsController.h"

Enemy::Enemy(Materials* pMaterials, PhysicsController* pPhysicsController, fw::GameCore* pGameCore)
{
	m_pGameCore = pGameCore;
	m_pMaterials = pMaterials;
	m_pPhysicsController = pPhysicsController;
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

