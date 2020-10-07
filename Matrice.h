/*
 * Matrice.h
 *
 *  Created on: Oct 6, 2020
 *      Author: etudiant
 */

#ifndef MATRICE_H_
#define MATRICE_H_

const int NRANGEES = 4;
const int NCOLONNES = 5;

class Matrice
{
private:
	double element[NRANGEES][NCOLONNES];

public:
	Matrice();
	static bool indicesSontValides(const int i, const int j);
	double& operator()(const int rangee, const int col);

};



#endif /* MATRICE_H_ */
