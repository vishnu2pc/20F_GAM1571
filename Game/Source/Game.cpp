#include "Framework.h"

#include "Game.h"

#include <iostream>

Game::Game()
{
    
    
}

Game::~Game()
{
}

void Game::Init()
{
    
    m_GameObjects.push_back(fw::GameObject());
	
}

void Game::Update()
{
}

void Game::Draw()
{
    glClearColor( 0, 1, 0, 0 );
    glClear( GL_COLOR_BUFFER_BIT );

    glPointSize( 10 );
	
    for (auto it = m_GameObjects.begin(); it < m_GameObjects.end(); ++it)
    {
        it->Draw();
    }
    
}
