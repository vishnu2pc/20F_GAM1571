#include "GamePCH.h"

#include "Objects/Player.h"
#include "Tilemap/Tilemap.h"
#include "Game.h"
#include "Objects/PlayerController.h"


Player::Player(fw::GameCore* pGameCore, PlayerController* pPlayerController, fw::SpriteSheet* pSpriteSheet, std::string name, vec2 pos, vec2 ObjectScale, fw::Mesh* pMesh, fw::ShaderProgram* pShader, fw::Texture* pTexture)
    : fw::GameObject( pGameCore, name, pos, ObjectScale, pMesh, pShader, pTexture )
    , m_pPlayerController( pPlayerController )
{
    m_pSpriteSheet = pSpriteSheet;
    m_ObjectScale = ObjectScale;
}

Player::~Player()
{

}

void Player::Update(float deltaTime)
{
    float speed = 2.0f * m_ObjectScale.GetLength();
    vec2 OldPos = m_Position;
    vec2 NewPos = m_Position;
    vec2 dir;
	
    if (m_pPlayerController->IsHeld(PlayerController::Down))
    {
        m_PlayerState = PlayerState::MOVE_DOWN;
    }
    else if (m_pPlayerController->IsHeld(PlayerController::Up))
    {
        m_PlayerState = PlayerState::MOVE_UP;
    }
    else if (m_pPlayerController->IsHeld(PlayerController::Left))
    {
        m_PlayerState = PlayerState::MOVE_LEFT;
    }
    else if (m_pPlayerController->IsHeld(PlayerController::Right))
    {
        m_PlayerState = PlayerState::MOVE_RIGHT;
    }

    else
        m_PlayerState = PlayerState::IDLE;

	
	switch(m_PlayerState)
	{
    case PlayerState::IDLE:
		{
        m_SpriteInfo = m_pSpriteSheet->GetSpriteInfo("Player/player_05");
             break;
		}

    case PlayerState::MOVE_DOWN:
	    {
        if (m_pPlayerController->WasNewlyPressed(PlayerController::Down))
        {
            m_Timer = 0;
            framecount = 0;
        }

        else
        {
            if (framecount < frames - 1)
            {
                if (m_Timer > delay)
                {
                    framecount++;
                    m_Timer = 0;
                }
            }

            else if(m_Timer > delay)
            {
                framecount = 0;
                m_Timer = 0;
            }
        }

        m_SpriteInfo = m_pSpriteSheet->GetSpriteInfo(WalkDown[framecount]);
        dir.y += -1;
    		NewPos = m_Position + dir * speed * deltaTime;
        m_TileIndex = ((10 * (int)(NewPos.y / m_ObjectScale.y) + (int)(NewPos.x / m_ObjectScale.x)));
        if (!static_cast<Game*>(m_pGameCore)->GetTileMap()->isTileWalkable(m_TileIndex))
            NewPos = OldPos;
        break;


	    }

    case PlayerState::MOVE_UP:
		{
        if (m_pPlayerController->WasNewlyPressed(PlayerController::Up))
        {
            m_Timer = 0;
            framecount = 0;
        }

        else
        {
            if (framecount < frames -1)
            {
                if (m_Timer > delay)
                {
                    framecount++;
                    m_Timer = 0;
                }
            }

            else if (m_Timer > delay)
            {
                framecount = 0;
                m_Timer = 0;
            	
            }
        }

        m_SpriteInfo = m_pSpriteSheet->GetSpriteInfo(WalkUp[framecount]);
        dir.y += 1;
        NewPos = m_Position + dir * speed * deltaTime;
        m_TileIndex = ((10 * (int)((NewPos.y + m_ObjectScale.y) / m_ObjectScale.y) + (int)(NewPos.x / m_ObjectScale.x)));
        if (!static_cast<Game*>(m_pGameCore)->GetTileMap()->isTileWalkable(m_TileIndex))
            NewPos = OldPos;
        break;
		}

    case PlayerState::MOVE_LEFT:
	    {
		    if(m_pPlayerController->WasNewlyPressed(PlayerController::Left))
		    {
                m_Timer = 0;
                framecount = 0;
		    }

            else
            {
                if (framecount < frames - 1 )
                {
                    if (m_Timer > delay)
                    {
                        framecount++;
                        m_Timer = 0;
                    }
                }

                else if (m_Timer > delay)
                {
                    framecount = 0;
                    m_Timer = 0;
                }
            }

            m_SpriteInfo = m_pSpriteSheet->GetSpriteInfo(WalkLeft[framecount]);
            dir.x += -1;
            NewPos = m_Position + dir * speed * deltaTime;
            m_TileIndex = ((10 * (int)(NewPos.y / m_ObjectScale.y) + (int)(NewPos.x / m_ObjectScale.x)));
            if (!static_cast<Game*>(m_pGameCore)->GetTileMap()->isTileWalkable(m_TileIndex))
                NewPos = OldPos;
    		break;
	    }

    case PlayerState::MOVE_RIGHT:
	    {
        if (m_pPlayerController->WasNewlyPressed(PlayerController::Right))
        {
            m_Timer = 0;
            framecount = 1;
        }

        else
        {
            if (framecount < frames - 1)
            {
                if (m_Timer > delay)
                {
                    framecount++;
                    m_Timer = 0;
                }
            }

            else if (m_Timer > delay)
            {
                framecount = 0;
                m_Timer = 0;
            }
        }

        m_SpriteInfo = m_pSpriteSheet->GetSpriteInfo(WalkRight[framecount]);
        dir.x += 1;
        NewPos = m_Position + dir * speed * deltaTime;
        m_TileIndex = ((10 * (int)(NewPos.y / m_ObjectScale.y) + (int)((NewPos.x + m_ObjectScale.x )/ m_ObjectScale.x)));
        if (!static_cast<Game*>(m_pGameCore)->GetTileMap()->isTileWalkable(m_TileIndex))
            NewPos = OldPos;
        break;
    		
	    }
		default:
	    {
            assert(FALSE);
	    }
	}
	
    m_UVScale = vec2(m_SpriteInfo.W/m_pSpriteSheet->GetWidth(), m_SpriteInfo.H/m_pSpriteSheet->GetHeight() );
    m_UVOffset = vec2(m_SpriteInfo.x/m_pSpriteSheet->GetWidth(), m_SpriteInfo.y/m_pSpriteSheet->GetHeight() );

   /* m_UVScale = vec2(64.0 / 1024.0, 64.0 / 512.0);
    m_UVOffset = vec2(780.0 / 1024.0, 383.0 / 512.0);*/

    m_Position = NewPos;
 
    m_Timer += deltaTime;
}
