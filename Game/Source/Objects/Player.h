#pragma once

class Materials;
class PhysicsController;

class Player : public fw::GameObject
{
public:
	Player(Materials* pMaterials, PhysicsController* pPhysicsController, fw::GameCore* pGameCore);
	~Player();

	void Draw() override;
	void Update(float deltaTime) override;
	
protected:
	Materials* m_Materials;
	PhysicsController* m_PhysicsController;
	fw::GameCore* m_GameCore;
};


