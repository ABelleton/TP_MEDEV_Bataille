#pragma once 
#include<iostream>
#include<vector>
using namespace std;

class Avion {
    private :
        int coordonees[3];
        int orientation[3];
        bool isDead;
        bool cooldown;
    public:
        int getX(){return coordonees[0];};
        int getY(){return coordonees[1];};
        int getZ(){return coordonees[2];};

        int getXO(){return orientation[0];};
        int getYO(){return orientation[1];};
        int getZO(){return orientation[2];};

        bool getIsDead(){};

};