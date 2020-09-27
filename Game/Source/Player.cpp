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
}