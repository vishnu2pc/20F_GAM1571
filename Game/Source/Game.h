#pragma once


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

    void Timer(float deltaTime);
    void SpawnEnemy();
    void HandleImGui(float deltaTime);
    void UpdateLevel();
		
protected:

    std::vector<fw::GameObject*> m_pEnemies;
    fw::ImGuiManager* m_pImGuiManager = nullptr;

	
    Player* m_pPlayer = nullptr;
    GameArena* m_pGameArena = nullptr;

    fw::ShaderProgram* m_pShader = nullptr;
    fw::Mesh* m_pOuterMesh = nullptr;
    fw::Mesh* m_pInnerMesh = nullptr;
	
    fw::Materials* m_pPlayerMaterial = nullptr;
    fw::Materials* m_pGameArenaMaterial = nullptr;
    
	
    fw::PhysicsController* m_pPlayerPhysicsController = nullptr;
    fw::PhysicsController* m_pGameArenaPhysicsController = nullptr;
    

    int m_pGameArenaNumVertices =100;
    int m_pPlayerVelocity = 5;
    float m_Timer = 0;

};


