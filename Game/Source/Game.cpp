#include "GamePCH.h"
#include "Game.h"
#include "Objects/Player.h"
#include "Objects/GameArena.h"
#include "Events/GameEvents.h"
#include "Objects/Enemy.h"


Game::Game(fw::FWCore* pFramework)  :fw::GameCore(pFramework)
{
    
}

Game::~Game()
{
   
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
    m_pPlayerPhysicsController->SetMaxVelocity(m_pPlayerVelocity);
	
    m_pPlayer = new Player(m_pPlayerMaterial, m_pPlayerPhysicsController, m_pPlayerController, this);

    m_pGameArenaMaterial = new fw::Materials(m_pOuterMesh, m_pInnerMesh,m_pShader);
    m_pGameArenaPhysicsController = new fw::PhysicsController();
	
    m_pGameArenaMaterial->SetNumVertices(m_pGameArenaNumVertices);
    m_pGameArenaMaterial->SetColors(vec4::Blue(), vec4::White());

    m_pGameArenaPhysicsController->SetRadius(4.0f);
    m_pGameArenaPhysicsController->SetPosition(vec2(5.0f, 5.0f));

    m_pGameArena = new GameArena(m_pGameArenaMaterial, m_pGameArenaPhysicsController, this);

    m_Timer = 1;
	
}

void Game::SpawnEnemy()
{
    fw::Materials* m_pEnemyMaterial = new fw::Materials(m_pOuterMesh, m_pInnerMesh, m_pShader);
    fw::PhysicsController* m_pEnemyPhysicsController = new fw::PhysicsController();

    m_pEnemyMaterial->SetNumVertices(100);
    m_pEnemyMaterial->SetColors(vec4::Green(), vec4::DarkBlue());

    m_pEnemyPhysicsController->SetRadius(0.2f);

    float RandAngle = (2 * (float)M_PI / 5) * (rand() % 10);
    vec2 pos = vec2(cosf(RandAngle), sinf(RandAngle)) * m_ArenaRadius + vec2(5.0f,5.0f);
    m_pEnemyPhysicsController->SetPosition(pos);
    m_pEnemyPhysicsController->SetMaxVelocity(rand() % 10);
    m_pEnemies.push_back(new Enemy(m_pEnemyMaterial, m_pEnemyPhysicsController, this));
}

void Game::HandleImGui(float deltaTime)
{
    m_pImGuiManager->StartFrame(deltaTime);
    ImGui::ShowDemoWindow();

    ImGui::DragInt("Arena Vertices", &m_pGameArenaNumVertices, 1, 3, 100);
    /*ImGui::DragInt("Player Speed", &m_pPlayerVelocity, 1, 3, 10);*/
}

void Game::UpdateLevel()
{
    m_pGameArenaMaterial->SetNumVertices(m_pGameArenaNumVertices);
    /*m_pPlayerPhysicsController->SetMaxVelocity(m_pPlayerVelocity);*/

    m_ArenaRadius = m_pGameArena->GetPhysicsController()->GetRadius();
    m_ArenaPosition = m_pGameArena->GetPhysicsController()->GetPosition();
}

void Game::OnEvent(fw::Event* pEvent)
{
    if(pEvent->GetType()==EVENT_TYPE::INPUT_EVENT)
	m_pPlayerController->OnEvent(pEvent);

	if(pEvent->GetType()==EVENT_TYPE::SPAWN_ENEMY)
	{
        SpawnEnemy();
	}
}

void Game::Update(float deltaTime)
{
    m_pEventManager->DispatchAllEvents(this);
    UpdateLevel();

    m_pGameArena->Update(deltaTime);
    m_pPlayer->Update(deltaTime);
    
	
    for (int i = 0; i < m_pEnemies.size(); i++)
    {
        m_pEnemies[i]->Update(deltaTime);
    }
    HandleImGui(deltaTime);
    Timer(deltaTime);

    
}

void Game::Draw()
{
    glClearColor( 0.9f, 0.9f, 0.9f, 1 );
    glClear( GL_COLOR_BUFFER_BIT );

    glPointSize( 10 );
	
    m_pGameArena->Draw();
    m_pPlayer->Draw();
	
    for(int i=0; i<m_pEnemies.size();i++)
    {
        m_pEnemies[i]->Draw();
    }
    m_pImGuiManager->EndFrame();
}

void Game::Timer(float deltaTime)
{
    m_Timer -= deltaTime;
    if (m_Timer < 0)
    {
        SpawnEnemyEvent* pEvent = new SpawnEnemyEvent();
        this->GetEventManager()->AddEvent(pEvent);
        m_Timer = 1;
    }
}
