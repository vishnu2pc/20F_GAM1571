#pragma once

class Materials;
class PhysicsController;

class GameArena : public fw::GameObject
{
public:
	GameArena(Materials* pMaterials, PhysicsController* pPhysicsController, fw::GameCore* pGameCore);
	~GameArena();

	void Draw() override;
	void Update(float deltaTime) override;
	
protected:
	Materials* m_pMaterials;
	PhysicsController* m_pPhysicsController;
	fw::GameCore* m_pGameCore;
};


