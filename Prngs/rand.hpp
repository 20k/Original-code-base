#ifndef RAND_HEADER
#define RAND_HEADER
void initrand(int seed);
int randint(int max);
int randint(int min, int max);
double randdouble();
double randdouble(double max);
double randdouble(double min, double max);



#define znew  ((z=36969*(z&65535)+(z>>16))<<16)
#define wnew  ((w=18000*(w&65535)+(w>>16))&65535)
#define IUNI  (znew+wnew)
#define UNI   (znew+wnew)*2.328306e-10
static unsigned long z=362436069, w=521288629;
inline void setseed(unsigned long i1,unsigned long i2);
#endif
