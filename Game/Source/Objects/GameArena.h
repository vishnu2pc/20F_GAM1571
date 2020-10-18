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
	Materials* m_Materials;
	PhysicsController* m_PhysicsController;
	fw::GameCore* m_GameCore;
};


