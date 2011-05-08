


#include "Image.hpp"
#include "../Common/Common.hpp"

        Image::Image() {

                Transparency=0;
                Dest.x=0;
                Dest.y=0;
                Dest.h=0;
                Dest.w=0;
                Src.x=0, Src.y=0, Src.h=0, Src.w=0;

        }

        Image::Image(std::string pName,  int64_t x, int64_t y, int pTransparency) {

                Load(pName, x, y, pTransparency);


        }

        int Image::Load(std::string pName, int64_t x, int64_t y,  int pTransparency) { ///This is the default co-ordinates, not the coords to load from


                r=0; ///Draw in same place regardless of camera
                Name=pName;
                Del=0;
                Transparency=pTransparency; ///Doesnt really do a lot


                Dest.x=x;
                Dest.y=y;


                data.LoadFromFile(Name);

                image.SetImage(data);
                Dest.h=data.GetHeight();
                Dest.w=data.GetWidth();

                //Src=Dest;
                Src.x=0;
                Src.y=0;
                Src.w=data.GetWidth();
                Src.h=data.GetHeight();
                return 0;

        }

        Image::~Image() {
        }

        void Image::update_to_surface(int64_t x, int64_t y) {

                Dest.x=x;
                Dest.y=y;

                Dest.h=data.GetHeight();
                Dest.w=data.GetWidth();

                Src.x=0;
                Src.y=0;
                Src.w=data.GetWidth();
                Src.h=data.GetHeight();

                image.SetImage(data);


        }

        void Image::add_to_pixel(int64_t x, int64_t y, sf::Color Colourr){

        sf::Color Col=Get_pixel(&data,  x,  y);


        if(Colourr.r+Col.r<=255 && Colourr.r+Col.r>=0){

            Col.r+=Colourr.r;

        }
        else if(Colourr.r+Col.r<0){
            Col.r=0;
        }
        else{
            Col.r=255;
        }
        if(Colourr.g+Col.g<=255&& Colourr.g+Col.g>=0){

            Col.g+=Colourr.g;


        }
        else if(Colourr.g+Col.g<0){
            Col.g=0;

        }
        else{
            Col.g=255;
        }
        if(Colourr.b+Col.b<=255&& Colourr.b+Col.b>=0){

            Col.b+=Colourr.b;

        }
        else if(Colourr.b+Col.b<0){
            Col.b=0;

        }
        else{
            Col.b=255;
        }
        ///Out of bounds checks

        Set_pixel(&data, x, y, Col);

        }



        void Image::create_surface(int64_t width, int64_t height) {

                data.Create(width, height);
                update_to_surface();
        }




        sf::Color Image::get_pixel(int64_t x, int64_t y){

            return Get_pixel(&data, x, y);

        }

        void Image::set_pixel(int64_t x, int64_t y, sf::Color Colour){
            Set_pixel(&data, x, y, Colour);
        }



