#include "GamePCH.h"

#include "Objects/Player.h"


Player::Player(fw::Materials* pMaterials, fw::PhysicsController* pPhysicsController, fw::PlayerController* pPlayerController, fw::GameCore* pGameCore) :
    GameObject(pPhysicsController, pGameCore)
{
	m_pMaterials = pMaterials;
	m_pPlayerController = pPlayerController;
    m_PlayerArenaCollision = false;
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
            dir.y = 1;
        }
        if (m_pPlayerController->IsDownHeld())
        {
            dir.y = -1;
        }
        if (m_pPlayerController->IsLeftHeld())
        {
            dir.x = -1;
        }
        if (m_pPlayerController->IsRightHeld())
        {
            dir.x = 1;
        }

        vec2 NewPos = m_pPhysicsController->GetPosition();
        NewPos += dir * (float)m_pPhysicsController->GetSpeed() * deltaTime;
        m_pPhysicsController->SetPosition(NewPos);
    }

    else
    {
        if (m_pPlayerController->IsUpHeld())
        {
            if (m_pPhysicsController->GetPosition().y > 0.0f)
            {
                if (m_pPhysicsController->GetPosition().x < 0.0f)
                    dir.x = 0.5f;
                else if (m_pPhysicsController->GetPosition().x > 0.0f)
                    dir.x = -0.5f;
            }

            else
                dir.y = 1;
        }
    	
        if (m_pPlayerController->IsDownHeld())
        {
            if (m_pPhysicsController->GetPosition().y < 0.0f)
            {
                if (m_pPhysicsController->GetPosition().x < 0.0f)
                    dir.x = 0.5f;
                else if (m_pPhysicsController->GetPosition().x > 0.0f)
                    dir.x = -0.5f;
            }
        	
            else
                dir.y = -1;
        }
        if (m_pPlayerController->IsLeftHeld())
        {
            if (m_pPhysicsController->GetPosition().x < 0.0f)
            {
                if (m_pPhysicsController->GetPosition().y < 0.0f)
                    dir.y = 0.5f;
                else if (m_pPhysicsController->GetPosition().y > 0.0f)
                    dir.y = -0.5f;
            }

            else
                dir.x = -1;
        }
        if (m_pPlayerController->IsRightHeld())
        {
            if (m_pPhysicsController->GetPosition().x > 0.0f)
            {
                if (m_pPhysicsController->GetPosition().y < 0.0f)
                    dir.y = 0.5f;
                else if (m_pPhysicsController->GetPosition().y > 0.0f)
                    dir.y = -0.5f;
            }

            else
                dir.x = 1;
        }

        vec2 NewPos = m_pPhysicsController->GetPosition();
        NewPos += dir * (float)m_pPhysicsController->GetSpeed() * deltaTime;
        m_pPhysicsController->SetPosition(NewPos);
    }
    
}

void Player::CheckPlayerArenaCollision(float radius)
{
    if (m_pPhysicsController->GetPosition().Magnitude() >= radius)
        m_PlayerArenaCollision = true;
}


void Player::Draw()
{
	m_pMaterials->Draw(m_pPhysicsController->GetPosition(), m_pPhysicsController->GetRadius());
}

