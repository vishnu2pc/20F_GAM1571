#pragma once

class Game : public fw::GameCore
{
public:
    Game();
    virtual ~Game();

    void Init();
    virtual void Update() override;
    virtual void Draw() override;

protected:
    fw::GameObject* m_Humanoid = nullptr;
};
