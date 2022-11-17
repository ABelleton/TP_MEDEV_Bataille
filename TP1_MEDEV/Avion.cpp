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
        int posVerif=coordonees;
        while(posVerif[0]<14 && posVerif[1]<14 && posVerif[2]<14 && posVerif[0]>=0 && posVerif[1]>=0 && posVerif[2]>=0){
            posVerif+=orientation;
            vector<Avion*> avions = carte->getAvions ; 
            for(int i=0; i<avions.size(); i++){
                for (int j=0; j<4; j++){
              if ( avions[i]->coordonees == posVerif && this->getTeam() != avions[i]->getTeam()) {
                 avions[i]->setIsDead(true);
                 break;
              }
            }
            }
            
           
        }
    }

};