#pragma once


namespace fw {
	class ShaderProgram;

    class Mesh
{
public:
    Mesh(float attribs[],int NumVertices, int PrimitiveType);
    virtual ~Mesh();

    void Draw(ShaderProgram* m_pShader);

protected:
    GLuint m_VBO = 0;

    int m_NumVertices = 0;
    int m_PrimitiveType = GL_POINTS;
    
};

} // namespace fw
