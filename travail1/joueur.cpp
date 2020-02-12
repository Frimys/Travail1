#include "joueur.h"
Joueur::Joueur()
{
	nom = "";
	nombreVictoires = 0;
	nombreDefaites = 0;
	for (int i = 0; i < 26; i++)
	{
		mainDuJoueur[i] = NULL;
	}
}
void Joueur::SetNom(string aNom)
{
	nom = aNom;
}
void Joueur::AjouterVictoire()
{
	nombreVictoires++;
}
void Joueur::AjouterDefaite()
{
	nombreDefaites++;
}
void Joueur::AjouterUneCarte(Carte* aCartePigee)
{
	bool carteAjoutee = false;
	int nbCartes = 0;
		while (carteAjoutee = false && nbCartes < 26)
		{
		if (mainDuJoueur[nbCartes] == NULL)
			{
			mainDuJoueur[nbCartes] = aCartePigee;
			carteAjoutee = true;
			}
		else
		{
			nbCartes++;
		}
		}
}
void Joueur::EnleverLesCartes()
{
	for (int i = 0; i < 26; i++)
	{
		mainDuJoueur[i] = NULL;
	}
}