/*
 * testMatrice.cpp
 *
 *  Created on: Oct 6, 2020
 *      Author: etudiant
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
    		cout << setw(5) << matrice(i, j);
    	}
    	cout << endl;
    }
	return 0;
}

#endif



