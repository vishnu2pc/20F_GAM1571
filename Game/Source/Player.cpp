#include "Player.h"
#include "Framework.h"


Player::Player(vec2 position, int GameObjectType, std::vector<fw::Mesh*> pGameObjectMesh, std::vector<fw::ShaderProgram*> pShaders, fw::GameCore* pGameCore) : GameObject(position, pGameCore),
m_pMesh(pGameObjectMesh),
m_pShaders(pShaders),
GAMEOBJECT_TYPE(GameObjectType)
{
}

Player::Player(vec2 position, int GameObjectType, std::vector<fw::Mesh*> pGameObjectMesh, fw::ShaderProgram* pShader,fw::GameCore* pGameCore) : GameObject(position, pGameCore),
m_pMesh(pGameObjectMesh),
m_pShader(pShader),
GAMEOBJECT_TYPE(GameObjectType)
{
}

Player::~Player()
{
}

void Player::Update(float deltaTime)
{
	if (m_pGameCore->GetFramework()->IsKeyDown('W') == true)
	{
		m_position.y += 10.0f* deltaTime;
	}

	if (m_pGameCore->GetFramework()->IsKeyDown('A') == true)
	{
		m_position.x -= 10.0f * deltaTime;
	}

	if (m_pGameCore->GetFramework()->IsKeyDown('S') == true)
	{
		m_position.y -= 10.0f * deltaTime;
	}

	if (m_pGameCore->GetFramework()->IsKeyDown('D') == true)
	{
		m_position.x += 10.0f * deltaTime;
	}
	
}

void Player::Draw()
{
	if (GAMEOBJECT_TYPE == HUMANOID)
	{
		for (int i = 0; i < m_pMesh.size(); i++)
		{
			m_pMesh[i]->Draw(m_position.x, m_position.y, m_pShaders[i]);
		}

	}
	if (GAMEOBJECT_TYPE == ANIMAL)
	{
		for (int i = 0; i < m_pMesh.size(); i++)
		{
			m_pMesh[i]->Draw(m_position.x, m_position.y, m_pShader);
		}
	}
}
