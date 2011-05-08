///For a quick description of what this class does
///It contains a list of planets and handles solar system generation.
///Assigning positions etc should be done through the planethandler class, not the planet class within the planethandler class
///pz and pw store the seedsd for the random number generator (UNI)
#include "SSystem.hpp"
#include "../Prngs/Rand.hpp"



      SSystem::SSystem(){

      }


        void SSystem::storezw(){
        pz=z;
        pw=w;

        }

        void SSystem::give_positions(){
            for(int i=1; i<number; i++){

                PlanetManagements[i].fromsun=(INITIALDISTANCE + (BODECONSTANT*i*i));
                PlanetManagements[i].x=(INITIALDISTANCE + (BODECONSTANT*i*i));
                PlanetManagements[i].y=0;
                //printf("%i\n", PlanetManagements[i].x);

                PlanetManagements[i].planet.image.Dest.x=PlanetManagements[i].x;
                PlanetManagements[i].planet.image.Dest.y=PlanetManagements[i].y;
            }

            PlanetManagements[0].x=200;
            PlanetManagements[0].planet.image.Dest.x=200;
            PlanetManagements[0].y=200;
            PlanetManagements[0].planet.image.Dest.y=200;
            PlanetManagements[0].fromsun=200; ///Sun this is
           //printf("N:%s", PlanetManagements[0].planet.name.c_str());
        }


        void SSystem::load(int old){        ///maybe "init rand(systemsoffset) systemsoffset++?

            ///Ok, use planet distribution class with static seed for random distribution of planets, how many and what class of planets should be generated.

            //int n=3;
            ///int n=randint(1, 9); ///Do max planets define
            ///You know, it turns out that this is a lot, lot better.
            ///Generate N planets
            ///Generate Sun, first in array.
            ///Generate R rocky planets, fill array
            ///Generate Q remote planets
            ///Generate N-R-Q gas giants, fill array
            ///Generate Q remote, cold planets.

            ///Thus array will go:
            ///Sun, R Rocky(/exotic) planets, N-R-Q Gas(/cloud?) giants, Q Cold(/cloud?) planets.
            //int p=23;

            //for(int i=0; i<p; i++)
            //UNI;

            //seed = systemsoffset;
            int N=old;
            unsigned long tr1=z, tr2=w;


            if(old==0){
                pz=z;
                pw=w;
            }
            else{
                N=1;
                z=pz;
                w=pw;

            }



            int n=(UNI*9)+1;
            number=n;
            PlanetManagements= new PlanetHandler[n];
            numbertolist = new int[n];





            int RockyNum=floor(((UNI*n))); ///so between 0 and maxnum planets.
            //exit(RockyNum);

            for(int i=1; i<RockyNum; i++){
                int Rocknum=UNI*planetnum;

                if(PlanetArgLists[Rocknum].atmosphere.type==1){
                PlanetManagements[i].load(PlanetArgLists[Rocknum]);
                }
                else{
                    i--;

                }


            }
            //int Temp;
            int GasNum=floor((UNI*(n)))-RockyNum;
            //exit(n-RockyNum);
            //exit(n);


            for(int i=RockyNum; i<GasNum+RockyNum; i++){
            int gasnum=UNI*planetnum;

                if(PlanetArgLists[gasnum].atmosphere.type==2){
                PlanetManagements[i].load(PlanetArgLists[gasnum]);
                }
                else{
                    i--;

                }


            }


            int moonnum=n-RockyNum-GasNum;


            for(int i=RockyNum+GasNum; i<moonnum+GasNum+RockyNum; i++){
            int mn=UNI*planetnum;

                if(PlanetArgLists[mn].atmosphere.type==3){
                PlanetManagements[i].load(PlanetArgLists[mn]);
                }
                else{
                    i--;

                }


            }

            int SunNum=floor(UNI*sunnum);

            PlanetManagements[0].load(SunArgLists[SunNum]);

            if(N==1){
                z=tr1, w=tr2;
            }



            give_positions();




        }

        void SSystem::delete_images(){
            //delete Orig;
            //delete
            for(int i=0; i<number; i++){
                PlanetManagements[i].delete_images();
                //delete [] PlanetManagements;

            }
            delete [] numbertolist;
        }




