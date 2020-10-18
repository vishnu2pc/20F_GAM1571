#pragma once

class Materials;
class PhysicsController;

class Enemy : public fw::GameObject
{
public:
	Enemy(Materials* pMaterials, PhysicsController* pPhysicsController, fw::GameCore* pGameCore);
	~Enemy();

	void Draw() override;
	void Update(float deltaTime) override;
	
protected:
	Materials* m_Materials;
	PhysicsController* m_PhysicsController;
	fw::GameCore* m_GameCore;
};


