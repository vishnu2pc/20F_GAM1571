#include "FrameworkPCH.h"
#include "Mesh.h"
#include "Objects/Texture.h"
#include "Utility/ShaderProgram.h"
#include "Utility/Helpers.h"
namespace fw {

    Mesh::Mesh()
    {

    }

    Mesh::Mesh(const float attribs[], int NumVertices, int PrimitiveType)
    {
        CreateShape(attribs, NumVertices, PrimitiveType);
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

    void Mesh::SetUniform1f(ShaderProgram* pShader, char* name, float value)
    {
        int loc = glGetUniformLocation(pShader->GetProgram(), name);
        glUniform1f(loc, value);
    }

    void Mesh::SetUniform2f(ShaderProgram* pShader, char* name, vec2 value)
    {
        int loc = glGetUniformLocation(pShader->GetProgram(), name);
        glUniform2f(loc, value.x, value.y);
    }

    void Mesh::SetUniform4f(ShaderProgram* pShader, char* name, vec4 value)
    {
        int loc = glGetUniformLocation(pShader->GetProgram(), name);
        glUniform4f(loc, value.x, value.y, value.z, value.w);
    }

    void Mesh::SetUniform1i(ShaderProgram* pShader, char* name, int value)
    {
        int loc = glGetUniformLocation(pShader->GetProgram(), name);
        glUniform1i(loc, value);
    }

    void Mesh::CreateCircle(float radius, int num_points)
    {
        m_GameProject = GameProject::Game;
        std::vector<vec2> m_Circle_Vertices;

        for (int i = 0; i <= num_points; i++)
        {

            m_Circle_Vertices.push_back(vec2(0, 0));

            const float angle = (2 * (float)M_PI / num_points) * i;
            const vec2 Vertex = vec2(cosf(angle), sinf(angle)) * radius;

            m_Circle_Vertices.push_back(Vertex);

        }

        CreateShape(&m_Circle_Vertices[0], m_Circle_Vertices.size(), GL_TRIANGLE_STRIP);
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

    void Mesh::Draw(vec2 pos, ShaderProgram* pShader, Texture* pTexture, vec4 color, vec2 UVScale, vec2 UVOffset)
    {
        glUseProgram(pShader->GetProgram());

        // Set this VBO to be the currently active one.
        glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
        // Get the attribute variable’s location from the shader.
        GLint loc = glGetAttribLocation(pShader->GetProgram(), "a_Position");
        if (loc != -1)
        {
            glEnableVertexAttribArray(loc);
            glVertexAttribPointer(loc, 2, GL_FLOAT, GL_FALSE, 16, (void*)0);
        }
        loc = glGetAttribLocation(pShader->GetProgram(), "a_UVCoord");
        if (loc != -1)
        {
            glEnableVertexAttribArray(loc);
            glVertexAttribPointer(loc, 2, GL_FLOAT, GL_FALSE, 16, (void*)8);
        }
        // Setup our uniforms.
        {
            SetUniform1f(pShader, "u_Time", (float)GetSystemTimeSinceGameStart());
            SetUniform2f(pShader, "u_ObjectPos", pos);
            SetUniform4f(pShader, "u_Color", color);

            SetUniform2f(pShader, "u_UVScale", UVScale);
            SetUniform2f(pShader, "u_UVOffset", UVOffset);

            if (pTexture != nullptr)
            {
                glActiveTexture(GL_TEXTURE0);
                glBindTexture(GL_TEXTURE_2D, pTexture->GetHandle());
                SetUniform1i(pShader, "u_Texture", 0);
            }
        }
        // Draw the primitive.
        glDrawArrays(m_PrimitiveType, 0, m_NumVertices);
    }
    }

}