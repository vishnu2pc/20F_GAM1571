#include "GamePCH.h"
#include "Game.h"
#include "Objects/Player.h"
#include "Events/GameEvents.h"


Game::Game(fw::FWCore* pFramework)  :fw::GameCore(pFramework)
{
    
}

Game::~Game()
{
   
}

void Game::Init()
{
    srand(time(0));
	
    m_pImGuiManager = new fw::ImGuiManager(m_pFramework);
    m_pImGuiManager->Init();
	
    m_pEventManager = new fw::EventManager();
    m_pPlayerController = new fw::PlayerController();
	
}


void Game::StartFrame(float deltaTime)
{
    m_pPlayerController->StartFrame();
    m_pEventManager->DispatchAllEvents(this);
}



void Game::OnEvent(fw::Event* pEvent)
{

}

void Game::Update(float deltaTime)
{
    StartFrame(deltaTime);
    m_pPlayer->Update(deltaTime);
}

void Game::Draw()
{
    glClearColor(GameColor.x, GameColor.y, GameColor.z, GameColor.w);
    glClear( GL_COLOR_BUFFER_BIT );

    glPointSize( 10 );

    m_pPlayer->Draw();
   
    m_pImGuiManager->EndFrame();
}

