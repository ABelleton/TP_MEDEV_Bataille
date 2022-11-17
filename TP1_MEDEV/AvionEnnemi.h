#pragma once
#include "avion.h"
#include "Carte.h"

class AvionEnnemi :Avion
{
public:
	AvionEnnemi(int x, int y, int z, int xO, int yO, int zO) :Avion(x, y, z, xO, yO, zo) {};
	int getTeam() { return 2; };
	void decisionDeplacement(const Carte& c, int[3]);
	void appliquerDeplacement(int[3]);
private:
};