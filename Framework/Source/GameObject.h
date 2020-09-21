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
		
    fw::Mesh* m_pMeshDarkBlue = nullptr;
    fw::Mesh* m_pMeshBlue = nullptr;
    fw::Mesh* m_pMeshSkin = nullptr;
		

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

    float VERTEX_BLUE[72] =
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
    	
    };

  
    }
   
	
};
}
