#include "FrameworkPCH.h"

#include "Components/Materials.h"

#include "Objects/Mesh.h"

namespace fw
{
	Materials::Materials(fw::Mesh* pOuterLayer, fw::Mesh* pInnerLayer, fw::ShaderProgram* pShader)
	{
		m_pInnerLayer_Mesh = pOuterLayer;
		m_pOuterLayer_Mesh = pInnerLayer;
		m_pShader = pShader;

		m_numVertices = 3;
	}
	
	Materials::~Materials()
	{
	
	}

	void Materials::Draw(fw::vec2 pos, float radius)
	{
		m_pOuterLayer_Mesh->CreateCircle(radius, m_numVertices);
		m_pInnerLayer_Mesh->CreateCircle(radius - 0.1f, m_numVertices);

		m_pOuterLayer_Mesh->Draw(pos, m_pShader, m_OuterLayer_Color);
		m_pInnerLayer_Mesh->Draw(pos, m_pShader, m_InnerLayer_Color);
	}
}
