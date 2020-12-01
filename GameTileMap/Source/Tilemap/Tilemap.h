#pragma once

class Tilemap
{
public:
    enum class TileType
    {
        BrownFloor,
        RedWall,
    	RedCrate,
    	BlueCrate,
        GreyCrate,
        NumTypes,
    };

    struct TileProperties
    {
	    std::string m_SpriteName;      
        bool m_Walkable;
        TileProperties();
        TileProperties(std::string spriteName, bool walkable)
    		{ m_SpriteName = spriteName; m_Walkable = walkable; }
    };
//
public:
    Tilemap(const TileType* pLayout, int height, int width, vec2 TileSize, fw::SpriteSheet* pSpriteSheet,
        fw::Mesh* pMesh, fw::ShaderProgram* pShader, fw::Texture* pTexture);
    ~Tilemap();

    bool isTileWalkable(int TileIndex);
    void Draw();
 
protected:
    fw::Mesh* m_pTileMesh;
    fw::ShaderProgram* m_pShader;
    fw::Texture* m_pTexture;
    fw::SpriteSheet* m_pSpriteSheet;
  
    TileType* m_pLayout;
    fw::ivec2 m_MapSize = fw::ivec2(0, 0); // Width and Height of the map in tiles.
    vec2 m_TileSize = vec2(5, 5); // How big is a tile in world units?

    vec2 m_Position; // World position.
    fw::ivec2 m_TilePos; // Position of a tile in tile space.
    int m_TileIndex; // Index into the layout array of the tile.

		TileProperties m_Properties[(int)TileType::NumTypes];

};

