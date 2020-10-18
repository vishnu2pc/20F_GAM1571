#include "GamePCH.h"
#include "PhysicsController.h"


PhysicsController::PhysicsController()
{
	m_position = vec2(5, 5);
	speed = 0;
}

PhysicsController::~PhysicsController()
{
}

void PhysicsController::SetPosition(vec2 position)
{
	m_position = position;
}
