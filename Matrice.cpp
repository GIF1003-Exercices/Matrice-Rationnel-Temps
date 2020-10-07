/*
 * \file tableau2d.cpp
 *
 *  Created on: Oct 6, 2020
 * \author: Pascal Charpentier
 */

#include <cassert>

#include "Matrice.h"

/**
 * Le constructeur par défaut:  installe 0 sur toutes les entrées et 1 sur les éléments diagonaux.
 *
 */

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

/**
 * Valide si une paire d'indice ne serait pas hors limite.
 *
 * \param[in] i la rangée
 * \param[in] j la colonne
 *
 * \return true si les deux indices sont dans les limites du tableau.
 */

bool Matrice::indicesSontValides(const int i, const int j)
{
	return (i < NRANGEES and i >= 0 and j < NCOLONNES and j >= 0);
}

/**
 * Star of the show!!!  L'opérateur () va remplacer les [][]
 *
 * \param[in] i la rangée
 * \param[in] j la colonne
 *
 * \return le membre element[rangée][colonne]
 */

const double& Matrice::operator()(const int rangee, const int colonne) const
{
	// Précondition:

	assert(indicesSontValides(rangee, colonne));

	return element[rangee][colonne];
}

