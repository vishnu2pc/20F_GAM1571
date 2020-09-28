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
    std::vector<fw::GameObject*> m_GameObjects;
    fw::ImGuiManager* m_pImGuiManager = nullptr;

    fw::ShaderProgram* m_pShader_Blue = nullptr;
    fw::ShaderProgram* m_pShader_DarkBlue = nullptr;
    fw::ShaderProgram* m_pShader_Skin = nullptr;
    fw::ShaderProgram* m_pShader_Face = nullptr;

    std::vector<fw::Mesh*> m_MegaManMesh;
    std::vector<fw::Mesh*> m_DiamondDogMesh;

    std::vector<fw::ShaderProgram*> m_Shaders;
   
};
