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
    vec2 OldPos = m_pPhysicsController->GetPosition();
	
    m_pPhysicsController->Update(fw::PhysicsController::PHYSICS_TYPE::GAME_ARENA,
        static_cast<Game*>(m_pGameCore)->GetPlayerController(), deltaTime/100);
	
    vec2 CurrentVelocity = m_pPhysicsController->GetCurrentVelocity();
    vec2 NewPos = OldPos + CurrentVelocity * deltaTime ;

    if (NewPos.Distance(vec2(5.0f,5.0f)) > 0.2f)
        NewPos = OldPos;

    m_pPhysicsController->SetPosition(NewPos);
}
void GameArena::Draw()
{
	m_pMaterials->Draw(m_pPhysicsController->GetPosition(), m_pPhysicsController->GetRadius());
}

