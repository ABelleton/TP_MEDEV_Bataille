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
        bool out = true;//verificateur de sortie de boucle
        int* posVerif=coordonees;//Le vecteur position qui parcourt la ligne de visée
        while(posVerif[0]<14 && posVerif[1]<14 && posVerif[2]<14 && posVerif[0]>=0 && posVerif[1]>=0 && posVerif[2]>=0 && out){//On parcourt la ligne de visée
            posVerif[0]+=orientation[0];
            posVerif[1]+=orientation[1];
            posVerif[2]+=orientation[2];
            vector<Avion*> avions = carte.getAvions() ; 
            for(int i=0; i<avions.size(); i++){//Pour chaque avion, on vérifie s'il est à la position qu'on est en train de vérifier
                if(orientation[1] == 0 ){
                        if (orientation[0] ==1 && orientation[1] == 0 && orientation[2] ==0  ){
                            if ( (avions[i]->coordonees == posVerif||(avions[i]->coordonees[1]==posVerif[1]+1&&avions[i]->coordonees[2]==posVerif[2])||(avions[i]->coordonees[1]==posVerif[1]&&avions[i]->coordonees[2]==posVerif[2]+1)||(avions[i]->coordonees[1]==posVerif[1]-1&&avions[i]->coordonees[2]==posVerif[2])||(avions[i]->coordonees[1]==posVerif[1]&&avions[i]->coordonees[2]==posVerif[2]-1)) && this->getTeam() != avions[i]->getTeam()) {//On vérifie chaque position autour de posVerif, cela permet le canon large
                                avions[i]->setIsDead(true);
                                out = false;
                                break;
                 
              }
                        }
                }
            
                for (int j=0; j<4; j++){
              if ( avions[i]->coordonees == posVerif && this->getTeam() != avions[i]->getTeam()) {
                avions[i]->setIsDead(true);
                out = false;
                break;
              }
            }
            }
            
           
        }
    }

};