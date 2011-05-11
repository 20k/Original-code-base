#include "PlanetHandler.hpp"

#include "../Planet/Planet.hpp"

    PlanetHandler::PlanetHandler(std::string name, int pradius, int atmospherewidth, int lightx, int lighty, Limits &l1, Limits &l2, Limits &l3, DescA &Atmo){

        load(name ,pradius,  atmospherewidth,  lightx,  lighty,  l1,  l2,  l3,  Atmo);


    }

    void PlanetHandler::updateimage(){
        planet.image.Dest.x=x;
        planet.image.Dest.y=y;

    }


   void PlanetHandler::load(std::string name,int pradius,int atmospherewidth, int lightx, int lighty, Limits &l1, Limits &l2, Limits &l3, DescA &Atmo){
        //planet.imagepass=0;


        planet.imagepassed=0;

        planet.load(name,pradius, 0, 0, atmospherewidth, lightx, lighty, l1, l2, l3, Atmo, -4, 4, -2, 2);

        Orig.Copy(planet.image.data, 0, 0);
        planet.add_permanent_effects();
        planet.add_lighting();

    }


    void PlanetHandler::load(Arglist &D){

        Arglist Mod;
        Mod=D;
        Mod.pass=0;
        planet.imagepassed=0;

        planet.load(Mod.name, Mod.radius, 0, 0, Mod.atmospherewidth, Mod.lightx, Mod.lighty, Mod.l1, Mod.l2, Mod.l3, Mod.atmosphere, Mod.minx, Mod.maxx, Mod.miny, Mod.maxy, NULL, Mod.pass);
        ///The relative planet x and planet y seem irrelevant now. (arg 3+4)

        planet.add_permanent_effects();

        Orig.Copy(planet.image.data, 0, 0);
        planet.add_lighting();

        Updated.Copy(planet.image.data, 0, 0);


        ///This caused me an infinite number of bugs



    }


    PlanetHandler::PlanetHandler(){
    }


    void PlanetHandler::delete_images(){

    }


    ///Radius, Atmospherewidth ,Lightx, Lighty, Terrain1, terrain2, terrain3, atmosphere.
