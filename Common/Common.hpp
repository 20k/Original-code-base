#ifndef COMMON_HEADER
#define COMMON_HEADER

///Classes that are too small to warrent having their own header + implementation files

#define INITIALDISTANCE 900000
#define BODECONSTANT 675000
#define MAX_SOLAR 68400000.0
//#include "../Planet/Planet.hpp"

class Arglist;
struct preciserect;
class Colour;
class DescA;
class Limits;
//class Planet;



extern const unsigned int Size;
extern Arglist *PlanetArgLists;

extern int planetnum;


extern Arglist *SunArgLists;
extern int sunnum;




struct preciserect{
    int64_t x, y, w, h;
};



class Pass{
public:
    sf::Sprite *Sprite;
    int r;

    preciserect Dest, Src;
    Pass(){r=0;}
};

class Colour ///Hmmm. it would be nice to use this instead of sf::colour incase i have to do another whole switch.
{
public:
        int r, g, b;

        Colour(int pr, int pg, int pb) {
                load(pr, pg, pb);
        }

        void load(int pr, int pg, int pb) {
                r=pr, g=pg, b=pb;
        }

        Colour() {
        }

        Colour operator+=(Colour &C) {
                r+=C.r,
                g+=C.g,
                b+=C.b;
                return *this;
        }

};


class DescA{
public:
    int Haze;
    int r, g, b;
    int Atmosphere;
    int sun;
    int type;

    DescA(){
    }

    DescA(int pHaze, int pAtmosphere, int pr, int pg, int pb, int psun, int ptype){
        load(pHaze,Atmosphere ,pr, pg, pb, psun, ptype);

    }

    void load(int pHaze,int pAtmosphere, int pr, int pg, int pb, int psun, int ptype){
        Haze=pHaze;
        r=pr;
        g=pg;
        b=pb;
        Atmosphere=pAtmosphere;
        sun=psun;
        type=ptype;
    }

};

///Atmosphere Descriptor


class Limits{
public:
    Colour col;

    int limit;

    Limits(int plimit, int r, int g, int b){
        load(plimit, r, g, b);
    }

    void load(int plimit, int r, int g, int b){
        limit=plimit;
        col.r = r;
		col.g = g;
		col.b = b;
    }
    Limits(){
    }



};
///Noise limits for colouring in planets


class Arglist{

public:


    std::string name;
    int radius;
    int atmospherewidth;
    int lightx, lighty;
    Limits l1, l2, l3;
    DescA atmosphere;
    int minx, maxx, miny, maxy;
    int pass;

    double **Terrain;


    Arglist(double **pTerrain, std::string pname, int pradius,int patmos,int plx,int ply, Limits p1, Limits p2, Limits p3, DescA Atmosphere, int pmx,int pax,int pmy, int pay){
    radius=pradius;
    atmospherewidth=patmos;
    lightx=plx;
    lighty=ply;
    l1=p1;
    l2=p2;
    l3=p3;
    //atmosphere =new DescA;
    atmosphere=Atmosphere;
    minx=pmx;
    maxx=pax;
    miny=pmy;
    maxy=pay;
    name=pname;
    Terrain=pTerrain;
    pass=1;
    }

    Arglist(){
    }




};

#endif
