#pragma once

#include "Math/Vector.h"

namespace fw{
	
	class GameCore;
	class Mesh;
	class ShaderProgram;

	class GameObject
	{
	public:
		GameObject(vec2 position, int GameObjectType, std::vector<fw::Mesh*> pMesh, std::vector<fw::ShaderProgram*> pShaders, fw::GameCore* pGameCore);
		GameObject(vec2 position, int GameObjectType, std::vector<fw::Mesh*> pMesh,fw::ShaderProgram* pShader, fw::GameCore* pGameCore);
		~GameObject();

		virtual void Update(float deltaTime);
		virtual void Draw();
		
	protected:
		GameCore* m_pGameCore;
		vec2 m_Position;
		int GAMEOBJECT_TYPE;
		fw::ShaderProgram* m_pShader = nullptr;
		std::vector<fw::ShaderProgram*> m_pShaders;
		std::vector<fw::Mesh*> m_pMesh;
};
}
