#include "GamePCH.h"

#include "Objects/GameArena.h"

#include "Game.h"


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
	vec2 PlayerPosition = m_pGameCore->GetPlayerPosition();
	vec2 ArenaPosition = m_pGameCore->GetArenaPosition();
	float ArenaRadius = m_pGameCore->GetArenaRadius();
	float PlayerRadius = m_pGameCore->GetPlayerRadius();
	
	vec2 OldPos = m_pPhysicsController->GetPosition();

	vec2 NewPos = OldPos - ((PlayerPosition - ArenaPosition) / ArenaRadius) * 0.0003f;
	vec2 distance = PlayerPosition - ArenaPosition;
	if (distance.Magnitude() >= ArenaRadius - PlayerRadius)
		NewPos = OldPos;
	
	m_pPhysicsController->SetPosition(NewPos);


}
void GameArena::Draw()
{
	m_pMaterials->Draw(m_pPhysicsController->GetPosition(), m_pPhysicsController->GetRadius());
}

