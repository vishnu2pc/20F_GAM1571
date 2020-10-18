#pragma once
class PlayerController;
class Game : public fw::GameCore
{
    
public:
    Game(fw::FWCore* pFramework);
    virtual ~Game();

    void Init();
    virtual void OnEvent(fw::Event* pEvent) override;
    virtual void Update(float deltaTime) override;
    virtual void Draw() override;


protected:
    
	std::vector<fw::GameObject*> m_GameObjects;
    fw::ImGuiManager* m_pImGuiManager = nullptr;
    
    PlayerController* m_pPlayerController = nullptr;
};
