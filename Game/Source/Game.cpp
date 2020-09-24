#include "Framework.h"
#include "Game.h"
#include <iostream>

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
	
    m_GameObjects.push_back(new fw::GameObject(HUMANOID));
    m_GameObjects.push_back(new fw::GameObject(ANIMAL));
	
}

void Game::Update(float deltaTime)
{
    m_pImGuiManager->StartFrame(deltaTime);
    ImGui::ShowDemoWindow();
    
}

void Game::Draw()
{
    glClearColor( 0, 0, 0, 0 );
    glClear( GL_COLOR_BUFFER_BIT );

    glPointSize( 10 );
	
   
    for(int i=0; i<m_GameObjects.size();i++)
    {
        m_GameObjects[i]->Draw();
    }

    m_pImGuiManager->EndFrame();
}
