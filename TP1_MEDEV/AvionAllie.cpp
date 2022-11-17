#include "AvionAllie.h"

void AvionAllie::decisionDeplacement(Carte carte,int[3] &o) {

	//Strategie anti murs
	if ((getX() == 12) && (getXO() == 1) && (getYO() == 0) && (getZO() == 0)) {
		o[0] = 1;
		o[1] = 1;
		o[2] = 0;
	}
	if ((getY() == 12) && (getXO() == 0) && (getYO() == 1) && (getZO() == 0)) {
		o[0] = 1;
		o[1] = 1;
		o[2] = 0;
	}
	if ((getZ() == 12) && (getXO() == 0) && (getYO() == 0) && (getZO() == 1)) {
		o[0] = 0;
		o[1] = 1;
		o[2] = 1;
	}
	if ((getX() == 13) && (getXO() == 1) && (getYO() == 1) && (getZO() == 0)) {
		o[0] = 0;
		o[1] = 1;
		o[2] = 0;
	}
	if ((getY() == 13) && (getXO() == 1) && (getYO() == 1) && (getZO() == 0)) {
		o[0] = 1;
		o[1] = 0;
		o[2] = 0;
	}
	if ((getZ() == 13) && (getXO() == 0) && (getYO() == 1) && (getZO() == 1)) {
		o[0] = 0;
		o[1] = 1;
		o[2] = 0;
	}

	//pas proche d'un mur avec orientation critique
	for (int i = 0; i < carte.size(); i++) {




	}


}

