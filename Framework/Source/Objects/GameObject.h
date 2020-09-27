#pragma once
#include <vector>
#include "Math/Vector.h"

namespace fw{
	
	class GameCore;
	class ShaderProgram;
	class Mesh;

	class GameObject
	{
	public:
		GameObject(vec2 position,GameCore* pGameCore);
		~GameObject();

		virtual void Update(float deltaTime);
		virtual void Draw();
		
	protected:
		

		GameCore* m_pGameCore;
		vec2 m_position;
	
		
};
}
