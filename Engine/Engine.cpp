
#include "Engine.hpp"



Engine::Engine(int pScreenWidth, int pScreenHeight) : List(), screenwidth(pScreenWidth), screenheight(pScreenHeight), App(sf::VideoMode(pScreenWidth, pScreenHeight, 32), "This will only end badly")
{

        screenx=0;
        screeny=0;

}




void Engine::remove_num(int Num)
{
        typename std::list<Pass>::iterator it;
        it=List.begin();
        std::advance(it, Num);
        List.erase(it);
        //List.
}



int Engine::return_num()
{
        return List.size();
}

Engine::~Engine()
{
}


void Engine::draw_all(int prx, int pry)
{

        App.Clear();

        for(typename std::list<Pass>::iterator it=List.begin(); it!=List.end(); it++) {

                sf::Sprite *Draw=(*it).Sprite;

                int B = (screenwidth>screenheight) ? screenwidth : screenheight;


                signed long long int x, y;

                x=(*it).Dest.x;
                y=(*it).Dest.y;

                if((*it).r!=1) {
                        x-=prx;
                        y-=pry;
                }


                if(Draw==NULL) {
                        exit(12345);
                }

                if(abs(x)<(pow((long double)2, (long double)16)-1) && abs(y)<(pow((long double)2, (long double)16)-1)) {


                        Draw->SetX((float)x);
                        Draw->SetY((float)y);

                        App.Draw(*Draw);


                }


        }

}


void Engine::flip()
{
        App.Display();
}


void Engine::add_image_end(Pass t)
{
        List.push_back(t);
}


/*void Engine::add_file_end(std::string Name,int x, int y,  int pTransparency)
{

        Pass Load;
        Load.Load(Name, x, y, pTransparency);
        List.push_back(Load);

}*/


void Engine::remove_all()
{

        List.clear();

}

