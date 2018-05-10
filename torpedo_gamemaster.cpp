#include "torpedo_gamemaster.hpp"

using namespace std;

const int vektor_size = 8;

Game_master::Game_master()
{
    for(int i=0; i<vektor_size; i++){
        vector<bool> v;
        for(int j=0; j<vektor_size; j++){
            v.push_back(false);
        }
        _kezdeti_1.push_back(v);
    }
    _kezdeti_2 = _kezdeti_1;
    _lovesek_1 = _kezdeti_1;
    _lovesek_2 = _kezdeti_1;
    _jatek_menet_1 = _kezdeti_1;
    _jatek_menet_2 = _kezdeti_1;
    _irany = "";
    _hossz = 0;
}
