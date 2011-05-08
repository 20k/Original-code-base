#ifndef SSYSTEM_HEADER
#define SSYSTEM_HEADER
#include "../PlanetHandler/PlanetHandler.hpp"
#include "../Common/Common.hpp"

///For a quick description of what this class does
///It contains a list of planets and handles solar system generation.
///Assigning positions etc should be done through the planethandler class, not the planet class within the planethandler class
///pz and pw store the seedsd for the random number generator (UNI)


class SSystem
{
public:
        int x, y;

        ///relative galaxy view, but not now

        int number; ///of planets


        PlanetHandler *PlanetManagements; ///Generated planets are stored in here
        int *numbertolist;

        unsigned long pz, pw; ///Storage of seeds used to create solar system

        SSystem();

        void storezw();

        void give_positions();

        void load(int old=0);

        void delete_images();



};
#endif
