/*
 * \file testTemps.cpp
 *
 * Contient un petit programme d'horloge destiné à tester la classe Temps.  Un nouveau temps s'afficher
 * à chaque seconde.  On peut régler le temps initial avec la ligne 23 en fournissant des paramètres à
 * l'initialisateur.  Par-défaut il débute avec l'heure système.
 *
 *  Created on: Oct 6, 2020
 *  \author: Pascal Charpentier
 */
#define TESTTEMPS

#ifdef TESTTEMPS

#include "Temps.h"

#include <iostream>
#include <unistd.h>

using namespace std;

int main()
{
	Temps maintenant;

	cout << maintenant << endl;
	while (1)
	{
		sleep(1);
		maintenant.tic();
		cout << maintenant << endl;
	}

	return 0;
}

#endif
