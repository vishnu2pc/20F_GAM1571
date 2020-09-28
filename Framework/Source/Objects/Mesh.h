#pragma once


namespace fw {
	class ShaderProgram;

    class Mesh
{
public:
    Mesh();
    Mesh(float attribs[],int NumVertices, int PrimitiveType);
    virtual ~Mesh();

    void CreateShape(float attribs[], int NumVertices, int PrimitiveType);
    void Draw(float x, float y, ShaderProgram* pShader);
    void SetUniform1f(ShaderProgram* pShader, char* name, float value);

protected:
    GLuint m_VBO = 0;

    int m_NumVertices = 0;
    int m_PrimitiveType = GL_POINTS;
    
    
};

} // namespace fw
