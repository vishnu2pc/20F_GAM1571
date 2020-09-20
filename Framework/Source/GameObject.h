#pragma once
namespace fw{
	class ShaderProgram;
	class Mesh;

	class GameObject
{
public:
	GameObject();
	~GameObject();

	void Update();
	void Draw();
private:
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
}
