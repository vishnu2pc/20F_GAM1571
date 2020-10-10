#include "../../Framework/Source/Framework.h"

#include "Objects/Player.h"

Player::Player(fw::vec2 position, int GameObjectType, std::vector<fw::Mesh*> pGameObjectMesh, std::vector<fw::ShaderProgram*> pShaders, fw::GameCore* pGameCore)
	: GameObject(position, pGameCore),

		m_pMesh(pGameObjectMesh),
		m_pShaders(pShaders),
		GAMEOBJECT_TYPE(GameObjectType)
{
}

Player::Player(fw::vec2 position, int GameObjectType, std::vector<fw::Mesh*> pGameObjectMesh, fw::ShaderProgram* pShader,fw::GameCore* pGameCore)
	: GameObject(position, pGameCore),

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
	float speed = 2.0f;

	fw::vec2 dir;

	if (m_pGameCore->GetFramework()->IsKeyDown('A'))
	{
		dir.x = -1;
	}
	if (m_pGameCore->GetFramework()->IsKeyDown('D'))
	{
		dir.x = 1;
	}
	if (m_pGameCore->GetFramework()->IsKeyDown('W'))
	{
		dir.y = 1;
	}
	if (m_pGameCore->GetFramework()->IsKeyDown('S'))
	{
		dir.y = -1;
	}

	m_Position.x += dir.x * speed * deltaTime;
	m_Position.y += dir.y * speed * deltaTime;
	
}

void Player::Draw()
{
	if (GAMEOBJECT_TYPE == HUMANOID)
	{
		for (int i = 0; i < m_pMesh.size(); i++)
		{
			m_pMesh[i]->Draw(m_Position, m_pShaders[i]);
		}

	}
	if (GAMEOBJECT_TYPE == ANIMAL)
	{
		for (int i = 0; i < m_pMesh.size(); i++)
		{
			m_pMesh[i]->Draw(m_Position, m_pShader);
		}
	}
}
