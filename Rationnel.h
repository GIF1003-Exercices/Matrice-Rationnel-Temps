/*
 * Rationnel.h
 *
 *  Created on: Oct 6, 2020
 *      Author: etudiant
 */

#ifndef RATIONNEL_H_
#define RATIONNEL_H_

#include <iostream>
#include <string>

class Rationnel
{
private:
	long numerateur;
    long denominateur;

public:
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
