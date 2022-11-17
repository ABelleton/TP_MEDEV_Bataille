#include"Carte.h"


Carte::Carte() {
	carte = {};
	Avion* avion;
	avion = new AvionAllie(0, 5, 0, 1, 0, 0);
	carte.push_back(avion);
	avion = new AvionAllie(0, 8, 0, 1, 0, 0);
	carte.push_back(avion);
	avion = new AvionEnnemi(13, 5 ,13 , -1, 0, 0);
	carte.push_back(avion);
	avion = new AvionEnnemi(13, 8, 13, -1, 0, 0 );
	carte.push_back(avion);
	delete(avion);
}

void Carte::tour() {
	for (int i = 0; i < carte.size(); i++) {
		(carte[i])->deplacement;
	};
	for (int i = 0; i < carte.size(); i++) {
		(carte[i])->tir;
	}
	i = 0;
	while (i<carte.size()) {
		if (carte[i]->isDead) {
			carte.erase(i);
			i--;
		}
		i++
	}
	if (carte.size() == 1) {
		cout << "Fin de partie ! Victoire de l'équipe " <<  
	}
}