#include "GamePCH.h"
#include "Game.h"
#include "Objects/Player.h"

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
    m_pShader_DarkBlue = new fw::ShaderProgram("Data/Basic.vert", "Data/DarkBlue.frag");
    m_pShader_Blue = new fw::ShaderProgram("Data/Basic.vert", "Data/Blue.frag");
    m_pShader_Skin = new fw::ShaderProgram("Data/Basic.vert", "Data/Skin.frag");
    m_pShader_Black = new fw::ShaderProgram("Data/Basic.vert", "Data/Black.frag");
    m_pShader_White = new fw::ShaderProgram("Data/Basic.vert", "Data/White.frag");
    m_pShader_Red = new fw::ShaderProgram("Data/Basic.vert", "Data/Red.frag");

    m_GameArea_Shaders.push_back(m_pShader_Blue);
    m_GameArea_Shaders.push_back(m_pShader_White);

    m_Player_Shaders.push_back(m_pShader_Red);
	
    m_GameArea_Outer = new fw::Mesh();
    m_GameArea_Outer->CreateCircle(4.0f, 50);
    m_GameArea_Inner = new fw::Mesh();
    m_GameArea_Inner->CreateCircle(3.925f, 50);

    m_Player_mesh = new fw::Mesh();
    m_Player_mesh->CreateCircle( 0.25f, 50);

    m_GameArea_Meshes.push_back(m_GameArea_Outer);
    m_GameArea_Meshes.push_back(m_GameArea_Inner);

    m_Player_Meshes.push_back(m_Player_mesh);
    m_pImGuiManager = new fw::ImGuiManager(m_pFramework);
    m_pImGuiManager->Init();

    m_GameObjects.push_back(new fw::GameObject(vec2(5, 5), GAME_AREA, m_GameArea_Meshes, m_GameArea_Shaders, this));
    m_GameObjects.push_back(new Player(vec2(5, 5), PLAYER, m_Player_Meshes, m_Player_Shaders, this));
}

void Game::Update(float deltaTime)
{
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
