#pragma once
#include<vector>
#include<iostream>

#include"Avion.h"
#include"AvionAllie.h"
#include"AvionEnnemi.h"

using namespace std;

class Carte {
	vector<Avion*> avions;
	int tour;
public:
	Carte();
	void tour();

}