#include "GamePCH.h"

#include "Components/Materials.h"


Materials::Materials()
{
	m_pInnerLayer_Mesh = nullptr;
	m_pOuterLayer_Mesh = nullptr;
	m_pShader = nullptr;

	m_radius = 1;
	m_numVertices = 3;
}

Materials::~Materials()
{
	
	delete m_pInnerLayer_Mesh;
	delete m_pOuterLayer_Mesh;
	delete m_pShader;
}

void::Materials::Draw(vec2 pos)
{
	m_pInnerLayer_Mesh->CreateCircle(m_radius, m_numVertices);
	m_pOuterLayer_Mesh->CreateCircle(m_radius - 0.025f , m_numVertices);

	m_pInnerLayer_Mesh->Draw(pos, m_pShader, m_InnerLayer_Color);
	m_pOuterLayer_Mesh->Draw(pos, m_pShader, m_OuterLayer_Color);
}