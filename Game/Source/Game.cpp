#include "GamePCH.h"
#include "Game.h"
#include "Objects/Player.h"
#include "Objects/GameArena.h"
#include "Events/GameEvents.h"


Game::Game(fw::FWCore* pFramework)  :fw::GameCore(pFramework)
{
    
}

Game::~Game()
{
    for (int i = 0; i < m_pGameObjects.size(); i++)
    {
       delete m_pGameObjects[i];
    }
    delete m_pImGuiManager;
}

void Game::Init()
{
	
    m_pImGuiManager = new fw::ImGuiManager(m_pFramework);
    m_pImGuiManager->Init();
	
    m_pEventManager = new fw::EventManager();
	
    m_pShader = new fw::ShaderProgram("Data/Basic.vert", "Data/Basic.frag");
    m_pOuterMesh = new fw::Mesh();
    m_pInnerMesh = new fw::Mesh();
	
    m_pPlayerMaterial = new fw::Materials(m_pOuterMesh,m_pInnerMesh,m_pShader);
    m_pPlayerController = new fw::PlayerController();
    m_pPlayerPhysicsController = new fw::PhysicsController();
	
	m_pPlayerMaterial->SetNumVertices(100);
    m_pPlayerMaterial->SetColors(vec4::Black(), vec4::Red());

    m_pPlayerPhysicsController->SetRadius(0.4f);
    m_pPlayerPhysicsController->SetPosition(vec2(5.0f, 5.0f));
    m_pPlayerPhysicsController->SetMaxVelocity(5.0f);
	
    m_pPlayer = new Player(m_pPlayerMaterial, m_pPlayerPhysicsController, m_pPlayerController, this);

    m_pGameArenaMaterial = new fw::Materials(m_pOuterMesh, m_pInnerMesh,m_pShader);
    m_pGameArenaPhysicsController = new fw::PhysicsController();
	
    m_pGameArenaMaterial->SetNumVertices(100);
    m_pGameArenaMaterial->SetColors(vec4::Blue(), vec4::White());

    m_pGameArenaPhysicsController->SetRadius(4.0f);
    m_pGameArenaPhysicsController->SetPosition(vec2(5.0f, 5.0f));

    m_pGameArena = new GameArena(m_pGameArenaMaterial, m_pGameArenaPhysicsController, this);
	
}

void Game::CheckCollision()
{
    
}

void Game::OnEvent(fw::Event* pEvent)
{
    if(pEvent->GetType()==EVENT_TYPE::INPUT_EVENT)
	m_pPlayerController->OnEvent(pEvent);

    if (pEvent->GetType() == EVENT_TYPE::COLLISION)
        m_pPlayer->OnEvent(pEvent);
}

void Game::Update(float deltaTime)
{
    m_pEventManager->DispatchAllEvents(this);
    m_ArenaRadius = m_pGameArena->GetPhysicsController()->GetRadius();
    m_ArenaPosition = m_pGameArena->GetPhysicsController()->GetPosition();
	
    CheckCollision();
	m_pImGuiManager->StartFrame(deltaTime);
    ImGui::ShowDemoWindow();
	
   /* for (int i = 0; i < m_pGameObjects.size(); i++)
    {
        m_pGameObjects[i]->Update(deltaTime);
    }*/

    m_pGameArena->Update(deltaTime);
    m_pPlayer->Update(deltaTime);

}

void Game::Draw()
{
    glClearColor( 1, 10, 1, 1 );
    glClear( GL_COLOR_BUFFER_BIT );

    glPointSize( 10 );
	
    
    for(int i=0; i<m_pGameObjects.size();i++)
    {
        m_pGameObjects[i]->Draw();
    }

    m_pGameArena->Draw();
    m_pPlayer->Draw();

    m_pImGuiManager->EndFrame();
}
