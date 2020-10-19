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
	/*vec2 CurrentPos = m_pPhysicsController->GetPosition();
	vec2 CurrentVelocity = m_pPhysicsController->GetCurrentVelocity();

	if (CurrentPos.Distance(vec2(5.0f, 5.0f)) < 1.0f)
	{
		m_pPhysicsController->Update(static_cast<Game*>(m_pGameCore)->GetPlayerController(), deltaTime);
		vec2 CurrentVelocity = m_pPhysicsController->GetCurrentVelocity();
		vec2 NewPos = CurrentPos + CurrentVelocity * deltaTime;
		m_pPhysicsController->SetPosition(NewPos);
	}*/
}
void GameArena::Draw()
{
	m_pMaterials->Draw(m_pPhysicsController->GetPosition(), m_pPhysicsController->GetRadius());
}

