#include "donnees.h"
#include "..\screen\screen.h"
#include <conio.h>
#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

Donnees leJeu;
Joueur lesJoueurs[2];
int AfficherResultatJoueur(Joueur);
void MelangerLesCartes();
void DistribueLesCartes(int anbCartesJoueurs);
void InitialiserJoueurs();
void Jouer();
void quiAGagner(int, int);
void ResultatsFinals();


int main() 
{
	char fini = 'n';
	srand((unsigned)time(NULL));
	InitialiserJoueurs();
	while (fini=='n' || fini=='N')
	{
		Jouer();
		cout << "\nTermine (n/o) ? ";
		cin >> fini;		
	}
	ResultatsFinals();
}

void Jouer() 
{
	int nbCartesJoueurs = 0;
	bool BoolCarte = false;


	while(BoolCarte == false)
	{
		cout << "Combien de cartes par joueurs? (Max 26)\n";
		cin >> nbCartesJoueurs;
		if (nbCartesJoueurs > maxCartesAJouer)
		{
			cout << "Le Nombre de cartes choisi doit être inferieur ou égale à 26";
		}
		else
		{
			BoolCarte = true;
		}
	}
	MelangerLesCartes();
	DistribueLesCartes(nbCartesJoueurs);
	int resultatJoueur1 = AfficherResultatJoueur(leJeu.Joueur1);
	int resultatJoueur2 = AfficherResultatJoueur(leJeu.Joueur2);
	quiAGagner(resultatJoueur1, resultatJoueur2);

}

void InitialiserJoueurs()
{
	string nomJoueur;
	cout << "\n Nom du premier joueur? \n";
	cin >> nomJoueur;
	lesJoueurs[0].SetNom(nomJoueur);
	cout << "\n Nom du deuxième joueur? \n";
	cin >> nomJoueur;
	lesJoueurs[1].SetNom(nomJoueur);
}

void MelangerLesCartes()
{
	int carte1, carte2;
	Carte carteTemp;
	int brasser;
	for (brasser = 0; brasser <= 500; brasser++)
	{
		carte1 = (rand() % maxCartes);
		carte2 = (rand() % maxCartes);
		carteTemp = leJeu.LesCartes[carte1];
		leJeu.LesCartes[carte1] = leJeu.LesCartes[carte2];
		leJeu.LesCartes[carte2] = carteTemp;
	}
}
void DistribueLesCartes(int anbCartesJoueur)
{
	int joueur = 1;
	anbCartesJoueur = anbCartesJoueur * 2;
	for (int i = 0; i < anbCartesJoueur; i++)
	{
		if (joueur == 1)
		{
			leJeu.Joueur1.AjouterUneCarte(&leJeu.LesCartes[i]);
			joueur = 2;
		}
		else
		{
			leJeu.Joueur2.AjouterUneCarte(&leJeu.LesCartes[i]);
			joueur = 1;
		}
	}
	
}
int AfficherResultatJoueur(Joueur aJoueur)
{
	int totalDesCartes = 0;
	int indiceTableau = 0;
	cout << aJoueur.getNomJoueur() << "\n";
	while (indiceTableau < 26 && aJoueur.GetCarteJoueurTableau(indiceTableau) != NULL)
	{
		cout << aJoueur.GetCarteJoueurTableau(indiceTableau)->GetValeur() << ", " << aJoueur.GetCarteJoueurTableau(indiceTableau)->GetAtout() << "\n";
		totalDesCartes = totalDesCartes + aJoueur.GetCarteJoueurTableau(indiceTableau)->GetValeur();
		indiceTableau++;
	}
	cout << "Le total du joueur " << aJoueur.getNomJoueur() << " est de " << totalDesCartes << ". \n";
	return totalDesCartes;
}
void quiAGagner(int aresultatJoueur1, int aresultatJoueur2)
{
	if (aresultatJoueur1 == aresultatJoueur2)
	{
		/* cas égalité*/
		cout << "C'ette partie est nulle! \n";
	}
	if (aresultatJoueur1 < aresultatJoueur2)
	{
		/* joueur 2 gagne*/
		cout << "Bravo au joueur " << leJeu.Joueur2.getNomJoueur() << "! \n";
		leJeu.Joueur2.AjouterVictoire();
		leJeu.Joueur1.AjouterDefaite();
	}
	else
	{
		/* joueur 1 gagne*/
		cout << "Bravo au joueur " << leJeu.Joueur2.getNomJoueur() << "! \n";
		leJeu.Joueur1.AjouterVictoire();
		leJeu.Joueur2.AjouterDefaite();

	}
	leJeu.Joueur1.EnleverLesCartes();
	leJeu.Joueur2.EnleverLesCartes();
}
void ResultatsFinals()
{
	cout << "Joueur 1: " << leJeu.Joueur1.getNomJoueur() << ": " << leJeu.Joueur1.getNombreVictoires() << " victoires et " << leJeu.Joueur1.getNombreDefaites() << " defaites. \n";
	cout << "Joueur 2: " << leJeu.Joueur2.getNomJoueur() << ": " << leJeu.Joueur2.getNombreVictoires() << " victoires et " << leJeu.Joueur2.getNombreDefaites() << " defaites. \n";
	if (leJeu.Joueur1.getNombreVictoires() == leJeu.Joueur2.getNombreVictoires())
	{
		cout << "La partie est nulle! \n";

	}
	else if (leJeu.Joueur1.getNombreVictoires() < leJeu.Joueur2.getNombreVictoires())
	{
		cout << leJeu.Joueur2.getNomJoueur() << " gagne la partie! \n";
	}
	else
	{
		cout << leJeu.Joueur1.getNomJoueur() << " gagne la partie! \n";
	}
}