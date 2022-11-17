#include "avion.h"

Avion :: Avion(int x, int y, int z, int xo , int yo, int zo) {
   
    coordonees[0] = x;
    coordonees[1] = y;
    coordonees[2] = z;

    orientation[0] = xo;
    orientation[1] = yo;
    orientation[2] = zo;

    isDead = false;
    cooldown = false;

}


void Avion::tir (Carte carte){
    if(cooldown){
        cooldown = false;
    }
    else{
        
    }

};