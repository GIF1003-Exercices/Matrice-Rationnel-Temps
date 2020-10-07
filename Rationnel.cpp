/*
 * Rationnel.cpp
 *
 *  Created on: Oct 6, 2020
 *      Author: etudiant
 */
#include "Rationnel.h"
#include <cmath>
#include <cassert>
#include <iostream>
#include <string>

long Rationnel::pgdc(long a, long b)
{
	// On ne s'occupe que des nombres positifs

    a = std::abs(a);
    b = std::abs(b);

    // Cas pathologiques: nombres égaux ou nuls

    assert( (a != 0) or (b != 0));
    if ((b == 0) or (a == b)) return a;
    if (a == 0) return b;

    // Ordonner les deux nombres
    if (b > a)
    {
    	long temp = a;
    	a = b;
    	b = temp;
    }

    // Algorithme d'Euclide

    long rem = a % b;
    while (rem)
    {
    	a = b;
    	b = rem;
    	rem = a % b;
    }
    return b;
}

Rationnel::Rationnel(long num, long denom) : numerateur(num), denominateur(denom)
{
	// Précondition: dénominateur non-nul et positif

	assert(denom > 0);

	// La fraction est rendue irréductible à l'aide du PGDC

	long reducteur = pgdc(numerateur, denominateur);
	if (reducteur != 1)
	{
		numerateur /= reducteur;
		denominateur /= reducteur;
	}

	// Post condition: nombre rationnel irréductible

	assert(pgdc(numerateur, denominateur) == 1);
}

Rationnel::Rationnel(long num) : numerateur(num), denominateur(1) {};

Rationnel& Rationnel::operator+ ()
{
	return *this;
}

Rationnel  Rationnel::operator- ()
{
	return Rationnel(-numerateur, denominateur);
}

Rationnel  Rationnel::operator+ (const Rationnel& r) const
{
	return Rationnel(numerateur * r.denominateur + r.numerateur * denominateur, r.denominateur * denominateur);
}

Rationnel  Rationnel::operator- (const Rationnel& r) const
{
	return Rationnel(numerateur * r.denominateur - r.numerateur * denominateur, r.denominateur * denominateur);
}

Rationnel  Rationnel::operator* (const Rationnel& r)
{
	return Rationnel(r.numerateur * numerateur, r.denominateur * denominateur);
}

Rationnel  Rationnel::operator/ (const Rationnel& r)
{
	assert(r.numerateur != 0);
	return Rationnel(numerateur * r.denominateur, denominateur * r.numerateur);
}

bool  Rationnel::operator== (const Rationnel& r) const
{
	return r.numerateur == numerateur and r.denominateur == denominateur;
}

bool Rationnel::operator!= (const Rationnel& r) const
{
	return !(r == (*this));
}

std::string Rationnel::formatter() const
{
	std::string affichage;
	const std::string separateur = "/";

	if ((numerateur == 0) or (denominateur == 1))
	{
		affichage = std::to_string(numerateur);
	}
	else
	{
		affichage = std::to_string(numerateur) + separateur + std::to_string(denominateur);
	}

	return affichage;
}

std::ostream& operator<< (std::ostream& os, const Rationnel& r)
{
	os << r.formatter();
	return os;
}








