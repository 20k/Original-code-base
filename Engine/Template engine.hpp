#ifndef ENGINE_HEADER
#define ENGINE_HEADER

#include <iostream>
#include <SFML/Graphics.hpp>
#include <list>
template <class T>
class Engine
{

public:

        signed long long int screenx;
        signed long long int screeny;
        sf::RenderWindow App;


        std::list <T> List;
        int screenwidth, screenheight;
        Engine(int pScreenWidth, int pScreenHeight);
        void remove_num(int Num);
        int return_num();
        void draw_all(int prx=0, int pry=0);
        void flip();
        void add_image_end(T t) ;
        void add_file_end(std::string Name,int x=0, int y=0,  int pTransparency=0) ;
        void remove_all();
        ~Engine();


};
#endif
