#include "GamePCH.h"

#include "Objects/GameArena.h"
#include "Components/Materials.h"
#include "Components/PhysicsController.h"

GameArena::GameArena(Materials* pMaterials, PhysicsController* pPhysicsController, fw::GameCore* pGameCore)
{
	m_GameCore = pGameCore;
	m_Materials = pMaterials;
	m_PhysicsController = pPhysicsController;
}

GameArena::~GameArena()
{
	
}


void GameArena::Update(float deltaTime)
{
	
}

void GameArena::Draw()
{
	m_Materials->Draw(m_PhysicsController->GetPosition());
}

