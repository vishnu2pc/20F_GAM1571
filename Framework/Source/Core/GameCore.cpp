#include "FrameworkPCH.h"

#include "GameCore.h"

namespace fw {

GameCore::GameCore(FWCore* pFramework)
{
	m_pFramework = pFramework;
}

GameCore::~GameCore()
{
	
}

void GameCore::StartFrame(float deltaTime)
{
}
} // namespace fw
