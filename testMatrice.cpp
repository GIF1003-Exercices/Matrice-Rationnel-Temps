/**
 * \file testMatrice.cpp
 *
 * Contient un petit programme principal destiné à démontrer la surcharge de l'opérateur () dans la classe Matrice
 *
 * Created on: Oct 6, 2020
 * \author: Pascal Charpentier
 */

//#define TESTMATRICE
#ifdef TESTMATRICE

#include "Matrice.h"
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    Matrice matrice; // Matrice unité par défaut

    for (int i = 0; i < NRANGEES; ++i)
    {
    	for (int j = 0; j < NCOLONNES; ++j)
    	{
    		cout << setw(5) << matrice(i, j); // VoilÀ: on accède aux éléments avec () au lieu de [][]!
    	}
    	cout << endl;
    }
	return 0;
}

#endif



