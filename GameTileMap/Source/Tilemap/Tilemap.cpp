#include "GamePCH.h"
#include "Tilemap.h"

Tilemap::TileProperties::TileProperties()
{

}

Tilemap::~Tilemap()
{
	delete m_pLayout;
}

bool Tilemap::isTileWalkable(int TileIndex)
{
	TileType type = m_pLayout[TileIndex];
	return m_Properties[(int)type].m_Walkable;
}


Tilemap::Tilemap(const TileType* pLayout,  int height, int width, vec2 TileSize,fw::SpriteSheet* pSpriteSheet,
                 fw::Mesh* pMesh, fw::ShaderProgram* pShader, fw::Texture* pTexture)
{
	m_pSpriteSheet = pSpriteSheet;
	m_pTexture = pTexture;
	m_pTileMesh = pMesh;
	m_pShader = pShader;
	m_Position = vec2(0.0f, 0.0f);
	m_MapSize = fw::ivec2(width, height);
	m_TileSize = TileSize;
	m_Position = vec2(0.f, 0.f);
    m_Properties[(int)TileType::BrownFloor] = TileProperties("Ground/ground_01", true );
	m_Properties[(int)TileType::RedWall] = TileProperties("Blocks/block_01", false);
	m_Properties[(int)TileType::RedCrate] = TileProperties("Crates/crate_13", false);
	m_Properties[(int)TileType::BlueCrate] = TileProperties("Crates/crate_14", false);
	m_Properties[(int)TileType::GreyCrate] = TileProperties("Crates/crate_16", false);

	m_pLayout = new TileType[width*height];
	for (int h = 0; h < m_MapSize.y; h++)
	{
		for (int w = 0; w < m_MapSize.x; w++)
		{
			m_pLayout[w + m_MapSize.x * h] = pLayout[w + m_MapSize.x * ((m_MapSize.y-1)-h)];
		}
	}
	
}

void Tilemap::Draw()
{

	for(int h = 0;h < m_MapSize.y;h++)
	{
		for(int w = 0; w< m_MapSize.x;w++)
		{
			TileType type = m_pLayout[w + m_MapSize.x*h];
			m_Position = m_TileSize * vec2((float)w, (float)h);
			std::string spritename = m_Properties[(int)type].m_SpriteName;
			fw::SpriteInfo m_SpriteInfo = m_pSpriteSheet->GetSpriteInfo(spritename);
			
			vec2 m_UVScale = vec2(m_SpriteInfo.W / m_pSpriteSheet->GetWidth(), m_SpriteInfo.H / m_pSpriteSheet->GetHeight());
			vec2 m_UVOffset = vec2(m_SpriteInfo.x / m_pSpriteSheet->GetWidth(), m_SpriteInfo.y / m_pSpriteSheet->GetHeight());
			m_pTileMesh->Draw(m_Position, m_pShader, m_pTexture, m_UVScale, m_UVOffset, m_TileSize);
		}
	}
}
