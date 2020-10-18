#include "GamePCH.h"

#include "Objects/GameArena.h"


GameArena::GameArena(fw::Materials* pMaterials, fw::PhysicsController* pPhysicsController, fw::GameCore* pGameCore) :
	GameObject(pPhysicsController, pGameCore)
{
	m_pMaterials = pMaterials;

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

