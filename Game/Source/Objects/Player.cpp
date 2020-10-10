#include "GamePCH.h"

#include "Objects/Player.h"

Player::Player(fw::vec2 position, int GameObjectType, std::vector<fw::Mesh*> pMesh, std::vector<fw::ShaderProgram*> pShaders, fw::GameCore* pGameCore)
	: fw::GameObject(position, GameObjectType, pMesh, pShaders, pGameCore)
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

