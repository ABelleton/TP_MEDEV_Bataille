#pragma once 
#include<iostream>
#include<vector>
#include"Carte.h"
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

        bool getIsDead(){return isDead;};
        bool getCD(){return cooldown;};
        
        
        void setX(int a ){coordonees[0] = a;};
        void setY(int a ){coordonees[1] = a;};
        void setZ(int a ){coordonees[2] = a;};

        void setXO(int a ){orientation[0] = a;};
        void setYO(int a ){orientation[1] = a;};
        void setZO(int a ){orientation[2] = a;};

        void setIsDead(bool isd){isDead = isd;};

        void setCD(bool cool){cooldown = cool;};
        
        //Constructeurs

        Avion(int x, int y, int z, int xo , int yo, int zo);

        //Methodes 
        void tir (Carte carte);
        virtual void decisionDeplacement(Carte c, int ref[3]) = 0;
        virtual void appliqueDeplacement(int i[3]) = 0;
        virtual int getTeam() = 0;




};