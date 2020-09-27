#pragma once
#include "Objects/GameObject.h"

class Player : public fw::GameObject
{
public:
	Player(vec2 position, int GameObjectType, std::vector<fw::Mesh*> pGameObjectMesh, fw::GameCore* pGameCore);
	~Player();

	void Update(float deltaTime) override;
	void Draw() override;

private:
	int GAMEOBJECT_TYPE = 0;
	std::vector<fw::Mesh*> m_pMesh;
};


