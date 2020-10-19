#include "FrameworkPCH.h"
#include "GameObject.h"


fw::GameObject::GameObject(PhysicsController* pPhysicsController, GameCore* pGameCore)
{
	m_pPhysicsController = pPhysicsController;
	m_pGameCore = pGameCore;
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
