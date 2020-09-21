#include "GameObject.h"
#include "Constants.h"
#include "FrameworkPCH.h"
#include "Utility/ShaderProgram.h"
#include "Mesh.h"

fw::GameObject::GameObject(int GameObjectType)
{
	GAMEOBJECT_TYPE = GameObjectType;
    m_pShader_DarkBlue = new fw::ShaderProgram("Data/Basic.vert", "Data/DarkBlue.frag");
	m_pShader_Blue = new fw::ShaderProgram("Data/Basic.vert", "Data/Blue.frag");
	m_pShader_Skin = new fw::ShaderProgram("Data/Basic.vert", "Data/Skin.frag");
	m_pShader_Face = new fw::ShaderProgram("Data/Basic.vert", "Data/Black.frag");

	if (GameObjectType == HUMANOID)
	{
		m_pMeshDarkBlue = new fw::Mesh(VERTEX_MM_DARK_BLUE, 54, GL_TRIANGLES);
		m_pMeshBlue = new fw::Mesh(VERTEX_MM_BLUE, 42, GL_TRIANGLES);
		m_pMeshSkin = new fw::Mesh(VERTEX_MM_SKIN, 18, GL_TRIANGLES);
		m_pMeshFace = new fw::Mesh(VERTEX_MM_FACE, 24, GL_TRIANGLES);
	}

	if (GameObjectType == ANIMAL)
	{
		m_pMeshDogFrontLegsRight = new fw::Mesh(VERTEX_DOG_FRONT_LEGS_RIGHT, 11, GL_LINE_LOOP);
		m_pMeshDogFrontLegsLeft = new fw::Mesh(VERTEX_DOG_FRONT_LEGS_LEFT, 11, GL_LINE_LOOP);
		m_pMeshDogBackLegsRight = new fw::Mesh(VERTEX_DOG_BACK_LEGS_RIGHT, 11, GL_LINE_LOOP);
		m_pMeshDogBackLegsLeft = new fw::Mesh(VERTEX_DOG_BACK_LEGS_LEFT, 9, GL_LINE_LOOP);

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
	if (GAMEOBJECT_TYPE == HUMANOID)
	{
		m_pMeshDarkBlue->Draw(m_pShader_DarkBlue);
		m_pMeshSkin->Draw(m_pShader_Skin);
		m_pMeshFace->Draw(m_pShader_Face);
		m_pMeshBlue->Draw(m_pShader_Blue);
	}

	if (GAMEOBJECT_TYPE == ANIMAL)
	{
		m_pMeshDogFrontLegsRight->Draw(m_pShader_Skin);
		m_pMeshDogFrontLegsLeft->Draw(m_pShader_Skin);
		m_pMeshDogBackLegsRight->Draw(m_pShader_Skin);
		m_pMeshDogBackLegsLeft->Draw(m_pShader_Skin);
		
	}
}
