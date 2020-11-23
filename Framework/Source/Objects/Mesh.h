#pragma once
#include "Math/Vector.h"

namespace fw {
	class ShaderProgram;
	
    struct VertexFormat
    {
        float x;
        float y;
        float u;
        float v;
    };

	enum class GameProject
	{
		Game,
		GameTileMap
	};
    class Mesh
{
public:
    Mesh();
    Mesh(const float attribs[],int NumVertices, int PrimitiveType);
    Mesh(const VertexFormat* pVertices, int numVertices, int PrimitiveType);
    virtual ~Mesh();

    void CreateShape(const float attribs[], int NumVertices, int PrimitiveType);
    void CreateShape(const vec2 attribs[], int NumVertices, int PrimitiveType);
    void CreateShape(const VertexFormat* pVertices, int NumVertices, int PrimitiveType);
    	
    void Draw(vec2 pos, ShaderProgram* pShader, vec4 color);
    	
    void SetUniform2f(ShaderProgram* pShader, char* name, vec2 value);
    void SetUniform4f(ShaderProgram* pShader, char* name, vec4 value);
    	
    void CreateCircle(float radius, int num_points);
    	
protected:
    GLuint m_VBO = 0;

    int m_NumVertices = 0;
    int m_PrimitiveType = GL_POINTS;
    
    GameProject m_GameProject = GameProject::GameTileMap;
};

} // namespace fw
