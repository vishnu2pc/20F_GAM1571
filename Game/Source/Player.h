#pragma once


class Player : public fw::GameObject
{
public:
	Player(vec2 position, int GameObjectType, std::vector<fw::Mesh*> pGameObjectMesh, std::vector<fw::ShaderProgram*> pShaders, fw::GameCore* pGameCore);
	Player(vec2 position, int GameObjectType, std::vector<fw::Mesh*> pGameObjectMesh, fw::ShaderProgram* pShader, fw::GameCore* pGameCore);
	~Player();

	void Update(float deltaTime) override;
	void Draw() override;

private:
	int GAMEOBJECT_TYPE = 0;
	fw::ShaderProgram* m_pShader = nullptr;
	
	std::vector<fw::ShaderProgram*> m_pShaders;
	std::vector<fw::Mesh*> m_pMesh;
	
};


