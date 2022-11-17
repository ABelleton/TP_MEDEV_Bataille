#pragma once

#include "avion.h"
#include "Carte.h"

class AvionAllie : public Avion {
public:
	AvionAllie(int a, int b, int c, int d, int e, int f) :Avion(a, b, c, d, e, f) {}
	int getTeam() { return 1; }
	void decisionDeplacement(Carte carte) {}
};