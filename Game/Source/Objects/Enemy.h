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

protected:
	fw::Materials* m_pMaterials;
	vec2 PlayerPosition;
	vec2 DistanceFromPlayer;
	vec2 DirectionToPlayer;
};


