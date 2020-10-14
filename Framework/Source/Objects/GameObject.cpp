#include "FrameworkPCH.h"
#include "GameObject.h"
#include "../../Game/Source/Constants.h"
#include "Mesh.h"
#include "../../Libraries/imgui/imgui.h"
#include "../../Game/Source/Constants.h"
fw::GameObject::GameObject(vec2 position, int GameObjectType, std::vector<fw::Mesh*> pMesh, std::vector<fw::ShaderProgram*> pShader,
	fw::GameCore* pGameCore)
{
	m_pGameCore = pGameCore;
	m_Position = position;
	m_pMesh = pMesh;
	m_pShaders = pShader;
	GAMEOBJECT_TYPE = GameObjectType;
}




fw::GameObject::~GameObject()
{
	
}

void fw::GameObject::Update(float deltaTime)
{
	
}

void fw::GameObject::Draw()
{
	if (GAMEOBJECT_TYPE == GAME_AREA)
	{
		
		ImGui::SliderInt("Vertices", &m_num_points, MIN_VERTICES, MAX_VERTICES);
		for (int i = 0; i < m_pMesh.size(); i++)
		{
			
			m_pMesh[i]->CreateCircle(radius[i], m_num_points);
			m_pMesh[i]->Draw(m_Position, m_pShaders[i]);
		}

	}

	if (GAMEOBJECT_TYPE == PLAYER)
	{
		for (int i = 0; i < m_pMesh.size(); i++)
		{
			m_pMesh[i]->Draw(m_Position, m_pShaders[i]);
		}

	}

}
