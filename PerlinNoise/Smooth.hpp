#ifndef SMOOTH_HEADER
#define SMOOTH_HEADER
inline double Smooth(int i, int j)
{
        return (double)(Noise2(i, j)+Noise2(i+1, j)+Noise2(i, j+1)+Noise2(i+1, j+1))/4;
}
#endif
