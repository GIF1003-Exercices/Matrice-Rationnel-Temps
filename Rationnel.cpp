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

/**
 * Ordonne deux entiers.  S'ils sont égaux ou déjà en ordre: ne change rien.
 * Donc à la sortie a > b
 *
 * \param[in] a un entier
 * \param[in] b un autre entier
 *
 */

void Rationnel::ordonner(long& a, long& b)
{
	if (b > a)
	{
		long temp = a;
		a = b;
		b = temp;
	}
}

/**
 * Trouve le plus grand diviseur commun de a et b avec l'algorithme d'Euclide.
 * Retourne toujours une valeur positive, donc on aura le même résultat, soit +6
 * pour les combinaisons d'arguments suivants: (42, 66) (-42, 66) (42, -66) (-42, -66).
 *
 * \param[in] a un entier
 * \param[in] b un autre entier
 *
 * \return un entier, le plus grand commun diviseur de a et b, en valeur absolue.
 *
 * \precondition a et b ne peuvent être simultanément 0
 *
 * \postcondition ne peut retourner 0
 *
 * \exception une assertion si a et b sont simultanément nuls.
 */

long Rationnel::pgdc(long a, long b)
{
	// Précondition

	assert( (a != 0) or (b != 0) );

	// Cas pathologiques: nombres égaux ou nuls

	if (b == 0) return std::abs(a);
	if ((a == 0) or (a == b)) return std::abs(b);

	// On ne s'occupe que des nombres positifs

    a = std::abs(a);
    b = std::abs(b);
    Rationnel::ordonner(a, b);

    // Algorithme d'Euclide

    long rem = a % b;
    while (rem)
    {
    	a = b;
    	b = rem;
    	rem = a % b;
    }

    // Postcondition

    assert(b != 0);
    return b;
}

/**
 * Constructeur membre à membre
 * Initialise le nombre rationnel à-partir de deux entier: numérateur et dénominateur
 *
 * \param[in] num le numérateur
 * \param[in] denom le dénominateur
 *
 * \precondition denom > 0
 * \exception assertion si le dénominateur est nul ou le nombre résultant n'est pas irréductible
 * \postcondition un rationnel doit être irréductible, le pgdc du numérateur et dénominateur doit être 1.
 */

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

/**
 * Constructeur à partir d'un entier
 * Crée le nombre num/1
 * Vu que le dénominateur est automatiquement 1, la pré et postcondition sont
 * automatiquement satisfaites.
 *
 * \param[in] num le numérateur
 *
 */

Rationnel::Rationnel(long num) : numerateur(num), denominateur(1) {};

/**
 * Opérateurs arithmétiques
 */

/**
 * + unaire
 *
 * \param l'objet rationnel
 * \return le même objet inchangé
 */

Rationnel& Rationnel::operator+ ()
{
	return *this;
}

/**
 * - unaire
 *
 * \param objet rationnel
 * \return le complément de l'objet (objet + (-objet)) == 0
 */

Rationnel  Rationnel::operator- ()
{
	return Rationnel(-numerateur, denominateur);
}

/**
 * + binaire : Addition arithmétique de deux rationnels
 */
Rationnel  Rationnel::operator+ (const Rationnel& r) const
{
	return Rationnel(numerateur * r.denominateur + r.numerateur * denominateur, r.denominateur * denominateur);
}

/**
 * - binaire : Soustraction arithmétique de deux rationnels
 */
Rationnel  Rationnel::operator- (const Rationnel& r) const
{
	return Rationnel(numerateur * r.denominateur - r.numerateur * denominateur, r.denominateur * denominateur);
}

/**
 * * binaire : multiplication arithmétique de deux rationnels
 */
Rationnel  Rationnel::operator* (const Rationnel& r)
{
	return Rationnel(r.numerateur * numerateur, r.denominateur * denominateur);
}

/**
 *  division arithmétique de deux rationnels.  Le diviseur ne peut être nul!
 *
 *  \precondition Diviseur non-nul
 *  \exception assertion si diviseur == 0
 */
Rationnel  Rationnel::operator/ (const Rationnel& r)
{
	assert(r.numerateur != 0);
	return Rationnel(numerateur * r.denominateur, denominateur * r.numerateur);
}

/**
 * Opérateurs relationnels
 */

/**
 * Égalité: si les numérateurs et dénominateurs sont égaux.  Dans notre cas ceci n'est pas ambigu car
 * le rationnel est toujours irréductible.
 *
 */
bool  Rationnel::operator== (const Rationnel& r) const
{
	return r.numerateur == numerateur and r.denominateur == denominateur;
}

/**
 * Inégalité retourne not ==
 */
bool Rationnel::operator!= (const Rationnel& r) const
{
	return !(r == (*this));
}

/**
 * Méthodes et opérateurs d'IO
 */

/**
 * Retourne une représentation textuelle du Rationnel
 */

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

/**
 * Opérateur de redirection dans un flux
 *
 * Affiche l'heure sous forme formattée avec 24h par défaut
 *
 * \param[in] os stream de sortie dans lequel insérer l'heure
 * \param[in] r objet Temps à insérer.
 *
 * \return le stream de sortie
 */

std::ostream& operator<< (std::ostream& os, const Rationnel& r)
{
	os << r.formatter();
	return os;
}








