#include "GamePCH.h"

#include "Objects/GameArena.h"
#include "Components/Materials.h"
#include "Components/PhysicsController.h"

GameArena::GameArena(Materials* pMaterials, PhysicsController* pPhysicsController, fw::GameCore* pGameCore)
{
	m_pGameCore = pGameCore;
	m_pMaterials = pMaterials;
	m_pPhysicsController = pPhysicsController;
}

GameArena::~GameArena()
{
	
}


void GameArena::Update(float deltaTime)
{
	
}

void GameArena::Draw()
{
	m_pMaterials->Draw(m_pPhysicsController->GetPosition(), m_pPhysicsController->GetRadius());
}

