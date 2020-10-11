#pragma once
#include "Math/Vector.h"

namespace fw {
	class ShaderProgram;

    class Mesh
{
public:
    Mesh();
    Mesh(const float attribs[],int NumVertices, int PrimitiveType);
    virtual ~Mesh();

    void CreateShape(const float attribs[], int NumVertices, int PrimitiveType);
    void Draw(vec2 pos, ShaderProgram* pShader);
    void SetUniform2f(ShaderProgram* pShader, char* name, vec2 value);

protected:
    GLuint m_VBO = 0;

    int m_NumVertices = 0;
    int m_PrimitiveType = GL_POINTS;
    
    
};

} // namespace fw
