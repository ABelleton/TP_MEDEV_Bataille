#pragma once
#include "avion.h"
class carte

class AvionEnnemi :Avion
{
public:
	AvionEnnemi(int x, int y, int z, int xO, int yO, int zO) :Avion(x, y, z, xO, yO, zo){];
	int getTeam() { return 2 };
	void deplacement(carte);
private:
};