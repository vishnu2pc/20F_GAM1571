#pragma once

#include "../../Game/Source/Constants.h"

namespace fw {

    class Level
    {
    public:
        Level();
        virtual ~Level();
        LEVEL_TYPE GetType();

        float GetDuration() { return m_Duration; }
        float GetEnemySpawnDuration() { return m_EnemySpawnTimer; }
    	
        void SetLevelType(LEVEL_TYPE level_type);
        void NextLevel();
        void SetLevelParameters();
        void InitializeLevel(GameCore* pGameCore);

    private:
        LEVEL_TYPE m_level_type = LEVEL_TYPE::FIRST;

        float m_Duration = 0;
        float m_EnemySpawnTimer = 0;

        float m_GameArenaSize = 0;
        vec4 m_GameArenaColor;

        float m_EnemySize = 0;
        float m_EnemySpeed = 0;
        vec4 m_EnemyColor;

        float m_PlayerSize = 0;
        float m_PlayerSpeed = 0;
        vec4 m_PlayerColor;
        
    };

    

} // namespace fw