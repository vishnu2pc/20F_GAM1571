#pragma once

#include "Math/Vector.h"

namespace fw{
	
	class GameCore;
	class Materials;
	class PhysicsController;
	
	class GameObject
	{
	public:
		GameObject();
		~GameObject();

		virtual void Update(float deltaTime);
		virtual void Draw();
		
	protected:
		
		
};
}
