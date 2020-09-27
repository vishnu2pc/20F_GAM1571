#include "GameObject.h"
#include "Constants.h"
#include "FrameworkPCH.h"
#include "Mesh.h"
#include "Math/Vector.h"


fw::GameObject::GameObject(vec2 position, int GameObjectType, std::vector<Mesh*> pGameObjectMesh, GameCore* pGameCore):

m_GameCore(pGameCore),
m_position(position),
GAMEOBJECT_TYPE(GameObjectType),
m_Mesh(pGameObjectMesh)

{
}

fw::GameObject::~GameObject()
{
	
}

void fw::GameObject::Update()
{
}

void fw::GameObject::Draw()
{
	if (GAMEOBJECT_TYPE == HUMANOID)
	{
		for (int i = 0; i < m_Mesh.size(); i++)
		{
			m_Mesh[i]->Draw(m_position.x, m_position.y);
		}

	}
	if (GAMEOBJECT_TYPE == ANIMAL)
	{
		for(int i = 0; i < m_Mesh.size(); i++)
		{
			m_Mesh[i]->Draw(m_position.x, m_position.y);
		}
	}
}
