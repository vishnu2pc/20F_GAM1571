#include "GamePCH.h"

#include "Game.h"
#include "Objects/Player.h"
#include "Objects/PlayerController.h"
#include "Objects/Shapes.h"
#include "Events/GameEvents.h"
#include "Tilemap/Layouts.h"
#include "Objects/Enemy.h"
#include "Pathfinder/Pathfinder.h"

Game::Game(fw::FWCore* pFramework) : fw::GameCore( pFramework )
{
    wglSwapInterval( m_VSyncEnabled ? 1 : 0 );
}

Game::~Game()
{
    for( std::pair<std::string, fw::ShaderProgram*> object : m_pShaders )
    {
        delete object.second;
    }

    for( std::pair<std::string, fw::Mesh*> object : m_pMeshes )
    {
        delete object.second;
    }

    for( std::pair<std::string, fw::Texture*> object : m_pTextures )
    {
        delete object.second;
    }

    for( fw::GameObject* pObject : m_Objects )
    {
        delete pObject;
    }

    delete m_pPlayerController;
    delete m_pSpriteSheet;
    delete m_pPathfinder;
    delete m_pTilemap;
    delete m_pEventManager;
    delete m_pImGuiManager;
}

void Game::Init()
{
    // OpenGL Settings.
    glEnable( GL_BLEND );
    glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

    m_pImGuiManager = new fw::ImGuiManager( m_pFramework );
    m_pImGuiManager->Init();

    m_pEventManager = new fw::EventManager();

    m_pPlayerController = new PlayerController();

    // Load some shaders.
    m_pShaders["Basic"] = new fw::ShaderProgram( "Data/Basic.vert", "Data/Basic.frag" );

    // Create some meshes.
    m_pMeshes["Player"] = new fw::Mesh( meshPrimType_Sprite, meshNumVerts_Sprite, meshAttribs_Sprite );
    m_pMeshes["Tilemap"] = new fw::Mesh(meshPrimType_Sprite, meshNumVerts_Sprite, meshAttribs_Sprite);

    // Load some textures.
    m_pTextures["Game"] = new fw::Texture( "Data/Textures/Sokoban.png" );

    m_pSpriteSheet = new fw::SpriteSheet("Data/Textures/Sokoban.json");

    m_pTilemap = new Tilemap(level1Layout, Level1Layout_Height, Level1Layout_Width, vec2(5.0f,5.0f), m_pSpriteSheet,
        m_pMeshes["Tilemap"], m_pShaders["Basic"], m_pTextures["Game"]);
	
    m_pPathfinder = new Pathfinder(m_pTilemap, Level1Layout_Width, Level1Layout_Height);
    // Create some GameObjects.
    m_pPlayer = new Player( this, m_pPlayerController, m_pSpriteSheet,"Player", vec2(10.f, 10.f), vec2(5.0f,5.0f),
        m_pMeshes["Player"], m_pShaders["Basic"], m_pTextures["Game"] );

    m_pEnemy = new Enemy(this,m_pSpriteSheet, m_pPathfinder, "Enemy", vec2(30.f, 30.f), vec2(5.0f, 5.0f),
        m_pMeshes["Player"], m_pShaders["Basic"], m_pTextures["Game"]);

    m_Objects.push_back( m_pPlayer );
    m_Objects.push_back(m_pEnemy);
}

void Game::StartFrame(float deltaTime)
{
    m_pImGuiManager->StartFrame( deltaTime );

    m_pPlayerController->StartFrame();

    // Process our events.
    m_pEventManager->DispatchAllEvents( deltaTime, this );
}

void Game::OnEvent(fw::Event* pEvent)
{
    m_pPlayerController->OnEvent( pEvent );

}

void Game::Update(float deltaTime)
{
    // Display framerate.
    ImGui::Text( "%0.2f", 1/deltaTime );

    for( auto it = m_Objects.begin(); it != m_Objects.end(); it++ )
    {
        fw::GameObject* pObject = *it;
        pObject->Update( deltaTime );
    }

    // Debug imgui stuff.
    {
        if( ImGui::Checkbox( "VSync", &m_VSyncEnabled ) )
        {
            wglSwapInterval( m_VSyncEnabled ? 1 : 0 );
        }
    }
        }

void Game::Draw()
{
    glClearColor( 0, 0, 0.2f, 0 );
    glClear( GL_COLOR_BUFFER_BIT );

    glPointSize( 10 );
    m_pTilemap->Draw();
    for( auto it = m_Objects.begin(); it != m_Objects.end(); it++ )
    {
        fw::GameObject* pObject = *it;
        pObject->Draw();
    }

    m_pImGuiManager->EndFrame();
}
