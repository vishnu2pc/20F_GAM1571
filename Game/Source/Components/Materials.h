#pragma once

class Materials
{
	
public:
	Materials(fw::Mesh* pOuterLayer, fw::Mesh* pInnerLayer, fw::ShaderProgram* pShader);
	~Materials();

	void SetColors(vec4 OuterLayer, vec4 InnerLayer) { m_OuterLayer_Color = OuterLayer; m_InnerLayer_Color = InnerLayer; }
	void SetNumVertices(int NumVertices) { m_numVertices = NumVertices; }
	void Draw(vec2 pos, float radius);
	
private:
	fw::Mesh* m_pOuterLayer_Mesh;
	fw::Mesh* m_pInnerLayer_Mesh;

	fw::ShaderProgram* m_pShader;
	

	
	int m_numVertices;

	vec4 m_InnerLayer_Color;
	vec4 m_OuterLayer_Color;

};