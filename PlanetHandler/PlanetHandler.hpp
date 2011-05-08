#ifndef PLANETHANDLER_HEADER
#define PLANETHANDLER_HEADER

#include "../Planet/Planet.hpp"

class PlanetHandler{

public:
    Planet planet;

    int64_t  x, y; ///In pixels
    int64_t fromsun; ///distance from sun;
                                    ///Read these next two comments in reverse order
    sf::Image Orig;      ///This does not
    sf::Image Updated; ///This gets updated

    PlanetHandler();
    PlanetHandler(std::string name, int pradius, int atmospherewidth, int lightx, int lighty, Limits &l1, Limits &l2, Limits &l3, DescA &Atmo);

    void updateimage();

    void load(std::string name,int pradius,int atmospherewidth, int lightx, int lighty, Limits &l1, Limits &l2, Limits &l3, DescA &Atmo);
    void load(Arglist &D);

    void delete_images();


    ///Radius, Atmospherewidth ,Lightx, Lighty, Terrain1, terrain2, terrain3, atmosphere.

};
#endif
