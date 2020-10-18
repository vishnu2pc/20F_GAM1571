#pragma once

class Materials;
class PhysicsController;
class PlayerController;

class Player : public fw::GameObject
{
public:
	Player(Materials* pMaterials, PhysicsController* pPhysicsController, PlayerController* pPlayerController, fw::GameCore* pGameCore);
	~Player();

	void Draw() override;
	void Update(float deltaTime) override;
	
protected:
	Materials* m_pMaterials;
	PhysicsController* m_pPhysicsController;
	PlayerController* m_pPlayerController;
	fw::GameCore* m_pGameCore;
};


