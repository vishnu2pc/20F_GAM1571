#pragma once

class Materials;
class PhysicsController;

class GameArena : public fw::GameObject
{
public:
	GameArena(fw::Materials* pMaterials, fw::PhysicsController* pPhysicsController, fw::GameCore* pGameCore);
	~GameArena();

	void Draw() override;
	void Update(float deltaTime) override;
	
protected:
	fw::Materials* m_pMaterials;

};


