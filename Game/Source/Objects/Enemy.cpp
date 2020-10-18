#include "GamePCH.h"

#include "Objects/Enemy.h"
#include "Materials.h"
#include "PhysicsController.h"

Enemy::Enemy(Materials* pMaterials, PhysicsController* pPhysicsController, fw::GameCore* pGameCore)
{
	m_GameCore = pGameCore;
	m_Materials = pMaterials;
	m_PhysicsController = pPhysicsController;
}

Enemy::~Enemy()
{
	
}


void Enemy::Update(float deltaTime)
{
	
}

void Enemy::Draw()
{
	m_Materials->Draw(m_PhysicsController->GetPosition());
}

