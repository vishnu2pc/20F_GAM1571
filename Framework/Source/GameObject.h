#pragma once
#include <vector>

namespace fw{
	class ShaderProgram;
	class Mesh;

	class GameObject
	{
	public:
		GameObject(float x, float y, int GameObjectType, std::vector<Mesh*> pGameObjectMesh);
		~GameObject();

		void Update();
		void Draw();
		
	protected:
		int GAMEOBJECT_TYPE = 0;
		std::vector<Mesh*> m_Mesh;
	
		float m_PosX = 0;
		float m_PosY = 0;
	
		
};
}
