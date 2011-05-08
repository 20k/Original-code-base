
#include <iostream>
#include <math.h>
#include <list>
#include <cstdio>
#include <cstdlib>
#include <time.h>



//#define SHADING
#define Uint64 unsigned long long int
#define Sint64 signed long long int
#ifdef _MSC_VER
typedef signed long long int int64_t;
#define constexpr const
#endif
//#define Sint16 sint16

#include <windows.h>


#include "Prngs/rand.hpp"

#include <SFML/graphics.hpp>


int GetRefreshRate(int index)
{
    DISPLAY_DEVICE dd;
    dd.cb = sizeof(DISPLAY_DEVICE);
    if (!EnumDisplayDevices(NULL, index, &dd, 0))
    {
        printf("EnumDisplayDevices failed:%d\n", GetLastError());
        return 0;
    }

    DISPLAY_DEVICE monitor;
    monitor.cb = sizeof(DISPLAY_DEVICE);
    if (!EnumDisplayDevices(dd.DeviceName, index, &monitor, 0))
    {
        printf("EnumDisplayDevices failed:%d\n", GetLastError());
        return 0;
    }

    DEVMODE dm;
    dm.dmSize = sizeof(DEVMODE);

    if (!EnumDisplaySettings(dd.DeviceName, ENUM_CURRENT_SETTINGS, &dm))
    {
        printf("EnumDisplaySettings failed:%d\n", GetLastError());
        return 0;
    }


       return dm.dmDisplayFrequency;
}

#include "Common/Common.hpp"


///List of arguments so i can regenerate a planet
const unsigned int Size = 2^16;
Arglist *PlanetArgLists;

int planetnum=0;


Arglist *SunArgLists;
int sunnum=0;




//#include "PerlinNoise/Header.hpp"

#include "Engine/Engine.hpp"

#include "Image/Image.hpp"

#include "Planet/Planet.hpp"


#include "PlanetHandler/PlanetHandler.hpp"

int Planet::xyoffset=0;







#include "SSystem/SSystem.hpp"



struct CurrentScene{
    SSystem *System;

    CurrentScene(){};


};

#include "Minimap/Minimap.hpp"

//#include <SFML/Window.hpp>
//#include <SFML/Window/Event.hpp>






int main(int argc, char *argv[])
///GAS GIANT ISNT WORKING
///Fixed
///Add effects when doing planet stuff down below, is not added up the top. So lighting can be adjusted. Also, we need a sun, and locations etc for planets with sun at center. :D
///Finished sun, lighting can be reasonably adjusted, useless lighting (tier2) removed.
///Still need to do proper solar system generation



///And orbits need plotting out

///Create fixed planet locations, then randomise which planet location a planet will get, and hence orbit equation (change radius). And speed, make speed somewhat determinedly random
///Need orbits

///Make sun 0,0?
///229125  earth widths a solar system is, fairly large.
///(done)

///Need to specify something being gas giant.
///Perhaps a gas giant list?
///I think that would be rather nice
///Added properties in atmosphere
///DONE


///accidental discovery :::: Lighting on center of gas giant = awesome
///Done
///add sun to a sun list for generation
///Done
///Need to actually store generated stuff.
///Still need to work out positions
///Done

///Definitely going to need a mipmap
///If the solar system is 250000*200 pixels across
///divide by  200, then divide by 10000
///Then, draw resulting distances to a surface (from halfscreen, halfscreen), blit to somewhere
///Done somewhat



///mercury is 36 million miles from sun
///36000000 miles
///900000+0 pixels.
///675000 is the constant in pixels



///229125 earth widths is the solar system radius im using

///3666000000 miles
///91650000 pixels across radiusways

///252000000

///132300000 is my prediction for bodes in pixels, close enough

///2147483648 is maximum size of signed 32bit integer, nice enough
/// 1 pixel = 1*40 miles
/// 1 mile = 1/40 pixels
/// Width of earth is 8000 miles
/// Width of earth is 200 pixels
///Could make planets size scale. Or just redo their generation





///Fix drawing
///Was never broken?


///Implement orbits.
///Implement loading the planet types from files


///Lighting needs to point at sun.


///minimap position not drawing properly
{


        initrand(100);


        UNI;
        UNI;
        UNI;
        ///This solar system has a few nice planets in. Cloud is a bit shitty though


        /*UNI;
        UNI;
        UNI;
        UNI;
        UNI;
        UNI;
        UNI;
        UNI;
        UNI;
        UNI;
        UNI;
        UNI;
        UNI;
        UNI;
        UNI;*/

        PlanetArgLists=new Arglist[Size];
        SunArgLists=new Arglist[Size];


        Engine Tonic(800, 600);

        planetnum=0;
        Planet::xyoffset=1;
        Limits l1, l2, l3;



        /*l1.load(220, 175, 50, 0);
        l2.load(175, 50, 260, 50);
        l3.load(0, 0, 0, 255);*/


        l1.load(175, 200, 180, 90);


        l2.load(0, 120, 100,10);
        l3.load(0, 200, 150, 70);



        DescA Atmos;
        Atmos.load(0, 1 ,120, 100, 50,0,1);

        ///Haze, atmosphere, R, G, B, Sun?, Rocky(1)|GasGiant(2)|Cold(3)


        //DescA Atmos(0, 0, 0, 255);

        Planet Arid("Arid",100, 0, 0, 8, 200+50, 100+20, l1, l2, l3, Atmos, -1, 1, -1, 1);   ///Tier 2 should be reflective, but i need to fix this. thats the third limit ///Tier 2 reflection no longer relevant
        ///could add in tier 2 reflection again, but you know. Rather pointless. Would need to specify which land mass is reflective.
        //Arid.add_effects();
        PlanetArgLists[planetnum]=Arid.return_planetdescriptor();

        planetnum++;


        //std::cout << "n";



        /*l1.load(300, 255, 150, 90);
         //218-165-32  //238-221-130 //arid brown

        l2.load(300, 180, 160,60);
        l3.load(300, 0, 0, 0);



        Atmos.load(0,0,155, 135, 55,0);*/

        l1.load(10, 155, 135, 55);
         //218-165-32  //238-221-130 //arid brown

        l2.load(0, 180, 160,60);
        l3.load(0, 0, 0, 0);



        Atmos.load(0,0,155, 135, 55,0,2);

        Planet GasGiant("Gasgiant",100, 250, 0, 4, -50, 100+20, l1, l2, l3, Atmos, -4, 4, -2,2);
        //GasGiant.add_effects();


        PlanetArgLists[planetnum]=GasGiant.return_planetdescriptor();

        planetnum++;

        //std::cout << planets[0].lightx;


        l1.load(175, 200, 200, 200);
        l2.load(100, 180, 180, 180);
        l3.load(0,255,255,255);

        Atmos.load(0,0, 200, 200, 200,0,3);

        Planet Ice("Ice", 100, 0, 250, 6,250, 80, l1, l2, l3, Atmos, -4, 4, -2, 2);
        //Ice.add_effects();
        PlanetArgLists[planetnum]=Ice.return_planetdescriptor();

        planetnum++;

        l1.load(255, 245, 245, 245);
        l2.load(100, 255, 255, 255);
        l3.load(90,255,255,255);

        Atmos.load(0,0, 200, 200, 200,0,2);

        Planet Cloud("Cloud", 100, 250, 250, 60, -50, 67, l1, l2, l3, Atmos, -4, 4, -2, 2);
        //Cloud.add_effects();
        PlanetArgLists[planetnum]=Cloud.return_planetdescriptor();
        planetnum++;

        l1.load(175, 120, 120, 120);
        l2.load(100, 255, 90, 50);
        l3.load(0,180,150,150);

        Atmos.load(0, 1, 180, 20, 20,0,1);

        Planet Red("Red", 100, 500, 0, 6, -50, 167, l1, l2, l3, Atmos, -4, 4, -2, 2);
        //Red.add_effects();
        PlanetArgLists[planetnum]=Red.return_planetdescriptor();
        planetnum++;
        l1.load(100, 255, 90, 50);
        l2.load(0, 255, 90, 50);
        l3.load(0,180,150,150);

        Atmos.load(0, 0, 180, 20, 20, 0,2);

        Planet redgasgiant("Redgasgiant", 100, 500, 250, 4, -50, 120, l1, l2, l3, Atmos, -4, 4, -2, 2);
        //redgasgiant.add_effects();
        PlanetArgLists[planetnum]=redgasgiant.return_planetdescriptor();
        planetnum++;


        /*l1.load(100, 300, 300, 300);
        l2.load(100, 180, 180, 0);
        l3.load(0,180,150,150);

        Atmos.load(0, 0, 255,255, 255, 1);

        Planet whitesun(150, 750, 0, 80, -50, 150, l1, l2, l3, &Atmos, -1, 1, -1, 1);*/


        /*l1.load(100, 300, 300, 100);
        l2.load(100, 180, 180, 0);
        l3.load(0,180,150,150);

        Atmos.load(0, 0, 255,255, 255, 1);

        Planet yellowsun(150, 750, 0, 80, -50, 150, l1, l2, l3, &Atmos, -1, 1, -1, 1);*/


        l1.load(10, 155, 135, 55);
         //218-165-32  //238-221-130 //arid brown

        l2.load(0, 180, 160,60);
        l3.load(0, 0, 0, 0);

        Atmos.load(0, 0, 155,135, 55, 1,0);

        Planet sun("Sun", 100, 0, 0,12, 100, 100, l1, l2, l3, Atmos, -4, 4, -2, 2 );

        SunArgLists[sunnum]=sun.return_planetdescriptor();
        sunnum++;



        ///Name, Radius, x, y, Atmospherewidth ,Lightx, Lighty, Terrain1, terrain2, terrain3, atmosphere, -x smooth, x smooth, -y smooth, smooth
        //UNI;
        ///Colour information descriptor
        ///above this number fill in, r, g, b


        bool state=true;



        SSystem System1;
        System1.load();

        Minimap minimap;




        //System1.delete_images();

        //std::cout <<System1.pz << "pz";

        //System1.load(1);


        CurrentScene system;

        system.System=&System1;
        minimap.load(system.System, 200, 200);

        Pass passme;
        passme.Sprite = new sf::Sprite;


        int speedstate=0;

        double T;

        const sf::Input& Input = Tonic.App.GetInput();
        sf::Event Event;
        sf::Clock clock;
        clock.Reset();


        Tonic.App.SetFramerateLimit(GetRefreshRate(0));
        Tonic.App.UseVerticalSync(true);

        while(state){

            clock.Reset();

            Tonic.App.GetEvent(Event);



            double frametime=Tonic.App.GetFrameTime();

                //printf("%i",23);

               if(Input.IsKeyDown(sf::Key::Left)){

                    Tonic.screenx-=700*frametime;
               }
               if(Input.IsKeyDown(sf::Key::Right)){
                    Tonic.screenx+=700*frametime;
               }
               if(Input.IsKeyDown(sf::Key::Up)){
                    Tonic.screeny-=700*frametime;
               }
               if(Input.IsKeyDown(sf::Key::Down)){
                    Tonic.screeny+=700*frametime;
               }
               if(Input.IsKeyDown(sf::Key::Escape)){
                    state=false;
               }



             for(int i=0; i<system.System->number; i++){

                 Planet *P=&system.System->PlanetManagements[i].planet;

                 system.System->PlanetManagements[i].updateimage();


                    if(P->shinex!=P->shinexm1 || P->shiney!=P->shineym1){
                    P->use_surface(&system.System->PlanetManagements[i].Orig);
                    P->add_lighting();

                    system.System->PlanetManagements[i].Updated.Copy(P->image.data, 0, 0);


                    }


                    else{



                        P->use_surface(&system.System->PlanetManagements[i].Updated);


                    }
                    system.System->PlanetManagements[i].updateimage();

                    Pass passable;
                    passable.Sprite=&P->image.image;
                    passable.Dest=P->image.Dest;
                    passable.Src=P->image.Src;


                    Tonic.add_image_end(passable);




                }


                minimap.clear();
                minimap.process(Tonic.screenx, Tonic.screenheight-Tonic.screeny);

                passme.Sprite->SetImage(minimap.Map);
                passme.Dest.x=Tonic.screenwidth-minimap.width;
                passme.Dest.y=Tonic.screenheight-minimap.height;
                passme.Dest.h=minimap.height;
                passme.Dest.w=minimap.width;
                passme.Src=passme.Dest;
                passme.Src.x=0;
                passme.Src.y=0;
                passme.r=1;


                Tonic.add_image_end(passme);




            Tonic.draw_all(Tonic.screenx, Tonic.screeny);

            Tonic.flip();
            Tonic.remove_all();
            std::cout << "R" << 1.0/clock.GetElapsedTime() << "\n";



        }
        delete passme.Sprite;



        //delete fps;







return 0;
}

