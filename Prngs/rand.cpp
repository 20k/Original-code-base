
#include "rand.hpp"
#include <time.h>
#include <cstdlib>

void initrand(int seed)
{
        srand((unsigned)(time(0)));
}



int randint(int max)
{
        return int(max*rand()/(RAND_MAX+1.0));
}



int randint(int min, int max)
{
        if (min>max) {
                return max+int((min-max+1)*rand() / (RAND_MAX+1.0));
        } else {
                return min+int((max-min+1)*rand() / (RAND_MAX+1.0));
        }
}

double randdouble()
{
        return rand()/(double(RAND_MAX)+1);
}

double randdouble(double max)
{
        return randdouble()*max;
}


double randdouble(double min, double max)
{
        if (min>max) {
                return randdouble()*(min-max)+max;
        } else {
                return randdouble()*(max-min)+min;
        }
}


inline void setseed(unsigned long i1,unsigned long i2)
{
        z=i1;
        w=i2;
}
