#include "GameObject.h"
#include "Constants.h"
#include "FrameworkPCH.h"
#include "Mesh.h"
#include "Math/Vector.h"


fw::GameObject::GameObject(vec2 position, GameCore* pGameCore):

m_pGameCore(pGameCore),
m_position(position)

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
