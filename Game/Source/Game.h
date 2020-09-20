#pragma once

class Game : public fw::GameCore
{
public:
    Game();
    virtual ~Game();

    void Init();
    virtual void Update() override;
    virtual void Draw() override;

protected:
    fw::ShaderProgram* m_pShader_Blue = nullptr;
    fw::ShaderProgram* m_pShader_DarkBlue = nullptr;
    fw::Mesh* m_pMesh = nullptr;

    float attribs[8] =
    {
        0.0f, 0.0f,
        0.5f, 0.5f,
        0.5f, 0.0f,
        0.5f, -0.5f,
    };
};
