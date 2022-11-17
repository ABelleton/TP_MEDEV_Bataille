#pragma once
#include<vector>
#include<iostream>

#include"avion.h"
#include"AvionAllie.h"
#include"AvionEnnemi.h"

using namespace std;

class Carte {
private:
	vector<Avion*> avions;
	int tours;

public:
	Carte();
	void tour();
};