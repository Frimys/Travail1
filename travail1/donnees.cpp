#include "donnees.h"
Donnees::Donnees()
{
	string atout = "";
	for (int numeroAtout= 0; numeroAtout < 4; numeroAtout++)
	{
		switch (numeroAtout) 
		{
		case 0: atout = "pique"; break;
		case 1: atout = "coeur"; break;
		case 2: atout = "tr�fle"; break;
		case 3: atout = "carreau"; break;
			
			for (int valeur = 1; valeur <= 13; valeur++)
			{
				LesCartes[(valeur + (numeroAtout * 13))].InitialiserCarte(valeur, atout);
			}
		}
	}
}


