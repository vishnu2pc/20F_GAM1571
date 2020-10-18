#pragma once

class Materials
{
	
public:
	Materials();
	~Materials();

	void AddMesh(fw::Mesh* OuterLayer, fw::Mesh* InnerLayer) { m_OuterLayer_Mesh = OuterLayer; m_InnerLayer_Mesh = InnerLayer; }
	void AddShader(fw::ShaderProgram* pShader) { m_Shader = pShader; }
	void SetColors(vec4 OuterLayer, vec4 InnerLayer) { m_InnerLayer_Color = InnerLayer; m_OuterLayer_Color = OuterLayer; }
	void SetRadius(float radius) { m_radius = radius; }
	void SetNumVertices(int NumVertices) { m_numVertices = NumVertices; }
	
	void Draw(vec2 pos);
	
private:
	fw::Mesh* m_OuterLayer_Mesh;
	fw::Mesh* m_InnerLayer_Mesh;

	fw::ShaderProgram* m_Shader;
	

	float m_radius;
	int m_numVertices;

	vec4 m_InnerLayer_Color;
	vec4 m_OuterLayer_Color;

};