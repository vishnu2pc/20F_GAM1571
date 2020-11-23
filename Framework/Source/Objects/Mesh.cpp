#include "FrameworkPCH.h"
#include "Mesh.h"


#include "Utility\ShaderProgram.h"
namespace fw {
	
Mesh::Mesh()
{
		
}

Mesh::Mesh(const float attribs[], int NumVertices, int PrimitiveType)
{
    CreateShape( attribs, NumVertices, PrimitiveType);
}

Mesh::Mesh(const VertexFormat* pVertices, int numVertices, int PrimitiveType)
{
    CreateShape(pVertices, numVertices, PrimitiveType);
}



Mesh::~Mesh()
{
    glDeleteBuffers(1, &m_VBO);
	

}

void Mesh::CreateShape(const float attribs[], int NumVertices, int PrimitiveType)
{
    if (m_VBO == 0)
    {
        // Generate a buffer for our vertex attributes.
        glGenBuffers(1, &m_VBO); // m_VBO is a GLuint.
    }
	
    // Set this VBO to be the currently active one.
    glBindBuffer(GL_ARRAY_BUFFER, m_VBO);


    m_NumVertices = NumVertices;
    m_PrimitiveType = PrimitiveType;
    

    // Copy our attribute data into the VBO.
    int numAttributeComponents = m_NumVertices * 2; // x & y for each vertex.
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * numAttributeComponents, attribs, GL_STATIC_DRAW);
	
}

void Mesh::CreateShape(const vec2 attribs[], int NumVertices, int PrimitiveType)
{
    if (m_VBO == 0)
    {
        // Generate a buffer for our vertex attributes.
        glGenBuffers(1, &m_VBO); // m_VBO is a GLuint.
    }

    // Set this VBO to be the currently active one.
    glBindBuffer(GL_ARRAY_BUFFER, m_VBO);


    m_NumVertices = NumVertices;
    m_PrimitiveType = PrimitiveType;


    // Copy our attribute data into the VBO.
    int numAttributeComponents = m_NumVertices * 2; // x & y for each vertex.
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * numAttributeComponents, attribs, GL_STATIC_DRAW);
}

void Mesh::CreateShape(const VertexFormat* pVertices, int NumVertices, int PrimitiveType)
{

    if (m_VBO == 0)
    {
        // Generate a buffer for our vertex attributes.
        glGenBuffers(1, &m_VBO); // m_VBO is a GLuint.
    }

    // Set this VBO to be the currently active one.
    glBindBuffer(GL_ARRAY_BUFFER, m_VBO);


    m_NumVertices = NumVertices;
    m_PrimitiveType = PrimitiveType;


    // Copy our attribute data into the VBO.
    glBufferData(GL_ARRAY_BUFFER, sizeof(VertexFormat) * m_NumVertices, pVertices, GL_STATIC_DRAW);
}
	
void Mesh::SetUniform2f(ShaderProgram* pShader, char* name, vec2 value)
{
    int loc = glGetUniformLocation(pShader->GetProgram(), name);
    glUniform2f(loc, value.x, value.y);
}

void Mesh::CreateCircle(float radius, int num_points)
{
    m_GameProject = GameProject::Game;
    std::vector<vec2> m_Circle_Vertices;
   
    for (int i = 0; i <= num_points; i++)
    {
    	
        m_Circle_Vertices.push_back(vec2(0, 0));
    	
        const float angle = (2*(float)M_PI / num_points) * i;
        const vec2 Vertex = vec2(cosf(angle), sinf(angle)) * radius;

        m_Circle_Vertices.push_back(Vertex);
        
    }
	
    CreateShape(&m_Circle_Vertices[0], m_Circle_Vertices.size(), GL_TRIANGLE_STRIP);
}
	
void Mesh::SetUniform4f(ShaderProgram* pShader, char* name, vec4 value)
{
    int loc = glGetUniformLocation(pShader->GetProgram(), name);
    glUniform4f(loc, value.x, value.y, value.z, value.w);
}
	
void Mesh::Draw(vec2 pos, ShaderProgram* pShader, vec4 color)
{
    glUseProgram(pShader->GetProgram());

    // Set this VBO to be the currently active one.
    glBindBuffer(GL_ARRAY_BUFFER, m_VBO);

    // Get the attribute variable’s location from the shader.
    GLint loc = 0; //glGetAttribLocation( m_pShader->m_Program, "a_Position" );
    glEnableVertexAttribArray(loc);

    // Describe the attributes in the VBO to OpenGL.
	if (m_GameProject == GameProject::GameTileMap)
    glVertexAttribPointer(loc, 2, GL_FLOAT, GL_FALSE, 16, (void*)0);
    else
        glVertexAttribPointer(loc, 2, GL_FLOAT, GL_FALSE, 8, (void*)0);

		
    // Setup our uniforms.
    {
        SetUniform2f(pShader, "u_ObjectPos", pos);
        SetUniform4f(pShader, "u_Color", color);
    }
    // Draw the primitive.
    glDrawArrays(m_PrimitiveType, 0, m_NumVertices);
	
}

} // namespace fw
