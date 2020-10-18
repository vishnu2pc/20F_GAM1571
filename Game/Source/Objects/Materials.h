#pragma once

class Materials
{
public:
	Materials();
	~Materials();

	void AddMesh(fw::Mesh* OuterLayer, fw::Mesh* InnerLayer) { m_OuterLayer_Mesh = OuterLayer; m_InnerLayer_Mesh = InnerLayer; }
	void AddShader(fw::ShaderProgram* OuterLayer, fw::ShaderProgram* InnerLayer) { m_OuterLayer_Shader = OuterLayer; m_InnerLayer_Shader = InnerLayer; }

	void Draw(vec2 pos);
	
private:
	fw::Mesh* m_OuterLayer_Mesh;
	fw::Mesh* m_InnerLayer_Mesh;

	fw::ShaderProgram* m_OuterLayer_Shader;
	fw::ShaderProgram* m_InnerLayer_Shader;
	
};