#include "GamePCH.h"

#include "Objects/Materials.h"


Materials::Materials()
{
	m_InnerLayer_Mesh = nullptr;
	m_OuterLayer_Mesh = nullptr;
	m_Shader = nullptr;

	m_radius = 1;
	m_numVertices = 3;
}

Materials::~Materials()
{
	
	delete m_InnerLayer_Mesh;
	delete m_OuterLayer_Mesh;
	delete m_Shader;
}

void::Materials::Draw(vec2 pos)
{
	m_InnerLayer_Mesh->CreateCircle(m_radius, m_numVertices);
	m_OuterLayer_Mesh->CreateCircle(m_radius - 0.025f , m_numVertices);

	m_InnerLayer_Mesh->Draw(pos, m_Shader, m_InnerLayer_Color);
	m_OuterLayer_Mesh->Draw(pos, m_Shader, m_OuterLayer_Color);
}