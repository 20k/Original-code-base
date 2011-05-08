#ifndef IMAGE_HEADER
#define IMAGE_HEADER
#include <SFML/Graphics.hpp>
#include "../Common/Common.hpp"

sf::Color inline Get_pixel ( sf::Sprite *image ,int64_t x ,int64_t y )
{
    return image->GetPixel(x, y);
}

sf::Color inline Get_pixel(sf::Image *image, int64_t x, int64_t y)
{

    return image->GetPixel(x, y);

}

void inline Set_pixel ( sf::Image *image ,int64_t x ,int64_t y , sf::Color colour )
{
        image->SetPixel(x, y, colour);
}




class Image
{
public:
        int Del;
        int r;

        sf::Image data;
        sf::Sprite image;
        preciserect Dest, Src;
        std::string Name;

        int Transparency;


        Image();
        Image(std::string pName,  int64_t x=0, int64_t y=0, int pTransparency=0);
        ~Image();


        int Load (std::string pName, int64_t x=0, int64_t y=0,  int pTransparency=0);

        void update_to_surface (int64_t x=0, int64_t y=0) ;

        void add_to_pixel (int64_t x, int64_t y, sf::Color Colourr);

        void create_surface (int64_t width, int64_t height);

        sf::Color get_pixel (int64_t x, int64_t y);

        void set_pixel (int64_t x, int64_t y, sf::Color Colour);


};
#endif
