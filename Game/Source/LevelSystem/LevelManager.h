#pragma once

namespace fw {

    class Level;
    class GameCore;

    class LevelManager
    {
    public:
        LevelManager(GameCore* pGameCore);
        ~LevelManager();

        void OnEvent();
        void NextLevel();
        void ResetLevel();
        void CheckLevelState();
        void InitializeLevel();
        
        float GetLevelDuration();
        float GetEnemySpawnDuration();
        LEVEL_TYPE GetLevelType();

        void UI(float deltaTime);
    protected:
        Level* m_pLevel = nullptr;
        GameCore* m_pGameCore;
    	
    };

} // namespace fw