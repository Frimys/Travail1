#include <string>
#include "carte.h"
using namespace std;

#ifndef JoueurH
#define JoueurH

const int maxCartesAJouer = 26;
class Joueur
{
private:
	string nom;
	int nombreVictoires;
	int nombreDefaites;
	Carte* mainDuJoueur[26];

public:
	Joueur();
	void SetNom(string);
	void AjouterVictoire();
	void AjouterDefaite();
	void AjouterUneCarte(Carte*);
	void EnleverLesCartes();
};
#endif