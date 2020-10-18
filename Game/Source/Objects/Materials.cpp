#include "GamePCH.h"

#include "Objects/Materials.h"

Materials::Materials()
{
	m_InnerLayer_Shader = nullptr;
	m_InnerLayer_Mesh = nullptr;
	m_OuterLayer_Mesh = nullptr;
	m_OuterLayer_Shader = nullptr;
}

Materials::~Materials()
{
	delete m_InnerLayer_Shader;
	delete m_InnerLayer_Mesh;
	delete m_OuterLayer_Mesh;
	delete m_OuterLayer_Shader;
}

void::Materials::Draw(vec2 pos)
{
	m_InnerLayer_Mesh->Draw(pos, m_InnerLayer_Shader);
	m_OuterLayer_Mesh->Draw(pos, m_OuterLayer_Shader);
	
}