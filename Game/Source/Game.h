#pragma once

class Game : public fw::GameCore
{
    
public:
    Game(fw::FWCore* pFramework);
    virtual ~Game();

    void Init();
    virtual void Update(float deltaTime) override;
    virtual void Draw() override;

protected:
    fw::ShaderProgram* m_pShader_Blue = nullptr;
    fw::ShaderProgram* m_pShader_DarkBlue = nullptr;
    fw::ShaderProgram* m_pShader_Skin = nullptr;
    fw::ShaderProgram* m_pShader_Black = nullptr;
    fw::ShaderProgram* m_pShader_White = nullptr;
    fw::ShaderProgram* m_pShader_Red = nullptr;

    std::vector<fw::ShaderProgram*> m_GameArea_Shaders;
    std::vector < fw::ShaderProgram*> m_Player_Shaders;
	
    fw::Mesh* m_GameArea_Outer = nullptr;
    fw::Mesh* m_GameArea_Inner = nullptr;
    fw::Mesh* m_Player_mesh = nullptr;

	std::vector<fw::Mesh*> m_GameArea_Meshes;
    std::vector<fw::Mesh*> m_Player_Meshes;
	
	std::vector<fw::GameObject*> m_GameObjects;
    fw::ImGuiManager* m_pImGuiManager = nullptr;
    
	
};
