#include "GamePCH.h"

#include "Objects/Player.h"

#include "Game.h"
#include "Events/GameEvents.h"


Player::Player(fw::Materials* pMaterials, fw::PhysicsController* pPhysicsController, fw::PlayerController* pPlayerController, fw::GameCore* pGameCore) :
    GameObject(pPhysicsController, pGameCore)
{
    m_pMaterials = pMaterials;
    m_pPlayerController = pPlayerController;

}

Player::~Player()
{

}


void Player::Update(float deltaTime)
{

    vec2 dir;
    if (!m_PlayerArenaCollision)
    {

        if (m_pPlayerController->IsUpHeld())
        {
            dir.y = 3;
        }
        if (m_pPlayerController->IsDownHeld())
        {
            dir.y = -3;
        }
        if (m_pPlayerController->IsLeftHeld())
        {
            dir.x = -3;
        }
        if (m_pPlayerController->IsRightHeld())
        {
            dir.x = 3;
        }

        vec2 OldPos = m_pPhysicsController->GetPosition();
        vec2 NewPos = OldPos + dir * (float)m_pPhysicsController->GetSpeed() * deltaTime;

        float ArenaRadius = static_cast<Game*>(m_pGameCore)->GetArenaRadius();
        vec2 ArenaPosition = static_cast<Game*>(m_pGameCore)->GetArenaPosition();
        if (NewPos.Distance(ArenaPosition) > ArenaRadius)
            NewPos = OldPos;

        m_pPhysicsController->SetPosition(NewPos);
    }

}

void Player::OnEvent(fw::Event* pEvent)
{
    CollisionEvent* pCollisionEvent = static_cast<CollisionEvent*>(pEvent);

    if (pCollisionEvent->GetCollisionType() == CollisionEvent::COLLISION_TYPE::ARENA)
    {
        m_PlayerArenaCollision = true;
    }

    if (pCollisionEvent->GetCollisionType() == CollisionEvent::COLLISION_TYPE::NONE)
    {
        m_PlayerArenaCollision = false;
    }
}


void Player::Draw()
{
    m_pMaterials->Draw(m_pPhysicsController->GetPosition(), m_pPhysicsController->GetRadius());
}

