#pragma once

class PlayerController;
class SpriteSheet;

enum class PlayerState
{
	IDLE,
	MOVE_LEFT,
	MOVE_RIGHT,
	MOVE_UP,
	MOVE_DOWN
};



static const int frames = 3;
static const int duration = 1;
static const float delay = (float)duration / (float)frames;

static std::string WalkLeft[frames] = { "Player/player_14",
										"Player/player_15",
										"Player/player_16" };


static std::string WalkRight[frames] = { "Player/player_11",
										"Player/player_12",
										"Player/player_13" };

static std::string WalkDown[frames] = { "Player/player_06",
										"Player/player_07",
										"Player/player_06" };

static std::string WalkUp[frames] = { "Player/player_08",
										"Player/player_09",
										"Player/player_10" };

static std::string Idle[frames] = { "Player/player_05" };
class Player : public fw::GameObject
{
public:
	
    Player(fw::GameCore* pGameCore, PlayerController* pPlayerController, fw::SpriteSheet* pSpriteSheet, std::string name, vec2 pos, fw::Mesh* pMesh, fw::ShaderProgram* pShader, fw::Texture* pTexture, vec4 color);
    virtual ~Player();

    virtual void Update(float deltaTime) override;

protected:
    PlayerController* m_pPlayerController = nullptr;
    fw::SpriteSheet* m_pSpriteSheet = nullptr;
    fw::SpriteInfo m_SpriteInfo;
	PlayerState m_PlayerState = PlayerState::IDLE;
	float m_Timer = 0;
	int framecount = 0;
	
	
};
