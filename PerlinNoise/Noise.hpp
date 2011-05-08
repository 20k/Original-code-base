#ifndef NOISE_HEADER
#define NOISE_HEADER
inline double Noise2(int x, int y)
{
        int n=(int)x+(int)y*337;

        n=(n<<13)^n;

        int nn=(n*(n*n*41333 +53307781)+1376312589)&0x7fffffff;

        return 1.0-((double)nn/1073741824.0);
}
#endif
