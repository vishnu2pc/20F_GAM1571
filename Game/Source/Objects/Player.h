#pragma once


class Player : public fw::GameObject
{
public:
	Player(vec2 position, int GameObjectType, std::vector<fw::Mesh*> pMesh, std::vector<fw::ShaderProgram*> pShaders, fw::GameCore* pGameCore);
	~Player();

	void Update(float deltaTime) override;
	
protected:
		
};


