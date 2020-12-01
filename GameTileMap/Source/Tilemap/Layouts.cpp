
#include "GamePCH.h"

#include "Tilemap/Tilemap.h"
#include "Tilemap/Layouts.h"

using TT = Tilemap::TileType;

const int Level1Layout_Width = 10;
const int Level1Layout_Height = 10;
const Tilemap::TileType level1Layout[] =
{
    TT::RedWall, TT::RedWall,    TT::RedWall,    TT::RedWall,    TT::RedWall,   TT::RedWall,   TT::RedWall,    TT::RedWall,    TT::RedWall,    TT::RedWall,
    TT::RedWall, TT::BrownFloor, TT::BrownFloor, TT::BrownFloor, TT::BrownFloor,TT::BrownFloor,TT::BrownFloor, TT::BrownFloor, TT::BrownFloor, TT::RedWall,
    TT::RedWall, TT::GreyCrate, TT::BrownFloor, TT::BrownFloor, TT::BrownFloor,TT::BrownFloor,TT::GreyCrate, TT::BrownFloor, TT::BrownFloor, TT::RedWall,
    TT::RedWall, TT::BrownFloor, TT::BrownFloor, TT::BrownFloor, TT::BrownFloor,TT::BrownFloor,TT::BrownFloor, TT::BlueCrate, TT::BrownFloor, TT::RedWall,
    TT::RedWall, TT::BrownFloor, TT::RedCrate, TT::BrownFloor, TT::BrownFloor,TT::BrownFloor,TT::BrownFloor, TT::BrownFloor, TT::BrownFloor, TT::RedWall,
    TT::RedWall, TT::BrownFloor, TT::BrownFloor, TT::BrownFloor, TT::BrownFloor,TT::BrownFloor,TT::BrownFloor, TT::BrownFloor, TT::BrownFloor, TT::RedWall,
    TT::RedWall, TT::BrownFloor, TT::BrownFloor, TT::BrownFloor, TT::GreyCrate,TT::BrownFloor,TT::BlueCrate, TT::BrownFloor, TT::BrownFloor, TT::RedWall,
    TT::RedWall, TT::BrownFloor, TT::BrownFloor, TT::BlueCrate, TT::BrownFloor,TT::BrownFloor,TT::BrownFloor, TT::BrownFloor, TT::BrownFloor, TT::RedWall,
    TT::RedWall, TT::BrownFloor, TT::BrownFloor, TT::BrownFloor, TT::BrownFloor,TT::BrownFloor,TT::RedCrate, TT::BrownFloor, TT::BrownFloor, TT::RedWall,
    TT::RedWall, TT::RedWall,    TT::RedWall,    TT::RedWall,    TT::RedWall,   TT::RedWall,   TT::RedWall,    TT::RedWall,    TT::RedWall,    TT::RedWall
};                                                                                                                             
