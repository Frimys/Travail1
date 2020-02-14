#pragma once
#include "carte.h"
#include "joueur.h"

const int maxCartes = 52;

class Donnees
{
	public:
		Donnees();
		Carte LesCartes[maxCartes];
		Joueur Joueur1;
		Joueur Joueur2;
private:
	void InitialiserCartes();

};

