#include "Player.h"
#include "Framework.h"


Player::Player(vec2 position, int GameObjectType, std::vector<fw::Mesh*> pGameObjectMesh, fw::GameCore* pGameCore) : GameObject(position, GAMEOBJECT_TYPE, pGameObjectMesh, pGameCore)
{
}

Player::~Player()
{
}

void Player::Update(float deltaTime)
{
	if (m_pGameCore->GetFramework()->IsKeyDown('W') == true)
	{
		m_position.x += 0.5f;
	}

	if (m_pGameCore->GetFramework()->IsKeyDown('A') == true)
	{

	}

	if (m_pGameCore->GetFramework()->IsKeyDown('S') == true)
	{

	}

	if (m_pGameCore->GetFramework()->IsKeyDown('D') == true)
	{

	}
	
}