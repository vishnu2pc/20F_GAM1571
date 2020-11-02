#include "GamePCH.h"
#include "Game.h"
#include "Objects/Player.h"
#include "Objects/GameArena.h"
#include "Events/GameEvents.h"
#include "Objects/Enemy.h"
#include "LevelSystem/LevelManager.h"

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
    m_pLevelManager = new fw::LevelManager(this);
	
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
    m_pPlayerPhysicsController->SetMaxVelocity(m_PlayerVelocity);
	
    m_pPlayer = new Player(m_pPlayerMaterial, m_pPlayerPhysicsController, m_pPlayerController, this);

    m_pGameArenaMaterial = new fw::Materials(m_pOuterMesh, m_pInnerMesh,m_pShader);
    m_pGameArenaPhysicsController = new fw::PhysicsController();
	
    m_pGameArenaMaterial->SetNumVertices(m_GameArenaNumVertices);
    m_pGameArenaMaterial->SetColors(vec4::Blue(), vec4::White());

    m_pGameArenaPhysicsController->SetRadius(4.0f);
    m_pGameArenaPhysicsController->SetPosition(vec2(5.0f, 5.0f));

    m_pGameArena = new GameArena(m_pGameArenaMaterial, m_pGameArenaPhysicsController, this);

    m_pLevelManager->InitializeLevel();

}

void Game::SpawnEnemy()
{
    fw::Materials* m_pEnemyMaterial = new fw::Materials(m_pOuterMesh, m_pInnerMesh, m_pShader);
    fw::PhysicsController* m_pEnemyPhysicsController = new fw::PhysicsController();

    m_pEnemyMaterial->SetNumVertices(m_EnemyNumVertices);
    m_pEnemyMaterial->SetColors(EnemyColor, EnemyColor);

    m_pEnemyPhysicsController->SetRadius(m_EnemyRadiusControl);

    float RandAngle = rand() % 360;
    vec2 pos = vec2(cosf(RandAngle * M_PI / 180), sinf(RandAngle * M_PI / 180)) * m_pGameArenaPhysicsController->GetRadius() + vec2(5.0f, 5.0f);
    m_pEnemyPhysicsController->SetPosition(pos);
    m_pEnemyPhysicsController->SetMaxVelocity(m_EnemySpeed);

    m_pEnemies.push_back(new Enemy(m_pEnemyMaterial, m_pEnemyPhysicsController, this));

}

void Game::DeleteEnemy(fw::Event* pEvent)
{
    DeleteEnemyEvent* pDeleteEnemyEvent = static_cast<DeleteEnemyEvent*>(pEvent);
    Enemy* pEnemy = pDeleteEnemyEvent->GetEnemy();

    auto it = std::find(m_pEnemies.begin(), m_pEnemies.end(), pEnemy);
    m_pEnemies.erase(it);

    delete pEnemy;
}

void Game::HandleImGui(float deltaTime)
{
    m_pImGuiManager->StartFrame(deltaTime);
    
    ImGui::Begin("Level Editor");
    ImGui::DragInt("Arena Vertices", &m_GameArenaNumVertices, 1, 3, 100);
    ImGui::DragInt("Enemy Vertices", &m_EnemyNumVertices, 1, 3, 100);
    ImGui::DragInt("Player Vertices", &m_PlayerNumVertices, 1, 3, 100);
    ImGui::DragFloat("Player Speed", &m_PlayerVelocity, 1, 3, 10);
    ImGui::DragFloat("Player Size", &m_PlayerRadiusControl, 0.005, 0.1, 1);
    ImGui::DragFloat("Arena Size", &m_ArenaRadiusControl, 0.005, 2, 6);
    ImGui::DragFloat("Enemy Size", &m_EnemyRadiusControl, 0.005, 0.1, 1);
    ImGui::ColorEdit4("Player BaseColor", &PlayerInnerColor.x, ImGuiColorEditFlags_NoPicker);
    ImGui::ColorEdit4("Player SecColor", &PlayerOuterColor.x, ImGuiColorEditFlags_NoPicker);
    ImGui::ColorEdit4("Arena BaseColor", &ArenaInnerColor.x, ImGuiColorEditFlags_NoPicker);
    ImGui::ColorEdit4("Arena SecColor", &ArenaOuterColor.x, ImGuiColorEditFlags_NoPicker);
    ImGui::ColorEdit4("Enemy Color", &EnemyColor.x, ImGuiColorEditFlags_NoPicker);
    ImGui::ColorEdit4("Game Color", &GameColor.x, ImGuiColorEditFlags_NoPicker);
    ImGui::End();

	if(!m_WinCondtion)
	{
        ImGui::Begin("Level UI");
        ImVec4 const TextColor = ImVec4(0.0f, 1.0f, 0.0f, 1.0f);
        ImGui::TextColored(TextColor, "Level %d",(int)m_pLevelManager->GetLevelType() + 1);
        ImGui::TextColored(TextColor, "Time Left %d", (int)m_LevelTimer);
        ImGui::End();
    }

    else
    {
        ImGui::Begin("Win!");
        ImVec4 const TextColor = ImVec4(0.0f, 1.0f, 0.0f, 1.0f);
        ImGui::TextColored(TextColor,"Congratualions, you've won the game");
        ImGui::End();
    }
	
}

void Game::StartFrame(float deltaTime)
{
    m_pPlayerController->StartFrame();
    m_pEventManager->DispatchAllEvents(this);
}

void Game::UpdateLevel(float deltaTime)
{

	m_PlayerRadius = m_pPlayer->GetPhysicsController()->GetRadius();
    m_PlayerPosition = m_pPlayer->GetPhysicsController()->GetPosition();
    m_ArenaRadius = m_pGameArena->GetPhysicsController()->GetRadius();
    m_ArenaPosition = m_pGameArena->GetPhysicsController()->GetPosition();
	
    m_pGameArenaMaterial->SetColors(ArenaOuterColor, ArenaInnerColor);
    m_pGameArenaMaterial->SetNumVertices(m_GameArenaNumVertices);

    m_pGameArenaPhysicsController->SetRadius(m_ArenaRadiusControl);
	
    m_pPlayerPhysicsController->SetMaxVelocity(m_PlayerVelocity);
    m_pPlayerPhysicsController->SetRadius(m_PlayerRadiusControl);
	
    m_pPlayerMaterial->SetNumVertices(m_PlayerNumVertices);
    m_pPlayerMaterial->SetColors(PlayerOuterColor, PlayerInnerColor);
	
}

void Game::OnEvent(fw::Event* pEvent)
{
	if(pEvent->GetType()==EVENT_TYPE::WIN)
	{
        m_WinCondtion = true;
	}
    if (pEvent->GetType() == EVENT_TYPE::NEXT_LEVEL)
    {
        m_pLevelManager->NextLevel();
        m_pLevelManager->InitializeLevel();
    }
    if (pEvent->GetType() == EVENT_TYPE::SPAWN_ENEMY)
        SpawnEnemy();
    
    if (pEvent->GetType() == EVENT_TYPE::DELETE_ENEMY)
    {
        DeleteEnemy(pEvent);
    }
	if(pEvent->GetType()==EVENT_TYPE::INPUT_EVENT)
		m_pPlayerController->OnEvent(pEvent);

}

void Game::Update(float deltaTime)
{
    StartFrame(deltaTime);
    HandleImGui(deltaTime);
    UpdateLevel(deltaTime);

    m_pGameArena->Update(deltaTime);
    m_pPlayer->Update(deltaTime);
	
    for (int i = 0; i < m_pEnemies.size(); i++)
    {
        m_pEnemies[i]->Update(deltaTime);
    }

    Timer(deltaTime);

}

void Game::Draw()
{
    glClearColor(GameColor.x, GameColor.y, GameColor.z, GameColor.w);
    glClear( GL_COLOR_BUFFER_BIT );

    glPointSize( 10 );
	
    m_pGameArena->Draw();
    m_pPlayer->Draw();
    for (int i = 0; i < m_pEnemies.size(); i++)
    {
        m_pEnemies[i]->Draw();
    }
    m_pImGuiManager->EndFrame();
}

void Game::Timer(float deltaTime)
{
    m_EnemyTimer -= deltaTime;
    if (m_EnemyTimer < 0)
    {
        SpawnEnemyEvent* pEvent = new SpawnEnemyEvent();
        this->GetEventManager()->AddEvent(pEvent);
        m_EnemyTimer = m_pLevelManager->GetEnemySpawnDuration();

    }

    m_LevelTimer -= deltaTime;
    if (m_LevelTimer < 0)
    {
        NextLevelEvent* pEvent = new NextLevelEvent;
        this->GetEventManager()->AddEvent(pEvent);
        m_LevelTimer = m_pLevelManager->GetLevelDuration();
    }
}
