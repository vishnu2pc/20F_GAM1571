#include "Framework.h"

#include "Game.h"

Game::Game()
{
    
    
}

Game::~Game()
{
}

void Game::Init()
{
    m_Humanoid = new fw::GameObject();
	
}

void Game::Update()
{
}

void Game::Draw()
{
    glClearColor( 0, 1, 0, 0 );
    glClear( GL_COLOR_BUFFER_BIT );

    glPointSize( 10 );
    m_Humanoid->Draw();
    
}
