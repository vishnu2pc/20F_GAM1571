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
    m_pShader_Blue = new fw::ShaderProgram( "Data/Basic.vert", "Data/Basic.frag" );
    m_pShader_DarkBlue = new fw::ShaderProgram("Data/Basic.vert", "Data/DarkBlue.frag");

    m_pMesh = new fw::Mesh(attribs, 4, GL_TRIANGLES);
	
}

void Game::Update()
{
}

void Game::Draw()
{
    glClearColor( 0, 1, 0, 0 );
    glClear( GL_COLOR_BUFFER_BIT );

    glPointSize( 10 );
   
    m_pMesh->Draw(m_pShader_Blue);
}
