#ifndef TORPEDO_GAMEMASTER_HPP_INCLUDED
#define TORPEDO_GAMEMASTER_HPP_INCLUDED
#include <iostream>
#include <vector>

using namespace std;

class Game_master
{
public:
    vector<vector<bool>> _kezdeti_1;
    vector<vector<bool>> _kezdeti_2;
    vector<vector<bool>> _lovesek_1;
    vector<vector<bool>> _lovesek_2;
    vector<vector<bool>> _jatek_menet_1;
    vector<vector<bool>> _jatek_menet_2;
    string _irany;
    int _hossz;
    Game_master();
};

#endif // TORPEDO_GAMEMASTER_HPP_INCLUDED
