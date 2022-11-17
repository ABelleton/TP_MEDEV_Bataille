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
	delete avion;
}

void Carte::tour() {
	for (int i = 0; i < avions.size(); i++) {
		(avions[i])->deplacement;
	};
	for (int i = 0; i < avions.size(); i++) {
		(avions[i])->tir;
	}
	int i = 0;
	while (i<(avions.size())) {
		if (avions[i]->isDead) {
			avions.erase(i);
			i--;
		}
		i++;
	}
	if (avions.size() == 1) {
		cout << "Fin de partie !";
	}
	else {
		bool fin = true;
		for (int i = 1; i < avions.size(); i++) {
			if (avions[i]->getTeam == avions[0].getTeam) {
				fin = false;
				cout << "Fin de partie !";
			}
		}
		if (!fin) {
			tours++;
			avions.tour();
		}
	}

}