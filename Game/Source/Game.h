#pragma once

class Game : public fw::GameCore
{
    
public:
    Game(fw::FWCore* pFramework);
    virtual ~Game();

    void Init();
    virtual void Update(float deltaTime) override;
    virtual void Draw() override;

protected:
    std::vector<fw::GameObject*> m_GameObjects;
    fw::ImGuiManager* m_pImGuiManager = nullptr;
};
