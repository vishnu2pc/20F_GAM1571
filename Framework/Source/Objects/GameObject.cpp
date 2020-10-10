#include "GameObject.h"
#include "Math/Vector.h"


fw::GameObject::GameObject(vec2 position, GameCore* pGameCore):
	
m_pGameCore(pGameCore),
m_Position(position)

{
	
}

fw::GameObject::~GameObject()
{
	
}

void fw::GameObject::Update(float deltaTime)
{
}

void fw::GameObject::Draw()
{
	
}
