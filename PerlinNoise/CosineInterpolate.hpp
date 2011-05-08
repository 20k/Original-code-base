#ifndef COSINEINTERPOLATE_HEADER
#define COSINEINTERPOLATE_HEADER
inline double CosineInterpolate(double a, double b, double x )
{
        double ft = x * 3.1415927;
        double f = ((1.0 - cos(ft)) * 0.5);

        return  (a*(1.0-f) + b*f);
}
#endif
