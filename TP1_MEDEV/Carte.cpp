#include"Carte.h"


Carte::Carte() {
	avions = {};
	Avion* avion;
	avion = new AvionAllie(0, 5, 0, 1, 0, 0);
	avions.push_back(avion);
	avion = new AvionAllie(0, 8, 0, 1, 0, 0);
	avions.push_back(avion);
	avion = new AvionEnnemi(13, 5 ,13 , -1, 0, 0);
	avions.push_back(avion);
	avion = new AvionEnnemi(13, 8, 13, -1, 0, 0 );
	avions.push_back(avion);
	delete avion;
}

void Carte::tour() {

	// Choix des déplacements
	for (int i = 0; i < avions.size(); i++) {
		(avions[i])->decisionDeplacement(avions);
	};

	// Application des déplacements
	for (int i = 0; i < avions.size(); i++) {
		(avions[i])->applicationDeplacement(avions);
	};

	// Tirs
	for (int i = 0; i < avions.size(); i++) {
		(avions[i])->tir(avions);
	}

	// Détection des collisions
	int i = 0;
	while (i < avions.size()) {
		j = i + 1;
		while (j < avions.size()) {
			if ((avions[i]->getX() == avions[j]->getX()) && (avions[i]->getY() == avions[j]->getY()) && (avions[i]->getZ() == avions[j]->getZ())) {
				avions.erase(int(i));
				avions.erase(j - 1);
				i = i - 2;
				j = j - 2;
			}
			j++;
		}
		i++;
	}
	// Suppression des morts ce tour
	int i = 0;
	while (i<(avions.size())) {
		if (avions[i]->getIsDead()) {
			avions.erase(i);
			i--;
		}
		i++;
	}

	// Gestion de la fin de partie ou du nouveau tour
	if (avions.size() == 1) {
		cout << "Fin de partie ! Victoire de l'équipe " << (avions[0])->getTeam();;
	}
	else {
		bool fin = true;
		for (int i = 1; i < avions.size(); i++) {
			if ((avions[i])->getTeam() == (avions[0])->getTeam()) {
				fin = false;
				cout << "Fin de partie ! Victoire de l'équipe " << (avions[0])->getTeam();;
			}
		}
		if (!fin) {
			tours++;
			jouer();
		}
	}

}