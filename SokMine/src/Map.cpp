#include "Map.h"
#include "TextureManag.h"

// dirt = 0
// grass = 1
// floor = 2

int lvl1[20][25] = {
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,1,2,2,2,2,2,1,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,1,2,2,2,2,2,1,1,0,0,0,0,0,0},
    {0,0,0,0,0,0,1,2,2,2,2,2,2,1,1,0,0,0,0,0},
    {0,0,0,0,0,0,1,2,2,2,2,2,2,2,1,0,0,0,0,0},
    {0,0,0,0,0,0,1,2,2,2,2,2,2,2,1,0,0,0,0,0},
    {0,0,0,0,0,0,1,2,2,2,2,2,2,2,1,0,0,0,0,0},
    {0,0,0,0,0,0,1,2,1,1,1,2,2,2,1,0,0,0,0,0},
    {0,0,0,0,0,0,1,2,2,2,2,2,2,1,1,0,0,0,0,0},
    {0,0,0,0,0,0,1,2,2,2,2,2,2,1,0,0,0,0,0,0},
    {0,0,0,0,0,0,1,2,2,2,2,2,2,1,0,0,0,0,0,0},
    {0,0,0,0,0,0,1,2,2,2,2,2,2,1,0,0,0,0,0,0},
    {0,0,0,0,0,0,1,2,2,2,2,2,2,1,0,0,0,0,0,0},
    {0,0,0,0,0,0,1,2,2,2,2,2,1,1,0,0,0,0,0,0},
    {0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
};

int* Map::getMap()
{
    return (int*) map;
}

Map::Map()
{
    dirt = TextureManag::loadTexture("images/dirt.png");
    grass = TextureManag::loadTexture("images/grass.png");
    floor = TextureManag::loadTexture("images/floor.png");


    LoadMap(lvl1);

    src.x = src.y = 0;
    src.w = dest.w = 32;
    src.h = dest.h = 32;

    dest.x = dest.y = 0;
}

Map::~Map()
{
    //dtor
}
void Map::LoadMap(int array[20][25])
{
    for(int row = 0;row<20;row++)
    {
        for(int colum = 0;colum<25; colum++)
        {
            map[row][colum] = array[row][colum];
        }
    }
}
void Map::DrawMap()
{
    int type = 0;

    for(int row = 0;row<20;row++)
    {
        for(int colum = 0;colum<25; colum++)
        {
            type = map[row][colum];
            dest.x = colum * 32;
            dest.y = row * 32;

            switch(type)
            {
            case 0:
                TextureManag::Draw(dirt,src,dest);
                break;
            case 1:
                TextureManag::Draw(grass,src,dest);
                break;
            case 2:
                TextureManag::Draw(floor,src,dest);
                break;
           default:
            break;
            }
        }
    }
}
