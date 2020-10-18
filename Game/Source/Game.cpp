#include "GamePCH.h"
#include "Game.h"
#include "Objects/Player.h"
#include "Components/PlayerController.h"
#include "Events/GameEvents.h"

Game::Game(fw::FWCore* pFramework)  :fw::GameCore(pFramework)
{
    
}

Game::~Game()
{
    for (int i = 0; i < m_GameObjects.size(); i++)
    {
       delete m_GameObjects[i];
    }

   

    delete m_pImGuiManager;
}

void Game::Init()
{
  
    m_pImGuiManager = new fw::ImGuiManager(m_pFramework);
    m_pImGuiManager->Init();
	
    m_pEventManager = new fw::EventManager();
    m_pPlayerController = new PlayerController();
	
}

void Game::OnEvent(fw::Event* pEvent)
{
    m_pPlayerController->OnEvent(pEvent);

    
}

void Game::Update(float deltaTime)
{
    m_pEventManager->DispatchAllEvents(this);
	
	m_pImGuiManager->StartFrame(deltaTime);
    ImGui::ShowDemoWindow();

	
    for (int i = 0; i < m_GameObjects.size(); i++)
    {
        m_GameObjects[i]->Update(deltaTime);
    }
}

void Game::Draw()
{
    glClearColor( 1, 10, 1, 1 );
    glClear( GL_COLOR_BUFFER_BIT );

    glPointSize( 10 );
	
    
    for(int i=0; i<m_GameObjects.size();i++)
    {
        m_GameObjects[i]->Draw();
    }

    m_pImGuiManager->EndFrame();

   
}
