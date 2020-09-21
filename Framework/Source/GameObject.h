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
    fw::ShaderProgram* m_pShader_Blue = nullptr;
    fw::ShaderProgram* m_pShader_DarkBlue = nullptr;
    fw::ShaderProgram* m_pShader_Skin = nullptr;
    fw::ShaderProgram* m_pShader_Face = nullptr;
		
		
    fw::Mesh* m_pMeshDarkBlue = nullptr;
    fw::Mesh* m_pMeshBlue = nullptr;
    fw::Mesh* m_pMeshSkin = nullptr;
    fw::Mesh* m_pMeshFace = nullptr;

    float VERTEX_DARK_BLUE[108] =
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

    float VERTEX_BLUE[84] =
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
		
    float VERTEX_SKIN[36]
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

    float VERTEX_FACE[72]
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
   
	
};
}
