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

    for (int i = 0; i < m_MegaManMesh.size(); i++)
    {
        delete m_MegaManMesh[i];
    }

    for (int i = 0; i < m_DiamondDogMesh.size(); i++)
    {
        delete m_DiamondDogMesh[i];
    }
	
    delete m_pImGuiManager;
	
    delete m_pShader_DarkBlue;
    delete m_pShader_Blue;
    delete m_pShader_Face;
    delete m_pShader_Skin;
}

void Game::Init()
{
    m_pShader_DarkBlue = new fw::ShaderProgram("Data/Basic.vert", "Data/DarkBlue.frag");
    m_pShader_Blue = new fw::ShaderProgram("Data/Basic.vert", "Data/Blue.frag");
    m_pShader_Skin = new fw::ShaderProgram("Data/Basic.vert", "Data/Skin.frag");
    m_pShader_Face = new fw::ShaderProgram("Data/Basic.vert", "Data/Black.frag");

	m_MegaManMesh.push_back(new fw::Mesh(VERTEX_MM_DARK_BLUE, 54, GL_TRIANGLES, m_pShader_DarkBlue));
    m_MegaManMesh.push_back(new fw::Mesh(VERTEX_MM_BLUE, 42, GL_TRIANGLES, m_pShader_Blue));
    m_MegaManMesh.push_back(new fw::Mesh(VERTEX_MM_SKIN, 18, GL_TRIANGLES, m_pShader_Skin));
    m_MegaManMesh.push_back(new fw::Mesh(VERTEX_MM_FACE, 24, GL_TRIANGLES, m_pShader_Face));

    m_DiamondDogMesh.push_back(new fw::Mesh(VERTEX_DOG_FRONT_LEGS_RIGHT, 11, GL_LINE_LOOP, m_pShader_Skin));
    m_DiamondDogMesh.push_back(new fw::Mesh(VERTEX_DOG_FRONT_LEGS_LEFT, 11, GL_LINE_LOOP, m_pShader_Skin));
    m_DiamondDogMesh.push_back(new fw::Mesh(VERTEX_DOG_BACK_LEGS_RIGHT, 11, GL_LINE_LOOP, m_pShader_Skin));
    m_DiamondDogMesh.push_back(new fw::Mesh(VERTEX_DOG_BACK_LEGS_LEFT, 9, GL_LINE_LOOP, m_pShader_Skin));
    m_DiamondDogMesh.push_back(new fw::Mesh(VERTEX_DOG_TAIL, 5, GL_LINE_LOOP, m_pShader_Skin));
    m_DiamondDogMesh.push_back(new fw::Mesh(VERTEX_DOG_BODY, 15, GL_LINE_STRIP, m_pShader_Skin));

    m_GameObjects.push_back(new fw::GameObject(0.0f, 0.0f, HUMANOID, m_MegaManMesh));
    m_GameObjects.push_back(new fw::GameObject(0.0f, 0.0f, ANIMAL, m_DiamondDogMesh));
	
	m_pImGuiManager = new fw::ImGuiManager(m_pFramework);
    m_pImGuiManager->Init();
	
    
   
	
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
