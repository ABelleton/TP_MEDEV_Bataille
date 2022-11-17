#include "AvionEnnemi.h" 

void AvionEnnemi::decisionDeplacement(const Carte& c, int[3] o){
	int[3] positionV;
	double distV=10000.0;
	double distA = 0.0;
	for (int i = 0; i < 4; i++) {
		if (c.avions[i]->getTeam() != this->getTeam()) {
			distA = sqrt((this->getX() - c.avions[i]->getX()) ^ 2 + (this->getY() - c.avions[i]->getX()) ^ 2 + (this->getZ() - c.avions[i]->getX()) ^ 2);
			if (distA < distV) {
				positionV[0] = c.avions[i]->getX();
				positionV[1] = c.avions[i]->getY();
				positionV[2] = c.avions[i]->getZ();
				distV = distA;
			}
		}
	}
	o= { this->getXO(), this->getYO(), this->getZO() };
	positionV -= {this->getX(), this->getY(), this->getZ()};
	bool at = false;
	if (!at && positionV[0] > 0 && o[0] <= 0) {
		o[0]++;
		at = true;
	}
	if (!at && positionV[0] == 0 && o[0] != 0) {
		o[0]=0;
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
}

void AvionEnnemi::appliquerDeplacement(int[3] o) {
	orientation = o;
	coordonees += o;
	for (int i = o; i < 3; i++) {
		if (coordonees[i] > 13) {
			coordonees[i] = 0;
		}
		if (coordonees[i] < 0) {
			coordonees[i] = 13;
		}
	}
}
