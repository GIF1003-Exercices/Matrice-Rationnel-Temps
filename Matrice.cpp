/*
 * tableau2d.cpp
 *
 *  Created on: Oct 6, 2020
 *      Author: etudiant
 */

#include <cassert>

#include "Matrice.h"

Matrice::Matrice()
{
	for (int i = 0; i < NRANGEES; ++i)
	{
		for (int j = 0; j < NCOLONNES; ++j)
		{
			if (i == j)
			{
			    element[i][j] = 1;
			}
			else
			{
				element[i][j] = 0;
			}
		}
	}
}

bool Matrice::indicesSontValides(const int i, const int j)
{
	return (i < NRANGEES and i >= 0 and j < NCOLONNES and j >= 0);
}


double& Matrice::operator()(const int rangee, const int colonne)
{
	// Précondition:

	assert(indicesSontValides(rangee, colonne));

	return element[rangee][colonne];
}

