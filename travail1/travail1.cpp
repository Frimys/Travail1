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

void InitialiserJoueurs();
void Jouer();


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
}

void Jouer() 
{

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
