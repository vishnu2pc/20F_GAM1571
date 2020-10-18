#include "FrameworkPCH.h"
#include "PhysicsController.h"

#include "Math/Vector.h"

namespace fw
{
		
	PhysicsController::PhysicsController()
	{
		m_position = fw::vec2(5, 5);
		m_speed = 0;
	}
	
	PhysicsController::~PhysicsController()
	{
	}
}

