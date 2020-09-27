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
		GameObject(vec2 position, int GameObjectType, std::vector<Mesh*> pGameObjectMesh, GameCore* pGameCore);
		~GameObject();

		void Update();
		void Draw();
		
	protected:
		int GAMEOBJECT_TYPE = 0;
		std::vector<Mesh*> m_Mesh;

		GameCore* m_GameCore;
		vec2 m_position;
	
		
};
}
