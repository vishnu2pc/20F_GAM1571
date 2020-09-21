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

    float VERTEX_MM_DARK_BLUE[108] =
    {
        //Body Vertices

        -1.0f, -0.6f,
        -0.6f, -0.6f,
        -0.8f, -0.4f,

        0.0f, -0.6f,
        -0.4f, -0.6f,
        -0.2f, -0.4f,

        -0.7f, -0.3f,
        -0.5f, -0.4f,
        -0.5f, -0.2f,

        -0.3f, -0.3f,
        -0.5f, -0.4f,
        -0.5f, -0.2f,

        -0.7f, -0.3f,
        -0.7f, -0.2f,
        -0.5f, -0.2f,

        -0.3f, -0.3f,
        -0.3f, -0.2f,
        -0.5f, -0.2f,

        -0.8f, 0.1f,
        -0.7f, -0.2f,
        -0.8f, -0.3f,

        -0.2f, 0.1f,
        -0.3f, -0.2f,
        -0.2f, -0.3f,

        -0.8f, -0.3f,
        -0.8f, 0.1f,
        -1.0f, -0.2f,

        -0.2f, -0.3f,
        -0.2f, 0.1f,
        -0.0f, -0.2f,

        // Head Vertices

        -0.5f, -0.1f,
        -0.8f, 0.1f,
        -0.8f, 0.2f,

        -0.5f, -0.1f,
        -0.2f, 0.1f,
        -0.2f, 0.2f,

        -0.8f, 0.2f,
        -0.8f, 0.3f,
        -0.7f, 0.3f,

        -0.2f, 0.2f,
        -0.2f, 0.3f,
        -0.3f, 0.3f,

        -0.8f, 0.3f,
        -0.5f, 0.3f,
        -0.5f, 0.5f,

        -0.2f, 0.3f,
        -0.5f, 0.3f,
        -0.5f, 0.5f,

        -0.8f, 0.3f,
        -0.5f, 0.5f,
        -0.6f, 0.5f,

        -0.2f, 0.3f,
        -0.5f, 0.5f,
        -0.4f, 0.5f,

    };

    float VERTEX_MM_BLUE[84] =
    {
        -0.8f, -0.4f,
        -0.7f, -0.3f,
        -0.6f, -0.6f,

        -0.2f, -0.4f,
        -0.3f, -0.3f,
        -0.4f, -0.6f,

        -0.7f, -0.3f,
        -0.6f, -0.6f,
        -0.5f, -0.4f,

        -0.3f, -0.3f,
        -0.4f, -0.6f,
        -0.5f, -0.4f,

        -0.7f, -0.2f,
        -0.5f, -0.2f,
        -0.5f, -0.1f,

        -0.3f, -0.2f,
        -0.5f, -0.2f,
        -0.5f, -0.1f,

        -0.5f, -0.1f,
        -0.7f, -0.2f,
        -0.8f, 0.1f,

        -0.5f, -0.1f,
        -0.3f, -0.2f,
        -0.2f, 0.1f,

        // Head Vertices

        -0.8f, 0.2f,
        -0.7f, 0.2f,
        -0.7f, 0.1f,

        -0.2f, 0.2f,
        -0.3f, 0.2f,
        -0.3f, 0.1f,

        -0.2f, 0.2f,
        -0.3f, 0.2f,
        -0.3f, 0.3f,

        -0.8f, 0.2f,
        -0.7f, 0.2f,
        -0.7f, 0.3f,

        -0.55f, 0.3f,
        -0.45f, 0.3f,
        -0.45f, 0.5f,

        -0.55f, 0.3f,
        -0.45f, 0.5f,
        -0.55f, 0.5f
    };

    float VERTEX_MM_SKIN[36] =
    {
        -0.5f, -0.1f,
        -0.7f, 0.1f,
        -0.7f, 0.2f,

        -0.5f, -0.1f,
        -0.3f, 0.1f,
        -0.3f, 0.2f,

        -0.7f, 0.2f,
        -0.7f, 0.3f,
        -0.5f, 0.3f,

        -0.3f, 0.2f,
        -0.3f, 0.3f,
        -0.5f, 0.3f,

        -0.7f, 0.2f,
        -0.5f, 0.3f,
        -0.5f, -0.1f,

        -0.3f, 0.2f,
        -0.5f, 0.3f,
        -0.5f, -0.1f,
    };

    float VERTEX_MM_FACE[72] =
    {
        -0.6f, 0.2f,
        -0.6f, 0.15f,
        -0.55f, 0.2f,

         -0.4f, 0.2f,
        -0.4f, 0.15f,
        -0.45f, 0.2f,

        -0.6f, 0.15f,
        -0.55f, 0.2f,
        -0.55f, 0.15f,

        -0.4f, 0.15f,
        -0.45f, 0.2f,
        -0.45f, 0.15f,

        -0.55f, 0.0f,
        -0.5f, 0.0f,
        -0.55f, 0.05f,

        -0.45f, 0.0f,
        -0.5f, 0.0f,
        -0.45f, 0.05f,

        -0.5f, 0.0f,
        -0.55f, 0.05f,
        -0.5f, 0.05f,

        -0.5f, 0.0f,
        -0.45f, 0.05f,
        -0.5f, 0.05f
    };

    float VERTEX_DOG_FRONT_LEGS_RIGHT[22] =
    {
        //Right Leg

        0.34f, -0.6f,
        0.3f, -0.6f,
        0.32f, -0.58f,
        0.32f, -0.52f,
        0.27f, -0.48f,
        0.27f, -0.4f,
        0.3f, -0.35f,
        0.3f, -0.4f,
        0.3f, -0.47f,
        0.36f, -0.5f,
        0.35f, -0.58f

    };

    float VERTEX_DOG_FRONT_LEGS_LEFT[22] =
    {
        0.42f, -0.6f,
        0.38f, -0.6f,
        0.4f, -0.58f,
        0.4f, -0.52f,
        0.34f, -0.47f,
        0.34f, -0.42f,
        0.35f, -0.4f,
        0.4f, -0.41f,
        0.42f, -0.47f,
        0.44f, -0.49f,
        0.44f, -0.52f

    };

    float VERTEX_DOG_BACK_LEGS_RIGHT[22] =
    {
        0.5f, -0.6f,
        0.46f, -0.6f,
        0.46f, -0.58f,
        0.48f, -0.56f,
        0.48f, -0.54f,
        0.44f, -0.52f,
        0.44f, -0.5f,
        0.5f, -0.5f,
        0.5f, -0.515,
        0.52f, -0.53,
        0.52f, -0.57f,

    };


    float VERTEX_DOG_BACK_LEGS_LEFT[18] =
    {
        0.69f, -0.6f,
        0.65f, -0.6f,
        0.6f, -0.54f,
        0.53f, -0.5f,
        0.5f, -0.47f,
        0.5f, -0.42f,
        0.55f, -0.4f,
        0.6f, -0.45f,
        0.63f, -0.5f,
    };

    float VERTEX_DOG_TAIL[10] =
    {
        0.6f, -0.45f,
        0.64f, -0.37f,
        0.55f, -0.28f,
        0.6f, -0.37f,
        0.55f, -0.4f,
    };

    float VERTEX_DOG_BODY[30] =
    {
        0.55f, -0.4f,
        0.5f, -0.4f,
        0.4f, -0.34f,
        0.4f, -0.26f,
        0.36f, -0.2f,
        0.36f, -0.24f,
        0.345f, -0.24f,
        0.3f, -0.2f,
        0.3f, -0.25f,
        0.27f, -0.23f,
        0.24f, -0.23f,
        0.22f, -0.24f,
        0.22f, -0.29f,
        0.255f, -0.35f,
        0.3f, -0.35f,
    };
};
}
