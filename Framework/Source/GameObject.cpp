#include "GameObject.h"
#include "Constants.h"
#include "FrameworkPCH.h"
#include "Utility/ShaderProgram.h"
#include "Mesh.h"



fw::GameObject::GameObject(float x, float y, int GameObjectType, std::vector<Mesh*> pGameObjectMesh)
{
	m_PosX = x;
	m_PosY = y;

	GAMEOBJECT_TYPE = GameObjectType;
	m_Mesh = pGameObjectMesh;
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
			m_Mesh[i]->Draw(m_PosX, m_PosY);
		}

	}
	if (GAMEOBJECT_TYPE == ANIMAL)
	{
		for(int i = 0; i < m_Mesh.size(); i++)
		{
			m_Mesh[i]->Draw(m_PosX, m_PosY);
		}
	}
}
