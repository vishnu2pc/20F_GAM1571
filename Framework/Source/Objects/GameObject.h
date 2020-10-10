#pragma once
#include "Math/Vector.h"

namespace fw{
	
	class GameCore;
	class Mesh;
	class ShaderProgram;

	class GameObject
	{
	public:
		GameObject(vec2 position,GameCore* pGameCore);
		~GameObject();

		virtual void Update(float deltaTime);
		virtual void Draw();
		
	protected:
		GameCore* m_pGameCore;
		vec2 m_Position;	
};
}
