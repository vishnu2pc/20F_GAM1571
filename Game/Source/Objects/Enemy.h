#pragma once

class Materials;
class PhysicsController;

class Enemy : public fw::GameObject
{
public:
	Enemy(fw::Materials* pMaterials, fw::PhysicsController* pPhysicsController, fw::GameCore* pGameCore);
	~Enemy();

	void Draw() override;
	void Update(float deltaTime) override;
	static void SetBehaviour(ENEMY_BEHAVIOUR enemy_behaviour);

protected:
	fw::Materials* m_pMaterials;
	vec2 InitialPlayerPosition;
	vec2 DistanceFromPlayer;
	vec2 DirectionToPlayer;

	static ENEMY_BEHAVIOUR m_Enemy_Behaviour ;
};


