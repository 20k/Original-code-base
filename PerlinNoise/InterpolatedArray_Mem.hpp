#ifndef INTERPOLATEDARRAY_MEM_HEADER
#define INTERPOLATEDARRAY_MEM_HEADER

class XYD{

    public:
        double x, y;

        XYD(){
        }

};


void distort(double x, double y, XYD&dest, double radius, double xoffset=0, double yoffset=0){  ///radius offsets

        dest.x=(1-((sqrt((x-radius-xoffset)*(x-radius-xoffset) + (y-radius-yoffset)*(y-radius-yoffset))/radius)))*(x-radius-xoffset)+radius;      //+100;
        dest.y=(1-((sqrt((x-radius-xoffset)*(x-radius-xoffset) + (y-radius-yoffset)*(y-radius-yoffset))/radius)))*(y-radius-yoffset)+radius;      //+20;


        //(1-((sqrt((x-radius)*(x-radius) + (y-radius)*(y-radius))/radius)))*(y-radius)+radius;
}

void distort_class_free(double x, double y, XYD&dest){

            double z;
            double tmp, rx, ry;
            double ri = 0.5f; // refraction index

            z = (double)sqrt(1.0 - (x * x)  - (y * y));

            rx = ri * x;
            tmp = (double)sqrt(1.0- (rx * rx) - (y * y));
            dest.x = rx * (1.0- (y * y)) / ((z * tmp) + (rx * x));

            ry = ri * y;
            //exit(dest.x);
            tmp = (double)sqrt(1.0- (x * x) - (ry * ry));
            dest.y = ry * (1.0-(x * x)) / ((z * tmp) + (ry * y));       //+20;

        }


inline double ** InterpolatedArray_Mem(int Xoffset, int Yoffset,int pWidth, int pHeight,int Frequency, double Zoom=1)
{
    int radius=-1;
    XYD r;
    XYD p;
    XYD fin;


        double **Interpolated=new double*[pWidth+1];

        for(int i=0; i<pWidth+1; i++) {
                Interpolated[i]=new double[pHeight+1];
        }

        for(int i=0; i<pWidth+1; i++) {

                for(int j=0; j<pHeight+1; j++) {




                        double X=(((i+Xoffset)*Frequency)/Zoom);
                        double Y=(((j+Yoffset)*Frequency)/Zoom);
                        fin.x=i;
                        fin.y=j;

                        if(pWidth==pHeight){

                            radius=pWidth/2.0;

                            distort(X, Y, p, radius);
                            r=p;


                        }else{
                                r.x=X;
                                r.y=Y;
                        }




                        double V1 = Smooth(r.x ,r.y);

                        double V2= Smooth(r.x+1, r.y);

                        double V3=Smooth(r.x, r.y+1);

                        double V4=Smooth(r.x+1,r.y+1);


                        double I1=CosineInterpolate(V1, V2, r.x-int(r.x));

                        double I2=CosineInterpolate(V3, V4, r.x-int(r.x));
                        int lx, ly;
                        lx=fin.x;
                        ly=fin.y;
                        Interpolated[lx][ly]=CosineInterpolate(I1, I2,r.y-int(r.y));
                        Interpolated[lx][ly]+=1;
                        Interpolated[lx][ly]/=2;


                }

        }



        delete [] Interpolated[pWidth];


        return Interpolated;
}
#endif
