#pragma once
class PlayerController;
class Materials;
class PhysicsController;
class Player;
class Enemy;
class GameArena;

class Game : public fw::GameCore
{
    
public:
    Game(fw::FWCore* pFramework);
    virtual ~Game();

    void Init();
    void CheckCollision();
    virtual void OnEvent(fw::Event* pEvent) override;
    virtual void Update(float deltaTime) override;
    virtual void Draw() override;


protected:

    std::vector<fw::GameObject*> m_pGameObjects;
    fw::ImGuiManager* m_pImGuiManager = nullptr;

	
    Player* m_pPlayer = nullptr;
    GameArena* m_pGameArena = nullptr;

    fw::ShaderProgram* m_pShader = nullptr;
    fw::Mesh* m_pOuterMesh = nullptr;
    fw::Mesh* m_pInnerMesh = nullptr;

    PlayerController* m_pPlayerController = nullptr;
	
    Materials* m_pPlayerMaterial = nullptr;
    Materials* m_pGameArenaMaterial = nullptr;
	
    PhysicsController* m_pPlayerPhysicsController = nullptr;
    PhysicsController* m_pGameArenaPhysicsController = nullptr;

    
};
