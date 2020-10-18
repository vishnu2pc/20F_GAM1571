#include "GamePCH.h"

#include "Objects/Player.h"
#include "Materials.h"
#include "PhysicsController.h"

Player::Player(Materials* pMaterials, PhysicsController* pPhysicsController, fw::GameCore* pGameCore)
{
	m_GameCore = pGameCore;
	m_Materials = pMaterials;
	m_PhysicsController = pPhysicsController;
}

Player::~Player()
{
	
}


void Player::Update(float deltaTime)
{
	
}

void Player::Draw()
{
	m_Materials->Draw(m_PhysicsController->GetPosition());
}

