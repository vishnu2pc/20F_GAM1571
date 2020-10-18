#pragma once

class Materials;
class PhysicsController;
class PlayerController;

class Player : public fw::GameObject
{
public:
	Player(fw::Materials* pMaterials, fw::PhysicsController* pPhysicsController, fw::PlayerController* pPlayerController, fw::GameCore* pGameCore);
	~Player();

	void Draw() override;
	void Update(float deltaTime) override;
	void CheckPlayerArenaCollision(float radius);

	
protected:
	fw::Materials* m_pMaterials;
	fw::PlayerController* m_pPlayerController;
	bool m_PlayerArenaCollision;
};


