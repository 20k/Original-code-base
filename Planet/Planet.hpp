#ifndef PLANET_HEADER
#define PLANET_HEADER
#include "../Image/Image.hpp"

//#include "../PerlinNoise/Header.hpp"
class Planet
{
public:

        static int xyoffset;
        const static int xyoffsetmul=1000; ///Needs to be greater than diameters of planets.
        ///Need to fix issue in noise distort gen.

        int AtmosphereAmount;
        int AtmosphereWidth; // 1 segment

        double **data; // DO like features. Roid belts

        Image image;

        int relative_x, relative_y; ///Doesnt do a lot
        int mineralamount; ///Doesnt do a lot

        Limits limit1, limit2, limit3;

        int shiney, shinex;
        int shineym1, shinexm1;

        std::string name;

        DescA Atmosphere;

        int imagepassed;


        int smaxx, smaxy, sminx, sminy;///Smoothing



        double radius; ///In pixels. Might have to do some sort of conversion.

        void  set_pixel_with_variance(register int r, register int g, register int b, double variance, register int px, register int py, register int check=0);
        ///Does what it says on the tin. Variance is just a measure of how much to multiply the rgb values by, and px and py are where to set
        ///Check is "Check if out of bounds"


        double average_square(int x, int y,int xsize, int ysize);///Seems to do the same as parse data

        Colour get_colours_from_heightmap(int x, int y );

        int return_tier(int x, int y);///Is this pixel in the first band, the second, or the third?



        void use_surface(sf::Image *mage);

        void generate_image();///Does what it says on the tin
        void parse_data(int minx, int maxx, int miny, int maxy); ///Does min/max smoothing of info

        void add_atmosphere(DescA acolour, int Do=1); ///If do is 0, just cuts circle out
        void add_to_pixel_with_variance(int r, int g, int b, double variance, int px, int py);
        void add_shine_old(double shinex, double shiney, int type); ///Obsolete?
        void add_shine_pre_half(double shinex, double shiney, int type); ///Obsolete?
        void add_shine(double shinex, double shiney, int type);
        void add_sun_shine(double shinex, double shiney);
        void add_scatter();
        void add_hal_region(int Sun=0);
        void add_extreme_variance();
        void add_permanent_effects();
        void add_lighting();
        void add_blur();

        int return_appropriate_image_lighting();

        Arglist return_planetdescriptor(); ///Returns all the arguments the planet was loaded with

        void load_from_descriptor(Arglist p);

        void distort_class(double x, double y, preciserect&dest);

        void circularise_image();

        void load(std::string pname,double pRadius, int px, int py, int pAtmosphereWidth, int pshinex, int pshiney, Limits pL1, Limits pL2, Limits pL3, DescA pAtmosphere, int minx, int maxx, int miny, int maxy, double **pdata=NULL, int pass=0);

        Planet();

        Planet(std::string pname,double pRadius, int px, int py, int pAtmosphereWidth, int pshinex, int pshiney, Limits pL1, Limits pL2, Limits pL3, DescA pAtmosphere, int minx, int maxx, int miny, int maxy, double **pdata=NULL, int pass=0);

         ~Planet();

        void SetRXY(int a, int b);

///Delete data


};
#endif
