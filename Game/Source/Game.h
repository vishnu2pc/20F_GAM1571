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


    fw::Mesh* m_pMeshDarkBlue = nullptr;
    fw::Mesh* m_pMeshBlue = nullptr;
    fw::Mesh* m_pMeshSkin = nullptr;
    fw::Mesh* m_pMeshFace = nullptr;

    fw::Mesh* m_pMeshDogFrontLegsRight = nullptr;
    fw::Mesh* m_pMeshDogFrontLegsLeft = nullptr;

    fw::Mesh* m_pMeshDogBackLegsRight = nullptr;
    fw::Mesh* m_pMeshDogBackLegsLeft = nullptr;

    fw::Mesh* m_pMeshDogTail = nullptr;
    fw::Mesh* m_pMeshDogBody = nullptr;

    std::vector<fw::Mesh*> m_MegaManMesh;
    std::vector<fw::Mesh*> m_DiamondDogMesh;

    std::vector<fw::ShaderProgram*> m_Shaders;
};
