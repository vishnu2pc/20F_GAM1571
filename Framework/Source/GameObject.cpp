#include "GameObject.h"
#include "Constants.h"
#include "FrameworkPCH.h"
#include "Utility/ShaderProgram.h"
#include "Mesh.h"

fw::GameObject::GameObject(int GameObjectType)
{
    m_pShader_Blue = new fw::ShaderProgram("Data/Basic.vert", "Data/Blue.frag");
    m_pShader_DarkBlue = new fw::ShaderProgram("Data/Basic.vert", "Data/DarkBlue.frag");
	m_pShader_Skin = new fw::ShaderProgram("Data/Basic.vert", "Data/Skin.frag");

	if (GameObjectType == HUMANOID)
	{
		m_pMeshDarkBlue = new fw::Mesh(VERTEX_DARK_BLUE, 54, GL_TRIANGLES);
		m_pMeshBlue = new fw::Mesh(VERTEX_BLUE, 36, GL_TRIANGLES);
		
	}

	if (GameObjectType == ANIMAL)
	{
		m_pMeshDarkBlue = new fw::Mesh(VERTEX_BLUE, 3, GL_TRIANGLES);
	}
	
}

fw::GameObject::~GameObject()
{
	
}

void fw::GameObject::Update()
{
}

void fw::GameObject::Draw()
{
	m_pMeshDarkBlue->Draw(m_pShader_DarkBlue);
	m_pMeshBlue->Draw(m_pShader_Blue);
	
}
