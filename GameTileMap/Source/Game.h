#pragma once


namespace fw {
	class LevelManager;
}

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
	
	
protected:
	
    fw::ImGuiManager* m_pImGuiManager = nullptr;
    Player* m_pPlayer = nullptr;
    vec4 GameColor = vec4::Grey();

  

};


