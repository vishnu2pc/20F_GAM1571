#pragma once


namespace fw {
	class ShaderProgram;

    class Mesh
{
public:
    Mesh();
    Mesh(float attribs[],int NumVertices, int PrimitiveType, ShaderProgram* pShader);
    virtual ~Mesh();

    void CreateShape(float attribs[], int NumVertices, int PrimitiveType, ShaderProgram* pShader);
    void Draw(float x, float y);
    void SetUniform1f(ShaderProgram* pShader, char* name, float value);

protected:
    GLuint m_VBO = 0;

    int m_NumVertices = 0;
    int m_PrimitiveType = GL_POINTS;
    ShaderProgram* m_pShader;
    
};

} // namespace fw
