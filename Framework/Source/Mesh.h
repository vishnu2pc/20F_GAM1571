#pragma once
#include "Framework.h"

namespace fw {

class Mesh
{
public:
    Mesh(float attribs[],int NumVertices, int PrimitiveType, ShaderProgram* pShader);
    virtual ~Mesh();

    void Draw();

protected:
    GLuint m_VBO = 0;

    int m_NumVertices = 0;
    int m_PrimitiveType = GL_POINTS;
    ShaderProgram* m_pShader;
};

} // namespace fw
