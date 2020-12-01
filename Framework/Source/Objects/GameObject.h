#pragma once

#include "Math/Vector.h"

namespace fw {

class Mesh;
class ShaderProgram;
class GameCore;
class Texture;

class GameObject
{
public:
    GameObject(GameCore* pGameCore, std::string name, vec2 pos, vec2 ObjectScale,Mesh* pMesh, ShaderProgram* pShader, fw::Texture* pTexture);
    virtual ~GameObject();

    virtual void Update(float deltaTime);
    virtual void Draw();

    std::string GetName() { return m_Name; }
    vec2 GetPosition() { return m_Position; }

    void SetTexture(Texture* pTexture) { m_pTexture = pTexture; }

protected:
    GameCore* m_pGameCore = nullptr;

    std::string m_Name;

    vec2 m_Position;
    vec2 m_ObjectScale;
    Mesh* m_pMesh = nullptr;
    ShaderProgram* m_pShader = nullptr;
    Texture* m_pTexture = nullptr;
    vec4 m_Color = vec4(1,1,1,1);

    vec2 m_UVScale = vec2( 1, 1 );
    vec2 m_UVOffset = vec2( 0, 0 );
};

} // namespace fw
