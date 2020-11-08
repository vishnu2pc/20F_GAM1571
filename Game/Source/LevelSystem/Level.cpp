#include "GamePCH.h"
#include "Level.h"
#include "Constants.h"

fw::Level::Level()
{
    m_level_type = LEVEL_TYPE::FIRST;
    SetLevelParameters();
}

fw::Level::~Level()
{
}

LEVEL_TYPE fw::Level::GetType()
{
    return m_level_type;
}

void fw::Level::SetLevelType(LEVEL_TYPE level_type)
{
	m_level_type = level_type;
}

void fw::Level::NextLevel()
{
    SetLevelType((LEVEL_TYPE)((int)m_level_type + 1));
}

void fw::Level::SetLevelParameters()
{

    m_Duration = Duration[(int)m_level_type];
    m_EnemySpawnTimer = Spawn_Timer[(int)m_level_type];
    
    m_GameArenaSize = Arena_Radius[(int)m_level_type];
    m_GameArenaColor = Arena_Color[(int)m_level_type];
    
    m_EnemySize = Enemy_Size[(int)m_level_type];
    m_EnemySpeed = Enemy_Speed[(int)m_level_type];
    m_EnemyBehaviour = Enemy_Behaviour[(int)m_level_type];
    m_EnemyColor = Enemy_Color[(int)m_level_type];
    
    m_PlayerSize = Player_Radius[(int)m_level_type];
    m_PlayerSpeed = Player_Speed[(int)m_level_type];
	m_PlayerColor = Player_Color[(int)m_level_type];

	
}

void fw::Level::InitializeLevel(GameCore* pGameCore)
{
    pGameCore->SetLevelDuration(m_Duration);
    pGameCore->SetEnemySpawnDuration(m_EnemySpawnTimer);
    pGameCore->SetEnemyBehaviour(m_EnemyBehaviour);
	
    pGameCore->SetArenaRadius(m_GameArenaSize);
    pGameCore->SetArenaColor(m_GameArenaColor);
	
    pGameCore->SetEnemyRadius(m_EnemySize);
    pGameCore->SetEnemySpeed(m_EnemySpeed);
    pGameCore->SetEnemyColor(m_EnemyColor);
	
    pGameCore->SetPlayerSpeed(m_PlayerSpeed);
    pGameCore->SetPlayerColor(m_PlayerColor);
    pGameCore->SetPlayerRadius(m_PlayerSize);
}
