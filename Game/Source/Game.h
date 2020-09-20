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
    std::vector<fw::GameObject> m_GameObjects;
};
