
#include "Engine.hpp"


template<class T>
Engine<T>::Engine(int pScreenWidth, int pScreenHeight) : List(), screenwidth(pScreenWidth), screenheight(pScreenHeight), App(sf::VideoMode(pScreenWidth, pScreenHeight, 32), "This will only end badly")
{

        screenx=0;
        screeny=0;

}



template<class T>
void Engine<T>::remove_num(int Num)
{
        typename std::list<T>::iterator it;
        it=List.begin();
        std::advance(it, Num);
        List.erase(it);
        //List.
}


template<class T>
int Engine<T>::return_num()
{
        return List.size();
}

template<class T>
Engine<T>::~Engine()
{
}

template<class T>
void Engine<T>::draw_all(int prx, int pry)
{

        App.Clear();

        for(typename std::list<T>::iterator it=List.begin(); it!=List.end(); it++) {

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

template<class T>
void Engine<T>::flip()
{
        App.Display();
}

template<class T>
void Engine<T>::add_image_end(T t)
{
        List.push_back(t);
}

template<class T>
void Engine<T>::add_file_end(std::string Name,int x, int y,  int pTransparency)
{

        T Load;
        Load.Load(Name, x, y, pTransparency);
        List.push_back(Load);

}

template<class T>
void Engine<T>::remove_all()
{

        List.clear();

}

