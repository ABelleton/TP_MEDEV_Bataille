#include "AvionAllie.h"

void AvionAllie::decisionDeplacement(Carte* carte, int o[3]) {
	int positionV[3];
	double distV = 10000.0;
	double distA = 0.0;
	for (int i = 0; i < 4; i++) {
		if (carte->getAvions()[i]->getTeam() != this->getTeam()) {
			distA = sqrt((this->getX() - carte->getAvions()[i]->getX()) ^ 2 + (this->getY() - carte->getAvions()[i]->getX()) ^ 2 + (this->getZ() - carte->getAvions()[i]->getX()) ^ 2);
			if (distA < distV) {
				positionV[0] = carte->getAvions()[i]->getX();
				positionV[1] = carte->getAvions()[i]->getY();
				positionV[2] = carte->getAvions()[i]->getZ();
				distV = distA;
			}
		}
	}
	o[0] = getXO();
	o[1] = getYO();
	o[2] = getZO();
	positionV -= {this->getX(), this->getY(), this->getZ()};
	bool at = false;
	if (!at && positionV[0] > 0 && o[0] <= 0) {
		o[0]++;
		at = true;
	}
	if (!at && positionV[0] == 0 && o[0] != 0) {
		o[0] = 0;
		at = true;
	}
	if (!at && positionV[0] < 0 && o[0] >= 0) {
		o[0]--;
		at = true;
	}
	if (!at && positionV[1] > 0 && o[1] <= 0) {
		o[1]++;
		at = true;
	}
	if (!at && positionV[1] == 0 && o[1] != 0) {
		o[1] = 0;
		at = true;
	}
	if (!at && positionV[1] < 0 && o[1] >= 0) {
		o[1]--;
		at = true;
	}
	if (!at && positionV[2] > 0 && o[2] <= 0) {
		o[2]++;
		at = true;
	}
	if (!at && positionV[2] == 0 && o[2] != 0) {
		o[2] = 0;
		at = true;
	}
	if (!at && positionV[2] < 0 && o[2] >= 0) {
		o[2]--;
		at = true;
	}

	for (int i = 0; i < carte->getAvions().size(); i++) {
		if (getTeam() != getAvions()[i].getTeam()) {
			if ((getXO() == getAvions()[i].getXO()) && (getYO() == getAvions()[i].getYO()) && (getZO() == getAvions()[i].getZO())) {
				o[0] = getXO();
				o[1] = getYO();
				if ((getZO() == 1) || (getZO() == -1)) {
					o[2] = 0;
					if ((getXO() == 1) || (getXO() == -1)) {
						o[0] = 0;
					}
					else { o[0] = 1; }
				}
				else { 
					if ((getXO() == 1) || (getXO() == -1)) {
						o[0] = 0;
					}
					else { o[0] = 1; }
					o[2] = 1; }
			}
			if ((getXO() == (-1) * getAvions()[i].getXO()) && (getYO() == (-1)*getAvions()[i].getYO()) && (getZO() == (-1) * getAvions()[i].getZO())) {
				o[0] = getXO();
				o[1] = getYO();
				if ((getZO() == 1) || (getZO() == -1)) {
					o[2] = 0;
					if ((getXO() == 1) || (getXO() == -1)) {
						o[0] = 0;
					}
					else { o[0] = 1; }
				}
				else {
					if ((getXO() == 1) || (getXO() == -1)) {
						o[0] = 0;
					}
					else { o[0] = 1; }
					o[2] = 1;
				}
			}
		}
	}

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


}

void AvionAllie::appliquerDeplacement(int o[3]) {
	setXO(o[0]);
	setYO(o[1]);
	setZO(o[2]);
	setX(getX() + o[0]);
	setX(getY() + o[1]);
	setX(getZ() + o[2]);
}


