#pragma once

class SpriteSheet;
class Pathfinder;

enum class EnemyState
{
	IDLE,
	MOVE_LEFT,
	MOVE_RIGHT,
	MOVE_UP,
	MOVE_DOWN
};


class Enemy : public fw::GameObject
{
public:
	
	Enemy(fw::GameCore* pGameCore, fw::SpriteSheet* pSpriteSheet, Pathfinder* pPathfinder, std::string name, vec2 pos, vec2 ObjectScale, fw::Mesh* pMesh, fw::ShaderProgram* pShader, fw::Texture* pTexture);
    virtual ~Enemy();

    virtual void Update(float deltaTime) override;

protected:
    
    fw::SpriteSheet* m_pSpriteSheet = nullptr;
	Pathfinder* m_pPathfinder = nullptr;
    fw::SpriteInfo m_SpriteInfo;
	EnemyState m_PlayerState = EnemyState::IDLE;
	float m_Timer = 0;
	vec2 m_ObjectScale;
	int framecount = 0;
	float delay = 0.5f;
	int m_TileIndex;
	float m_correction_offset = 0.5f;
	
};
