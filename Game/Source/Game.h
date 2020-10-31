#pragma once


class Enemy;
class GameArena;
class Player;

class Game : public fw::GameCore
{
    
public:
    Game(fw::FWCore* pFramework);
    virtual ~Game();

    void Init();
    virtual void OnEvent(fw::Event* pEvent) override;
    virtual void Update(float deltaTime) override;
    virtual void Draw() override;
    virtual void StartFrame(float deltaTime) override;
	
    void Timer(float deltaTime);
    void SpawnEnemy();
    void DeleteEnemy(fw::Event* pEvent);
    void HandleImGui(float deltaTime);
   
    void UpdateLevel(float deltaTime);
protected:

    std::vector<fw::GameObject*> m_pEnemies;
    fw::ImGuiManager* m_pImGuiManager = nullptr;

	
    Player* m_pPlayer = nullptr;
    GameArena* m_pGameArena = nullptr;
    Enemy* m_pEnemy = nullptr;

    fw::ShaderProgram* m_pShader = nullptr;
    fw::Mesh* m_pOuterMesh = nullptr;
    fw::Mesh* m_pInnerMesh = nullptr;
	
    fw::Materials* m_pPlayerMaterial = nullptr;
    fw::Materials* m_pGameArenaMaterial = nullptr;
    fw::Materials* m_pEnemyMaterial = nullptr;
	
    fw::PhysicsController* m_pPlayerPhysicsController = nullptr;
    fw::PhysicsController* m_pGameArenaPhysicsController = nullptr;
    fw::PhysicsController* m_pEnemyPhysicsController = nullptr;

    int m_GameArenaNumVertices =100;
    int m_EnemyNumVertices = 100;
    int m_PlayerNumVertices = 100;
    int m_PlayerVelocity = 5;
    float m_PlayerRadiusControl = 0.4f;
    float m_ArenaRadiusControl = 4.0f;
    float m_EnemyRadiusControl = 0.2f;
	
    float m_Timer = 1;

    vec4 PlayerOuterColor = vec4::Black();
    vec4 PlayerInnerColor = vec4::Red();
    vec4 ArenaOuterColor = vec4::Blue();
    vec4 ArenaInnerColor = vec4::White();
    vec4 EnemyColor = vec4::LightBlue();
    vec4 GameColor = vec4::Grey();
	
};


