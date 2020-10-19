#include "GamePCH.h"

#include "Game.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    fw::FWCore* pFramework = new fw::FWCore();
    pFramework->Init(1000, 1000);

	Game* pGame = new Game(pFramework);
    pGame->Init();

	
    pFramework->Run( pGame );
    pFramework->Shutdown();


	
    delete pGame;
    delete pFramework;
}
