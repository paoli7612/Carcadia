#include "map.h"

void map_init(map_t &map, const title_t title, const dimension_t dimension)
{


}

void map_load(map_t &map, title_t title)
{
    std::string filename = "maps/" + (std::string)title + ".tomaoli";
    std::ifstream file(filename);

    if (! file)
        throw "map not found";

    

    file.close();
}

void map_save(const map_t &map)
{
    std::string filename = "maps/" + (std::string)map.title + ".tomaoli";
    std::ofstream file(filename);

    if (! file)
        throw "map not found";

    file.write((char*)&map.width, sizeof(int));
    file.write((char*)&map.height, sizeof(int));
    
    file.close();
}
