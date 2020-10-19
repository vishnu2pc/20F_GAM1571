#include "FrameworkPCH.h"
#include "PhysicsController.h"
#include "PlayerController.h"


namespace fw
{
		
	PhysicsController::PhysicsController()
	{
		m_position = fw::vec2(5, 5);
		m_MaxVelocity = vec2(5, 5);
		m_MinVelocity = vec2(0, 0);
		m_FinalVelocity = vec2(0, 0);
		m_CurrentVelocity = vec2(0, 0);
		m_radius = 5;
	}
	
	PhysicsController::~PhysicsController()
	{
	}


	void PhysicsController::Update(PHYSICS_TYPE PhysicsType, PlayerController* pPlayerController, float deltaTime)
	{
		HandleKeyPress(PhysicsType, pPlayerController);
		Interpolate(deltaTime * 10);
	}

	void PhysicsController::HandleKeyPress(PHYSICS_TYPE PhysicsType, PlayerController* pPlayerController)
	{
		if (PhysicsType == PHYSICS_TYPE::PLAYER)
		{
			if (pPlayerController->IsDownHeld())
				m_FinalVelocity.y = m_MaxVelocity.y * -1;
			else if (!pPlayerController->IsDownHeld())
				m_FinalVelocity.y = m_MinVelocity.y * 1;

			if (pPlayerController->IsUpHeld())
				m_FinalVelocity.y = m_MaxVelocity.y * 1;

			if (pPlayerController->IsLeftHeld())
				m_FinalVelocity.x = m_MaxVelocity.x * -1;
			else if (!pPlayerController->IsLeftHeld())
				m_FinalVelocity.x = m_MinVelocity.x * 1;

			if (pPlayerController->IsRightHeld())
				m_FinalVelocity.x = m_MaxVelocity.x * 1;
		}

		if (PhysicsType == PHYSICS_TYPE::GAME_ARENA)
		{
			if (pPlayerController->IsDownHeld())
				m_FinalVelocity.y = m_MaxVelocity.y * 1;
			else if (!pPlayerController->IsDownHeld())
				m_FinalVelocity.y = m_MinVelocity.y * -1;

			if (pPlayerController->IsUpHeld())
				m_FinalVelocity.y = m_MaxVelocity.y * -1;

			if (pPlayerController->IsLeftHeld())
				m_FinalVelocity.x = m_MaxVelocity.x * 1;
			else if (!pPlayerController->IsLeftHeld())
				m_FinalVelocity.x = m_MinVelocity.x * -1;

			if (pPlayerController->IsRightHeld())
				m_FinalVelocity.x = m_MaxVelocity.x * -1;
		}
		
	}


	void PhysicsController::Interpolate(float deltaTime)
	{
		float difference = m_FinalVelocity.x - m_CurrentVelocity.x;

		if (difference > deltaTime)
			m_CurrentVelocity.x += deltaTime;
		else if (difference < deltaTime)
			m_CurrentVelocity.x -= deltaTime;
		else
			m_CurrentVelocity.x = m_FinalVelocity.x;

		difference = m_FinalVelocity.y - m_CurrentVelocity.y;

		if (difference > deltaTime)
			m_CurrentVelocity.y += deltaTime;
		else if (difference < deltaTime)
			m_CurrentVelocity.y -= deltaTime;
		else
			m_CurrentVelocity.y = m_FinalVelocity.y;
	}
}

