/**
 * \file Matrice.h
 *
 * Déclaration d'une classe de tableaux bidimensionnels avec surcharge de l'opérateur ().
 *
 *  Created on: Oct 6, 2020
 *  \Author: Pascal Charpentier
 */

#ifndef MATRICE_H_
#define MATRICE_H_

const int NRANGEES = 4;
const int NCOLONNES = 5;

/**
 * \class Matrice
 * \brief Tableaux bidimensionnels de valeurs réelles.  Les rangées et colonnes sontdéterminées par les
 * constantes NRANGEES et NCOLONNES
 *
 */

class Matrice
{
private:
	double element[NRANGEES][NCOLONNES];

public:
	Matrice();
	static bool indicesSontValides(const int i, const int j);
	const double& operator()(const int rangee, const int col) const ;

};



#endif /* MATRICE_H_ */
