#pragma once
namespace fw{
	class ShaderProgram;
	class Mesh;

	class GameObject
{
public:
	GameObject(int GameObjectType);
	~GameObject();

	void Update();
	void Draw();
private:
    int GAMEOBJECT_TYPE = 0;
		
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

   
};
}
