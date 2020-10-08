/*
 * \file Rationnel.h
 * Contient la classe Rationnel
 *
 *  Created on: Oct 6, 2020
 * \author: Pascal Charpentier
 */

#ifndef RATIONNEL_H_
#define RATIONNEL_H_

#include <iostream>
#include <string>

/**
 * \class Rationnel
 * Classe représentant les nombres rationnels comme une division de deux entiers.  Lorsqu'un objet est construit
 * il est immédiatement transformé à sa forme irréductible.  Donc, par exemple: 5/10 -> 1/2, ou 3/3 -> 1/1.
 * Par convention seul le numérateur peut être négatif, et le dénominateur ne peut jamais être nul.
 */

class Rationnel
{
private:
	long numerateur;
    long denominateur;

public:
    static void ordonner(long& a, long& b);
	static long pgdc(long, long);

	bool estValide() const ;

	Rationnel(long, long);
	Rationnel(long);

	Rationnel& operator+();
	Rationnel operator-();
	Rationnel operator+(const Rationnel& r) const ;
	Rationnel operator-(const Rationnel& r) const ;
	Rationnel operator*(const Rationnel& r);
	Rationnel operator/(const Rationnel& r);
	Rationnel operator++();

	bool operator==(const Rationnel& r) const ;
	bool operator!=(const Rationnel& r) const ;

	std::string formatter() const ;
	friend std::ostream& operator << (std::ostream&, const Rationnel&);

};




#endif /* RATIONNEL_H_ */
