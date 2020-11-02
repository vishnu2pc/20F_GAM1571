#include "GamePCH.h"

#include "LevelManager.h"

#include "Level.h"

#include "../Events/GameEvents.h"

fw::LevelManager::LevelManager(GameCore* pGameCore)
{
	m_pLevel = new Level;
	m_pGameCore = pGameCore;
}

fw::LevelManager::~LevelManager()
{
	
}

void fw::LevelManager::OnEvent()
{
	
}

void fw::LevelManager::NextLevel()
{
	if (m_pLevel->GetType() != LEVEL_TYPE::THIRD)
	{
		m_pLevel->NextLevel();
		m_pLevel->SetLevelParameters();
	}

	else
	{
		WinEvent* pEvent = new WinEvent();
		m_pGameCore->GetEventManager()->AddEvent(pEvent);
	}
	
}

void fw::LevelManager::ResetLevel()
{
	m_pLevel->SetLevelType(LEVEL_TYPE::FIRST);
	
}

void fw::LevelManager::CheckLevelState()
{
	
}

void fw::LevelManager::InitializeLevel()
{
	m_pLevel->InitializeLevel(m_pGameCore);
}

float fw::LevelManager::GetLevelDuration()
{
	return m_pLevel->GetDuration();
}

float fw::LevelManager::GetEnemySpawnDuration()
{
	return m_pLevel->GetEnemySpawnDuration();
}

LEVEL_TYPE fw::LevelManager::GetLevelType()
{
	return m_pLevel->GetType();
}

void fw::LevelManager::UI(float deltaTime)
{
	
}


