#include "Player.h"
#include "Framework.h"


Player::Player(vec2 position, int GameObjectType, std::vector<fw::Mesh*> pGameObjectMesh, fw::GameCore* pGameCore) : GameObject(position, pGameCore),
m_pMesh(pGameObjectMesh),
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
		m_position.y += 0.02f;
	}

	if (m_pGameCore->GetFramework()->IsKeyDown('A') == true)
	{
		m_position.x -= 0.02f;
	}

	if (m_pGameCore->GetFramework()->IsKeyDown('S') == true)
	{
		m_position.y -= 0.02f;
	}

	if (m_pGameCore->GetFramework()->IsKeyDown('D') == true)
	{
		m_position.x += 0.02f;
	}
	
}

void Player::Draw()
{
	if (GAMEOBJECT_TYPE == HUMANOID)
	{
		for (int i = 0; i < m_pMesh.size(); i++)
		{
			m_pMesh[i]->Draw(m_position.x, m_position.y);
		}

	}
	if (GAMEOBJECT_TYPE == ANIMAL)
	{
		for (int i = 0; i < m_pMesh.size(); i++)
		{
			m_pMesh[i]->Draw(m_position.x, m_position.y);
		}
	}
}
