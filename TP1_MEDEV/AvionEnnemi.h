#pragma once
#include "avion.h"
#include "Carte.h"

class AvionEnnemi :public Avion
{
public:
	AvionEnnemi(int x, int y, int z, int xO, int yO, int zO) :Avion(x, y, z, xO, yO, zO) {};
	int getTeam() { return 2; };
	void decisionDeplacement(Carte* c, int[3]);
	void appliquerDeplacement(int[3]);
private:
};