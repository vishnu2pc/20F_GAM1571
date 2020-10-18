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
	Materials* m_pMaterials;
	PhysicsController* m_pPhysicsController;
	fw::GameCore* m_pGameCore;
};


