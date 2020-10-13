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

    for (int i = 0; i < m_MegaManMesh.size(); i++)
    {
        delete m_MegaManMesh[i];
    }

    for (int i = 0; i < m_DiamondDogMesh.size(); i++)
    {
        delete m_DiamondDogMesh[i];
    }
	
    for (int i = 0; i < m_pShaders.size(); i++)
    {
        delete m_pShaders[i];
    }

    delete m_pImGuiManager;
}

void Game::Init()
{
    m_pShader_DarkBlue = new fw::ShaderProgram("Data/Basic.vert", "Data/DarkBlue.frag");
    m_pShader_Blue = new fw::ShaderProgram("Data/Basic.vert", "Data/Blue.frag");
    m_pShader_Skin = new fw::ShaderProgram("Data/Basic.vert", "Data/Skin.frag");
    m_pShader_Black = new fw::ShaderProgram("Data/Basic.vert", "Data/Black.frag");
	
	m_pShaders.push_back(m_pShader_DarkBlue);
    m_pShaders.push_back(m_pShader_Blue);
    m_pShaders.push_back(m_pShader_Skin);
    m_pShaders.push_back(m_pShader_Black);

	m_MegaManMesh.push_back(new fw::Mesh(VERTEX_MM_DARK_BLUE, VERTEX_MM_DARK_BLUE_NUM_VERTICES, VERTEX_MM_DARK_BLUE_MESH_TYPE));
    m_MegaManMesh.push_back(new fw::Mesh(VERTEX_MM_BLUE, VERTEX_MM_BLUE_NUM_VERTICES, VERTEX_MM_BLUE_MESH_TYPE));
    m_MegaManMesh.push_back(new fw::Mesh(VERTEX_MM_SKIN, VERTEX_MM_SKIN_NUM_VERTICES, VERTEX_MM_SKIN_MESH_TYPE));
    m_MegaManMesh.push_back(new fw::Mesh(VERTEX_MM_FACE, VERTEX_MM_FACE_NUM_VERTICES, VERTEX_MM_FACE_MESH_TYPE));

    m_DiamondDogMesh.push_back(new fw::Mesh(VERTEX_DOG_FRONT_LEGS_RIGHT, VERTEX_DOG_FRONT_LEGS_RIGHT_NUM_VERTICES, VERTEX_DOG_FRONT_LEGS_RIGHT_MESH_TYPE));
    m_DiamondDogMesh.push_back(new fw::Mesh(VERTEX_DOG_FRONT_LEGS_LEFT, VERTEX_DOG_FRONT_LEGS_LEFT_NUM_VERTICES, VERTEX_DOG_FRONT_LEGS_LEFT_MESH_TYPE));
    m_DiamondDogMesh.push_back(new fw::Mesh(VERTEX_DOG_BACK_LEGS_RIGHT, VERTEX_DOG_BACK_LEGS_RIGHT_NUM_VERTICES, VERTEX_DOG_BACK_LEGS_RIGHT_MESH_TYPE));
    m_DiamondDogMesh.push_back(new fw::Mesh(VERTEX_DOG_BACK_LEGS_LEFT, VERTEX_DOG_BACK_LEGS_LEFT_NUM_VERTICES, VERTEX_DOG_BACK_LEGS_LEFT_MESH_TYPE));
    m_DiamondDogMesh.push_back(new fw::Mesh(VERTEX_DOG_TAIL, VERTEX_DOG_TAIL_NUM_VERTICES, VERTEX_DOG_TAIL_MESH_TYPE));
    m_DiamondDogMesh.push_back(new fw::Mesh(VERTEX_DOG_BODY, VERTEX_DOG_BODY_NUM_VERTICES, VERTEX_DOG_BODY_MESH_TYPE));

    m_GameObjects.push_back(new Player(vec2(6,2), HUMANOID, m_MegaManMesh, m_pShaders, this));
    m_GameObjects.push_back(new fw::GameObject(vec2(3, 2), ANIMAL, m_DiamondDogMesh, m_pShader_Skin, this));

	
	m_pImGuiManager = new fw::ImGuiManager(m_pFramework);
    m_pImGuiManager->Init();
    m_GameArea_Outer = new fw::Mesh();
    m_GameArea_Outer->CreateCircle(3, 32);
    m_GameArea_Inner = new fw::Mesh();
    m_GameArea_Inner->CreateCircle(2.9, 32);
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
    glClearColor( 0, 0, 0, 0 );
    glClear( GL_COLOR_BUFFER_BIT );

    glPointSize( 10 );
	
    m_GameArea_Outer->Draw(vec2(5, 5), m_pShader_Blue);
    m_GameArea_Inner->Draw(vec2(5, 5), m_pShader_Black);
	
    for(int i=0; i<m_GameObjects.size();i++)
    {
        m_GameObjects[i]->Draw();
    }

    m_pImGuiManager->EndFrame();

   
}
