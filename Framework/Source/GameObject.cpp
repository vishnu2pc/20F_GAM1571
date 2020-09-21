#include "GameObject.h"
#include "Constants.h"
#include "FrameworkPCH.h"
#include "Utility/ShaderProgram.h"
#include "Mesh.h"

fw::GameObject::GameObject(int GameObjectType)
{
    
    m_pShader_DarkBlue = new fw::ShaderProgram("Data/Basic.vert", "Data/DarkBlue.frag");
	m_pShader_Blue = new fw::ShaderProgram("Data/Basic.vert", "Data/Blue.frag");
	m_pShader_Skin = new fw::ShaderProgram("Data/Basic.vert", "Data/Skin.frag");
	m_pShader_Face = new fw::ShaderProgram("Data/Basic.vert", "Data/Black.frag");

	if (GameObjectType == HUMANOID)
	{
		m_pMeshDarkBlue = new fw::Mesh(VERTEX_DARK_BLUE, 54, GL_TRIANGLES);
		m_pMeshBlue = new fw::Mesh(VERTEX_BLUE, 42, GL_TRIANGLES);
		m_pMeshSkin = new fw::Mesh(VERTEX_SKIN, 18, GL_TRIANGLES);
		m_pMeshFace = new fw::Mesh(VERTEX_FACE, 24, GL_TRIANGLES);
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
	m_pMeshSkin->Draw(m_pShader_Skin);
	m_pMeshFace->Draw(m_pShader_Face);
	m_pMeshBlue->Draw(m_pShader_Blue);
}
