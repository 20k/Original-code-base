#ifndef MINIMAP_HEADER
#define MINIMAP_HEADER
#include "../SSystem/SSystem.hpp"

class Minimap { ///Yes yes, it isnt a mipmap
public:
        int drawx, drawy;

        sf::Image Map;

        SSystem *System;

        int width, height;

        Minimap(SSystem *pSystem, int pwidth, int pheight);

        void load(SSystem *pSystem, int pwidth, int pheight);
        void clear();
        void process(int x, int y);

        Minimap();

};
#endif
