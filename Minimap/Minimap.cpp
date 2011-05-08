#include "Minimap.hpp"
#include "../SSystem/SSystem.hpp"

        Minimap::Minimap(SSystem *pSystem, int pwidth, int pheight) {
                load(pSystem, pwidth, pheight);
        }

        void Minimap::load(SSystem *pSystem, int pwidth, int pheight) {
                System=pSystem;
                width=pwidth;
                height=pheight;
                Map.Create(width, height);
        }

        void Minimap::clear() {
                Map.Create(width, height);
        }

        void Minimap::process(int x, int y) {


                for(int i=0; i<System->number; i++) {


                        PlanetHandler *P=&System->PlanetManagements[i];

                        double px, py;



                        signed long long int b;
                        long double a;
                        b=P->x;
                        a=(long double)b/(uint64_t)MAX_SOLAR;


                        a=(a*(width))/2.0;

                        px=a+height/2;


                        b=P->y;
                        a=(long double)b/(uint64_t)MAX_SOLAR;
                        a=(a*(height))/2.0;

                        py=a+height/2;

                        sf::Color C=sf::Color(254, 254, 254);
                        Set_pixel(&Map, px, py, C);

                }

                Set_pixel(&Map, ((x/200)/1000)/2 + 100, (y/200/1000/2) + 100, sf::Color(255, 0, 0));

        }

        Minimap::Minimap() {}
