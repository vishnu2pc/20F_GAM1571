#include "GamePCH.h"

#include "Objects/Enemy.h"
#include "Tilemap/Tilemap.h"
#include "Pathfinder/Pathfinder.h"
#include "Game.h"
#include "Objects/Player.h"

Enemy::Enemy(fw::GameCore* pGameCore, fw::SpriteSheet* pSpriteSheet, Pathfinder* pPathfinder, std::string name, vec2 pos, vec2 ObjectScale, fw::Mesh* pMesh, fw::ShaderProgram* pShader, fw::Texture* pTexture)
    : fw::GameObject( pGameCore, name, pos, ObjectScale, pMesh, pShader, pTexture )
{
    m_pSpriteSheet = pSpriteSheet;
    m_ObjectScale = ObjectScale ;
    m_pPathfinder = pPathfinder;
}

Enemy::~Enemy()
{

}

void Enemy::Update(float deltaTime)
{
    vec2 NewPos = m_Position;
    int path[255];
	
    m_SpriteInfo = m_pSpriteSheet->GetSpriteInfo("Player/player_05");
	
    Player* player = static_cast<Game*>(m_pGameCore)->GetPlayer();
    vec2 PlayerPosition = static_cast<GameObject*>(player)->GetPosition();
    Tilemap* tilemap = static_cast<Game*>(m_pGameCore)->GetTileMap();
	
    if(m_pPathfinder->FindPath(m_Position.x, m_Position.y, PlayerPosition.x, PlayerPosition.y));
    {
		int len = m_pPathfinder->GetPath(path, 255, PlayerPosition.x, PlayerPosition.y);
        if(delay<0)
        {
        	
            NewPos = tilemap->GetWorldPosition(path[0]);
            delay = 1.0f;
        }
    	
    }
    m_UVScale = vec2(m_SpriteInfo.W/m_pSpriteSheet->GetWidth(), m_SpriteInfo.H/m_pSpriteSheet->GetHeight() );
    m_UVOffset = vec2(m_SpriteInfo.x/m_pSpriteSheet->GetWidth(), m_SpriteInfo.y/m_pSpriteSheet->GetHeight() );

    m_Position = NewPos;
 
    delay -= deltaTime;
}
