#pragma once

class Pathfinder;
class Enemy;
class PlayerController;
class Player;
class SpriteSheet;
class Tilemap;

class Game : public fw::GameCore
{
public:
    Game(fw::FWCore* pFramework);
    virtual ~Game();

    void Init();
    virtual void StartFrame(float deltaTime) override;
    virtual void OnEvent(fw::Event* pEvent) override;
    virtual void Update(float deltaTime) override;
    virtual void Draw() override;
   
    Player* GetPlayer() { return m_pPlayer; }
    Tilemap* GetTileMap() { return m_pTilemap; }

protected:
    fw::ImGuiManager* m_pImGuiManager = nullptr;
    fw::SpriteSheet* m_pSpriteSheet = nullptr;
    PlayerController* m_pPlayerController = nullptr;
    Tilemap* m_pTilemap = nullptr;
    Pathfinder* m_pPathfinder = nullptr;
    std::map<std::string, fw::ShaderProgram*> m_pShaders;
    std::map<std::string, fw::Mesh*> m_pMeshes;
    std::map<std::string, fw::Texture*> m_pTextures;

    Player* m_pPlayer = nullptr;
    Enemy* m_pEnemy = nullptr;
    std::vector<fw::GameObject*> m_Objects;

    // Settings.
    bool m_VSyncEnabled = true;
};
