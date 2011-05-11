#include "Planet.hpp"
#include "../Image/Image.hpp"

#include "../PerlinNoise/Header.hpp"


        void Planet::set_pixel_with_variance(register int r, register int g, register int b, double variance, register int px, register int py, register int check) {


            int br, bg, bb;
            br=r*variance;
            bg=g*variance;
            bb=b*variance;
            if(check==1){

            if(br>255){
               br=255;
            }
            if(br<0){
                br=0;
            }
            if(bg>255){
               bg=255;
            }
            if(br<0){
                bg=0;
            }
            if(bb>255){
                bb=255;
            }
            if(br<0){
                bb=0;
            }
            }

            sf::Color Temp;
            Temp.r=br;
            Temp.g=bg;
            Temp.b=bb;

                image.set_pixel(px, py, Temp);


        }

        Planet::load_from_file(std::string pname){
            FILE *P=fopen(pname.c_str(), "r");
            if(P==NULL){
                exit(13313);
            }
            char *string = new char[100];

            Arglist R;
            R.name=fgets(string, 100, P);
            R.atmosphere=fgets(string, 100, P);


            R.l1.limit=fgets(string, 100, P);


            int B=atoi(fgets(string, 100, P));
            R.l1.col.r=B>>4;
            R.l1.col.g=((B<<2)>>2)>>2;
            R.l1.col.b=((B<<4)>>4);

            R.l2.limit=fgets(string, 100, P);


            B=atoi(fgets(string, 100, P));
            R.l2.col.r=B>>4;
            R.l2.col.g=((B<<2)>>2)>>2;
            R.l2.col.b=((B<<4)>>4);

             R.l3.limit=fgets(string, 100, P);


            B=atoi(fgets(string, 100, P));
            R.l3.col.r=B>>4;
            R.l3.col.g=((B<<2)>>2)>>2;
            R.l3.col.b=((B<<4)>>4);

            ///DescA(int pHaze, int pAtmosphere, int pr, int pg, int pb, int psun, int ptype){












            delete [] String;

        }

        double Planet::average_square(int x, int y,int xsize, int ysize) {

                double Total=0, Count=0;
                for(int i=-xsize+1; i<xsize; i++) {
                        for(int j=-ysize+1; j<ysize; j++) {

                                if(x+i>0 && x+i<radius*2 && y+j>0 && y+j<radius*2) {
                                        Total+=data[x+i][y+j];
                                        Count++;

                                }

                        }
                }

                if(Count!=0) {
                        //data[x][y]=Total/Count;
                        return Total/Count;

                }


        }


        Colour Planet::get_colours_from_heightmap(int x, int y ) {

                Colour C;

                if(data[x][y]*255>limit1.limit) {
                        //C.load(limit..r, flc.g , flc.b);
                        C=limit1.col;
                        //150 75 0
                } else if(data[x][y]*255>limit2.limit) {

                        //C.load(slc.r, slc.g, flc.b);        ///Make class for this sort of argument things would be nice.
                        C=limit2.col;
                        //50 260 50

                } else {

                        //C.load(everythingelse.r, everythingelse.g, everythingelse.b);
                        C=limit3.col;

                }

                return C;


        }


        int Planet::return_tier(int x, int y) {
                int tier=0;

                if(data[x][y]*255>limit1.limit) {
                        tier=0;
                } else if(data[x][y]*255>limit2.limit) {

                        tier=1;

                } else {

                        tier=2;

                }


                return tier;

        }

        void Planet::generate_image() {

                //bool sea=false;
                //bool land=false;
                //double average;
                //int sx=1, sy=1;
                Colour C;

                Colour Last;


                for(int x=0; x<radius*2; x++) {
                        for(int y=0; y<radius*2; y++) {

                                if((sqrt(pow(x-radius, 2)+pow(y-radius,2)))<radius) {

                                        Colour Final(0,0,0);

                                        //Final.load(0,0,0);

                                        Last=Final;
                                        Final=get_colours_from_heightmap(x, y);


                                        int Check=0;
                                        int LastCheck=0;
                                        int xlowerlim=1, xupperlim=1, ylowerlim=1, yupperlim=1;

                                        if(x+-xlowerlim>0 && x+xlowerlim<radius*2 ) {

                                                for(int i=-xlowerlim; i<xupperlim+1; i++) {

                                                        Check=return_tier(x+i, y);
                                                        LastCheck=return_tier(x+i-1, y);

                                                        if(Check!=LastCheck) {

                                                                Final=get_colours_from_heightmap(x-1, y);
                                                                #ifdef SHADING

                                                                set_pixel_with_variance((Final.r+Last.r)/2, (Final.g+Last.g)/2, (Final.b+Last.b)/2,data[x-1][y], x-1, y);
                                                                #endif


                                                        }


                                                }
                                        }

                                        Check=0;

                                        if(y+-ylowerlim>0 && y+ylowerlim<radius*2 ) {

                                                for(int i=-ylowerlim; i<yupperlim+1; i++) {

                                                        Check=return_tier(x, y+i);
                                                        LastCheck=return_tier(x, y+i-1);

                                                        if(Check!=LastCheck) {

                                                                Final=get_colours_from_heightmap(x, y-1);

                                                                #ifdef SHADING

                                                                set_pixel_with_variance((Final.r+Last.r)/2, (Final.g+Last.g)/2, (Final.b+Last.b)/2,data[x][y-1], x, y-1);
                                                                #endif


                                                        }

                                                }
                                        }


                                        set_pixel_with_variance(Final.r, Final.g, Final.b, data[x][y], x, y, 1);

                                        if(Atmosphere.sun==1){
                                            //set_pixel_with_variance(Final.r, Final.g, Final.b, 1, x, y, 1);
                                        }









                                } else {
                                        // image.set_pixel(x, y, {255, 0, 255});
                                        set_pixel_with_variance(255, 0, 255, 1, x, y);


                                }



                        }

                }



        }

        void Planet::use_surface(sf::Image *mage){
            imagepassed=1;
            image.Del=1;

            //image.Surface=CopySurface(mage);
            image.data.Copy(*mage, 0, 0);

            image.update_to_surface();
        }

        int Planet::return_appropriate_image_lighting(){

            if(shinexm1!=shinex || shineym1!=shiney){
                return 1;

            }
            else{
                return 0;

            }


        }



        void Planet::parse_data(int minx, int maxx, int miny, int maxy) {

                for(int x=0; x<radius*2; x++) {

                        for(int y=0; y<radius*2; y++) {

                                if(sqrt(pow(x-radius, 2)+pow(y-radius,2))<radius) {

                                        //if(x+1<radius*2 && x-1>0 && y+1<radius*2 && y-1>0){

                                        //data[x][y]=(data[x][y]+data[x+1][y]+data[x-1][y]+data[x][y+1]+data[x][y+1]+data[x+1][y+1]+data[x-1][y-1]+data[x+1][y-1]+data[x-1][y+1])/9;

                                        //}

                                        double Total=0;
                                        double Count=0;

                                        for(int i=minx; i<maxx; i++) {       ///Lopside the terrain generation and smooth the heightmap to remove little things.
                                                for(int j=miny; j<maxy; j++) {

                                                        if(x+i>0 && x+i<radius*2  && y+j>0 && y+j<radius*2 ) {
                                                                Total+=data[x+i][y+j];
                                                                Count++;

                                                        }

                                                }
                                        }

                                        if(Count!=0) {
                                                data[x][y]=Total/Count;

                                        }



                                }




                        }




                }


        }



        void Planet::add_atmosphere(DescA acolour, int Do) {

                for(int x=0; x<radius*2; x++) {
                        for(int y=0; y<radius*2; y++) {

                                if(sqrt(pow(x-radius, 2)+pow(y-radius,2))<radius && sqrt(pow(x-radius, 2)+pow(y-radius,2))>radius-AtmosphereWidth) {
                                        //if(Do==1)
                                        //double variance=(0.1001/(double)((sqrt(pow(x-radius, 2)+pow(y-radius,2)))/(double)sqrt(pow(radius, 2)+pow(radius, 2))));


                                        //double maxDfR=sqrt(pow(radius+AtmosphereWidth, 2)+pow(radius+AtmosphereWidth, 2));

                                        //double DfR=sqrt(pow(x-radius, 2)+pow(y-radius, 2))-radius;

                                        //double variance=1.0/((DfR)/(double)AtmosphereWidth);
                                        /*double variance=sqrt(pow(x-radius, 2)+pow(y-radius, 2))/(double)(radius+AtmosphereWidth);
                                        //std::cout << variance << "n";

                                        variance-=0.8;
                                        variance*=8;
                                        variance=0.6/variance;*/

                                        double a=pow(x-radius, 2);
                                        double b=pow(y-radius, 2);
                                        double c=sqrt(a+b);

                                        c=c-radius;
                                        double variance=c/AtmosphereWidth;


                                        variance=-variance;


                                        if(Do!=0)
                                        set_pixel_with_variance(acolour.r, acolour.g, acolour.b, variance, x, y, 1);

                                        //if(Do==0){
                                           //     set_pixel_with_variance(0, 0, 0, 0, x, y, 1);
                                        //}

                                        //else
                                        //set_pixel_with_variance(0, 0, 0, 1, x,y);


                                } else if (sqrt(pow(x-radius, 2)+pow(y-radius,2))>=radius) {
                                        set_pixel_with_variance(0, 0, 0, 1, x,y);

                                }
                        }

                }

        }

        void Planet::add_to_pixel_with_variance(int r, int g, int b, double variance, int px, int py) {

            sf::Color Col;
            Col.r=r*variance;
            Col.g=g*variance;
            Col.b=b*variance;

            //if(Check)

                image.add_to_pixel(px, py, Col); ///safe>255


        }

        void Planet::add_shine_old(double shinex, double shiney, int type){



                ///Center of shine is radius+0.5*radius, radius


                ///So cycle through image, and add 1/(distancefromthing/maxdistance(radius+radius*0.5?))
                ///Not so bad

                for(int x=0; x<radius*2; x++) {
                        for(int y=0; y<radius*2; y++) {


                            //if(return_tier(x, y)==2){

                                if(sqrt(pow(x-radius, 2)+pow(y-radius,2))<radius) {

                                   // int Blue=10*(5/(double)((sqrt(pow(x-(shinex), 2)+pow(y-(shiney),2)))/(double)sqrt(pow(radius+radius*0.5, 2)+pow(radius+radius*0.5, 2))));
                                   //int Blue=10*(5/(double)((sqrt(pow(x-(shinex), 2)+pow(y-(shiney),2)))/(double)sqrt(pow(shinex, 2)+pow(shiney, 2))));

                                   double x2=pow(x-shinex, 2);
                                   double y2=pow(y-shiney, 2);
                                   double sq=sqrt(x2+y2);

                                   double sx2=pow(radius-shinex, 2);
                                   double sy2=pow(radius-shiney, 2);
                                   double ssq=sqrt(sx2+sy2);

                                   int Blue=10*(13/double(sq/ssq));

                                   if(x==shinex && y==shiney){
                                        Blue=255;

                                   }

                                if(Blue>255){

                                    Blue=255;
                                }

                                if(type==1&&return_tier(x, y)==2){

                                        add_to_pixel_with_variance(Blue, Blue, Blue, 0.6, x, y); ///Make it times by current pixel amount
                                }
                                        //add_to_pixel_with_variance(0, 0, 0, Blue/255, x, y);
                                        else if(type==2){
                                        sf::Color Col=
                                        Get_pixel(&image.data, x, y);


                                        double Temp=(Blue/100.0)-1.0;  ///0.80 is nice

                                        if(Temp>1){
                                            //Temp=1;

                                        }
                                        if(Temp<0){
                                            Temp=0;
                                        }


                                        set_pixel_with_variance(Col.r, Col.g, Col.b, Temp , x, y, 1);
                                        //add_to_pixel_with_variance(Col.r, Col.g, Col.b, Temp , x, y);
                                        }

                                }
                            //}
                        }
                }

        }

                void Planet::add_shine_pre_half(double shinex, double shiney, int type){



                ///Center of shine is radius+0.5*radius, radius


                ///So cycle through image, and add 1/(distancefromthing/maxdistance(radius+radius*0.5?))
                ///Not so bad

                for(int x=0; x<radius*2; x++) {
                        for(int y=0; y<radius*2; y++) {


                            //if(return_tier(x, y)==2){

                                if(sqrt(pow(x-radius, 2)+pow(y-radius,2))<radius) {

                                   // int Blue=10*(5/(double)((sqrt(pow(x-(shinex), 2)+pow(y-(shiney),2)))/(double)sqrt(pow(radius+radius*0.5, 2)+pow(radius+radius*0.5, 2))));
                                   //int Blue=10*(5/(double)((sqrt(pow(x-(shinex), 2)+pow(y-(shiney),2)))/(double)sqrt(pow(shinex, 2)+pow(shiney, 2))));

                                    double x2=pow(x-shinex, 2);
                                    double y2=pow(y-shiney, 2);
                                    double sq=sqrt(x2+y2);
                                    //if(sq==0){
                                    //    sq=1;

                                   // }

                                   //double sx2=pow(radius-shinex, 2);
                                   //double sy2=pow(radius-shiney, 2);
                                   //double ssq=sqrt(sx2+sy2);

                                   //int Blue=10*(13/double(sq/ssq));

                                   int Blue=20000/sq;
                                   //Blue=Blue;

                                   if(x==shinex && y==shiney){
                                        Blue=999999;

                                   }

                                if(Blue>255){

                                    //Blue=255;
                                }


                                        sf::Color Col=
                                        Get_pixel(&image.data, x, y);


                                        double Temp=(Blue/100.0)-1.0;  ///0.80 is nice

                                        if(Temp<0){
                                            Temp=0;
                                        }


                                        set_pixel_with_variance(Col.r, Col.g, Col.b, pow(Temp, 1.1) , x, y, 1);
                                        //add_to_pixel_with_variance(Col.r, Col.g, Col.b, Temp , x, y);


                                }
                            //}
                        }
                }

        }


        void Planet::add_shine(double shinex, double shiney, int type){



                ///Center of shine is radius+0.5*radius, radius


                ///So cycle through image, and add 1/(distancefromthing/maxdistance(radius+radius*0.5?))
                ///Not so bad

                for(int x=0; x<radius*2; x++) {
                        for(int y=0; y<radius*2; y++) {


                            //if(return_tier(x, y)==2){

                                if(sqrt(pow(x-radius, 2)+pow(y-radius,2))<radius) {

                                   // int Blue=10*(5/(double)((sqrt(pow(x-(shinex), 2)+pow(y-(shiney),2)))/(double)sqrt(pow(radius+radius*0.5, 2)+pow(radius+radius*0.5, 2))));
                                   //int Blue=10*(5/(double)((sqrt(pow(x-(shinex), 2)+pow(y-(shiney),2)))/(double)sqrt(pow(shinex, 2)+pow(shiney, 2))));

                                    double x2=pow(x-shinex, 2);
                                    double y2=pow(y-shiney, 2);
                                    double sq=sqrt(x2+y2);
                                    //if(sq==0){
                                    //    sq=1;

                                   // }

                                   //double sx2=pow(radius-shinex, 2);
                                   //double sy2=pow(radius-shiney, 2);
                                   //double ssq=sqrt(sx2+sy2);

                                   //int Blue=10*(13/double(sq/ssq));

                                   int Blue=20000/sq;
                                   //Blue=Blue;

                                   if(x==shinex && y==shiney){
                                        Blue=999999;

                                   }

                                if(Blue>200){

                                    //Blue=200;
                                }


                                        sf::Color Col=
                                        Get_pixel(&image.data, x, y);


                                        double Temp=(Blue/100.0)-1.0;  ///0.80 is nice

                                        if(Temp<0){
                                            Temp=0;
                                        }


                                        set_pixel_with_variance(Col.r, Col.g, Col.b, pow(Temp, 0.7) , x, y, 1);
                                        //add_to_pixel_with_variance(Col.r, Col.g, Col.b, Temp , x, y);


                                }
                            //}
                        }
                }

        }




        void Planet::add_sun_shine(double shinex, double shiney){



                ///Center of shine is radius+0.5*radius, radius


                ///So cycle through image, and add 1/(distancefromthing/maxdistance(radius+radius*0.5?))
                ///Not so bad

                for(int x=0; x<radius*2; x++) {
                        for(int y=0; y<radius*2; y++) {


                            //if(return_tier(x, y)==2){

                                if(sqrt(pow(x-radius, 2)+pow(y-radius,2))<radius) {

                                   // int Blue=10*(5/(double)((sqrt(pow(x-(shinex), 2)+pow(y-(shiney),2)))/(double)sqrt(pow(radius+radius*0.5, 2)+pow(radius+radius*0.5, 2))));
                                   //int Blue=10*(5/(double)((sqrt(pow(x-(shinex), 2)+pow(y-(shiney),2)))/(double)sqrt(pow(shinex, 2)+pow(shiney, 2))));

                                   double x2=pow(x-shinex, 2);
                                   double y2=pow(y-shiney, 2);
                                   double sq=sqrt(x2+y2);

                                   //double sx2=pow(radius-shinex, 2);
                                   //double sy2=pow(radius-shiney, 2);
                                   //double ssq=sqrt(sx2+sy2);

                                   //int Blue=10*(13/double(sq/ssq));

                                   int Blue=10000*(1/sq);

                                   if(x==shinex && y==shiney){
                                        Blue=9999;

                                   }

                                //if(Blue>255){

                                    //Blue=255;
                                //}


                                        sf::Color Col=
                                        Get_pixel(&image.data, x, y);


                                        double Temp=(Blue/100.0)-1.0;  ///0.80 is nice

                                        if(Temp<0){
                                            Temp=0;
                                        }


                                        set_pixel_with_variance(Col.r, Col.g, Col.b, pow(Temp, 2) , x, y, 1);
                                        //add_to_pixel_with_variance(Col.r, Col.g, Col.b, Temp , x, y);


                                }
                            //}
                        }
                }

        }






        void Planet::add_scatter(){ ///Before atmosphere
            for(int x=0; x<radius*2; x++){
                    for(int y=0; y<radius*2; y++){
                        if(sqrt(pow(x-radius, 2)+pow(y-radius,2))<radius) {

                            add_to_pixel_with_variance(20, 20, 125, 1, x, y);    ///Should change this, but you know. i bored

                        }
                    }
            }
        }

        void Planet::add_hal_region(int Sun){
            int Thickness=1;
            Colour Hal_Colour(255, 255, 255);

            double variance = 0.615;

            for(int x=0; x<radius*2; x++){
                for(int y=0; y<radius*2; y++){

                     if(sqrt(pow(x-radius, 2)+pow(y-radius,2))<radius-AtmosphereWidth && sqrt(pow(x-radius, 2)+pow(y-radius,2))>radius-AtmosphereWidth-Thickness) {

                            data[x][y]=160.0/255.0;

                            if(Sun==1){


                                sf::Color Col=Get_pixel(&image.data, x, y);
                                Hal_Colour.load(Col.r, Col.g, Col.b);

                                double a=pow(x-radius, 2);
                                double b=pow(y-radius, 2);
                                double c=sqrt(a+b);

                                c=c-radius;
                                variance=c/(Thickness);
                                variance=variance+4;


                                variance=-variance;
                                variance=variance-0.5;

                                if(variance>0){
                                    variance=-variance;
                                }
                                variance=variance;
                                variance=variance+0.5;
                                variance/=2;



                                add_to_pixel_with_variance(Hal_Colour.r, Hal_Colour.g, Hal_Colour.b, variance, x, y);

                                //Col=Get_pixel(image.Surface, x, y);





                            }
                            else{
                                set_pixel_with_variance(Hal_Colour.r, Hal_Colour.g, Hal_Colour.b, variance, x, y, 1);
                            }



                    }

                }

            }

        }



        Planet::~Planet(){

        }


        Arglist Planet::return_planetdescriptor(){

            Arglist P(data ,name,(int)radius, (int)AtmosphereWidth, (int)shinex, (int)shiney, limit1,limit2, limit3, Atmosphere, (int)sminx, (int)smaxx,(int) sminy, (int)smaxy);
            return P;

        }


        void Planet::add_blur(){
            sf::Color Col;
            //int Nienn=0;
            for(int x=0; x<radius*2+AtmosphereWidth*2; x++){
                for(int y=0; y<radius*2+AtmosphereWidth*2; y++){

                    if(sqrt(pow(x-radius, 2)+pow(y-radius,2))<radius && sqrt(pow(x-radius, 2)+pow(y-radius,2))>radius-AtmosphereWidth) {

                                        //double variance=sqrt(pow(x-radius, 2)+pow(y-radius, 2))/(double)(radius+AtmosphereWidth);
                                        double a=pow(x-radius, 2);
                                        double b=pow(y-radius, 2);
                                        double c=sqrt(a+b);

                                        c=c-radius;
                                        double variance=c/AtmosphereWidth;


                                        variance=-variance;

                                        Col=Get_pixel(&image.data, x, y);

                                        set_pixel_with_variance(Col.r, Col.g, Col.b, pow(variance, 1), x, y, 1);


                    }

                }

            }


        }


        void Planet::add_extreme_variance(){

                for(int x=0; x<radius*2; x++){   //=atmospherewidth, -atmospherewidth?
                        for(int y=0; y<radius*2; y++){
                                if(sqrt(pow(x-radius, 2)+pow(y-radius,2))<radius-AtmosphereWidth){

                                        add_to_pixel_with_variance(1, 1, 1, data[x][y]*150, x, y);
                                        add_to_pixel_with_variance(-90, -90, -90, 1.2, x, y);

                                }


                        }


                }
        }



        void Planet::load_from_descriptor(Arglist p){


            load(p.name,p.radius, 0, 0, p.atmospherewidth, p.lightx, p.lighty, p.l1, p.l2, p.l3, p.atmosphere, p.minx, p.maxx, p.miny, p.maxy, p.Terrain,p.pass);

        }

        /*void distort(float x, float y, SDL_Rect &dest) {
            float z;
            float tmp, rx, ry;
            float ri = 0.5f; // refraction index

            z = (float)sqrt(1 - (x * x)  + (y * y));

            rx = ri * x;
            tmp = (float)sqrt((rx * rx) + (y * y));
            dest.x = rx * ((y * y)) / ((z * tmp) + (rx * x));

            ry = ri * y;
            tmp = (float)sqrt((x * x) + (ry * ry));
            dest.y = ry * ((x * x)) / ((z * tmp) + (ry * y));
            }*/


        void Planet::distort_class(double x, double y, preciserect&dest){ ///Shamelessly nicked off internet

            float z;
            float tmp, rx, ry;
            float ri = 0.6f; // refraction index

            z = (float)sqrt(1.0 - (x * x)  - (y * y));

            rx = ri * x;
            tmp = (float)sqrt(1.0- (rx * rx) - (y * y));
            dest.x = rx * (1.0- (y * y)) / ((z * tmp) + (rx * x));

            ry = ri * y;
            tmp = (float)sqrt(1.0- (x * x) - (ry * ry));
            dest.y = ry * (1.0-(x * x)) / ((z * tmp) + (ry * y));       //+20;

        }

        void Planet::circularise_image(){

            sf::Image *newimage = new sf::Image;
            newimage->Create(image.Src.w, image.Src.w);
            newimage->Copy(image.data, 0, 0);
            //preciserect Dest={0,0,0,0};
            sf::Color opixel;
            preciserect r;

            image.data.Create(image.Src.w, image.Src.h);



            for(int x=0; x<radius*2; x++){
                for(int y=0; y<radius*2; y++){

                    if(sqrt((x-radius)*(x-radius)+(y-radius)*(y-radius))<radius){

                    double xt, yt;
                    xt = (2*x)/(((radius*2)-1))-1;
                    yt = (2*y)/(((radius*2)-1))-1;

                    distort_class(xt, yt, r);





                    double setx, sety;

                    setx= (r.x+1)*((radius*2)-1)/2.0;
                    sety=   (r.y+1)*((radius*2)-1)/2.0;

                    opixel=Get_pixel(newimage, setx, sety);

                    if(setx>0 && setx<radius*2 && sety<radius*2 && sety>=0){

                        Set_pixel(&image.data, x, y, opixel);

                    }


                }

                }

            }

            delete newimage;


        }

        void Planet::load(std::string pname,double pRadius, int px, int py, int pAtmosphereWidth, int pshinex, int pshiney, Limits pL1, Limits pL2, Limits pL3, DescA pAtmosphere, int minx, int maxx, int miny, int maxy, double **pdata, int pass) {

                //limit1=new Limits;
                //limit2=new Limits;
                //limit3=new Limits;
                //int ar=0;

                //describe();


                shiney=pshiney;
                shinex=pshinex;
                shinexm1=-1000;
                shineym1=-1234114;

                limit1=pL1;
                //std::cout <<limit1.limit;
                limit2=pL2;
                limit3=pL3;
                Atmosphere=pAtmosphere;

                radius=pRadius;
                smaxx=maxx;
                sminx=minx;
                smaxy=maxy;
                sminy=miny;
                name= pname;
                AtmosphereWidth=pAtmosphereWidth;

                if(pass==1){

                    for(int i=0; i<radius*2; i++){
                        for(int j=0; j<radius*2; j++){

                            data[i][j]=pdata[i][j];

                        }

                    }

                }



                if(pass!=1){
                //image. ///Was i going to do something here?
                int Octaves=5;


                data=PerlinNoise_Mem(xyoffset*xyoffsetmul, xyoffset*xyoffsetmul, radius*2 , radius*2 , Octaves, 2, 50);


                ///Parse data.
                parse_data(minx, maxx, miny, maxy);

                xyoffset++;
                image.create_surface(radius*2, radius*2);
                image.Transparency=1;

                generate_image();
                }




        }
        void Planet::add_permanent_effects(){




                circularise_image();


                if(Atmosphere.Haze==1){
                    add_scatter();
                }

                //add_shine(shinex, shiney, 1);  ///This no longer does a lot.


                if(Atmosphere.Atmosphere==1){
                add_hal_region();

                add_atmosphere(Atmosphere, Atmosphere.Atmosphere);  ///Implement specific colour

                }


                else{
                    add_atmosphere(Atmosphere, 0);  ///BLUR Nicely to background
                    //blur();
                }



        }

        void Planet::add_lighting(){




                    shinexm1=shinex;
                    shineym1=shiney;


                    if(Atmosphere.sun!=1){
                    add_shine(shinex, shiney, 2); //Does the grading.
                    }
                    else{
                        //add_shine(shinex, shiney, 2);
                        add_sun_shine(shinex, shiney);
                    }

                    if(Atmosphere.Atmosphere!=1){
                        add_blur();

                    }



        }

        Planet::Planet(){}

        Planet::Planet(std::string pname,double pRadius, int px, int py, int pAtmosphereWidth, int pshinex, int pshiney, Limits pL1, Limits pL2, Limits pL3, DescA pAtmosphere, int minx, int maxx, int miny, int maxy, double **pdata, int pass) {
                load(pname,pRadius, px, py, pAtmosphereWidth, pshinex, pshiney, pL1, pL2, pL3,pAtmosphere, minx, maxx, miny, maxy, pdata, pass);

        }


        void Planet::SetRXY(int a, int b){
            relative_x=a;
            relative_y=b;
        }


///Delete data

//#include "../Common/Common.hpp"

