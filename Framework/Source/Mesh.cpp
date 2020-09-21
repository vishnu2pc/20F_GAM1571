#include "FrameworkPCH.h"

#include "Mesh.h"
#include <Utility\ShaderProgram.h>

namespace fw {

Mesh::Mesh(float attribs[], int NumVertices, int PrimitiveType)
{
    // Generate a buffer for our vertex attributes.
    glGenBuffers( 1, &m_VBO ); // m_VBO is a GLuint.

    // Set this VBO to be the currently active one.
    glBindBuffer( GL_ARRAY_BUFFER, m_VBO );
    
  
    m_NumVertices = NumVertices;
    m_PrimitiveType = PrimitiveType;
    

    // Copy our attribute data into the VBO.
    int numAttributeComponents = m_NumVertices*2; // x & y for each vertex.
    glBufferData( GL_ARRAY_BUFFER, sizeof(float)*numAttributeComponents, attribs, GL_STATIC_DRAW );
}

Mesh::~Mesh()
{
}

void Mesh::Draw(ShaderProgram* pShader)
{
    glUseProgram(pShader->GetProgram());
	// Set this VBO to be the currently active one.
    glBindBuffer( GL_ARRAY_BUFFER, m_VBO );

    // Get the attribute variable�s location from the shader.
    GLint loc = 0; //glGetAttribLocation( m_pShader->m_Program, "a_Position" );
    glEnableVertexAttribArray( loc );

    // Describe the attributes in the VBO to OpenGL.
    glVertexAttribPointer( loc, 2, GL_FLOAT, GL_FALSE, 8, (void*)0 );

    // Draw the primitive.
    glDrawArrays( m_PrimitiveType, 0, m_NumVertices );
}

} // namespace fw
