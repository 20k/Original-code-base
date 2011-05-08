#ifndef PERLINNOISE_MEM_HEADER
#define PERLINNOISE_MEM_HEADER
#include <SDL.h>

double **PerlinNoise_Mem(int Xoffset,int Yoffset, int Width, int Height, int Octaves, int Frequency, double Zoom){



        double *** Arraymain;
        Arraymain=new double**[Octaves];


        double **Array;
        Array=new double*[Width];

        for(int i=0; i<Width; i++) {
                Array[i]=new double[Height];
        }

        for(int i=0; i<Octaves; i++) {
            #ifdef _MSC_VER
                Arraymain[i]=InterpolatedArray_Mem(Xoffset, Yoffset, Width, Height, pow(long double(Frequency), long double(i)), Zoom);

            #else
                Arraymain[i]=InterpolatedArray_Mem(Xoffset, Yoffset, Width, Height, pow(Frequency, i), Zoom);
            #endif
        }


        for(int x=0; x<Width; x++) {
                for(int y=0; y<Height; y++) {

                        double Total=0;
                        for(int i=0; i<Octaves; i++) {
                                Total+=Arraymain[i][x][y];
                        }
                        Array[x][y]=(Total/Octaves);

                        Array[x][y]=Array[x][y]/0.75;



                }
        }

        for(int i=0; i<Octaves; i++){

            for(int x=0; x<Width; x++){

                delete [] Arraymain[i][x];

            }
            delete [] Arraymain[i];



        }

        delete [] Arraymain;

        return Array;
}
#endif
