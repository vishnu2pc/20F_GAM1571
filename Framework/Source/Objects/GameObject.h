#pragma once

#include "Math/Vector.h"

namespace fw{
	
	class GameCore;
	class Materials;
	class PhysicsController;
	
	class GameObject
	{
	public:
		GameObject(PhysicsController* pPhysicsController, GameCore* pGameCore);
		~GameObject();

		virtual void Update(float deltaTime);
		virtual void Draw();

		PhysicsController* GetPhysicsController() { return m_pPhysicsController; }

		
	protected:
		PhysicsController* m_pPhysicsController;
		GameCore* m_pGameCore;
};
}
