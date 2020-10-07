/*
 * testRationnel.cpp
 *
 *  Created on: 2020-10-06
 *      Author: etudiant
 */
//#define TESTRATIONNEL
#ifdef TESTRATIONNEL

#include "Rationnel.h"
#include <iostream>

using namespace std;

int main()
{
	Rationnel n(1);
	Rationnel m(2);
	Rationnel p = n + m;
	Rationnel q = p + 1;

	Rationnel x(1,2);
	Rationnel y(128, 24);


	std::cout << n << std::endl;
	std::cout << m << std::endl;
	std::cout << p << std::endl;
	std::cout << q << std::endl;

	std::cout << x << std::endl;

	std::cout << x + n << std::endl;

	std::cout << y << endl;

	std::cout << x + y << endl;
	std::cout << x - y << endl;
	std::cout << x * y << endl;
	std::cout << x / y << endl;
	std::cout << -x << std::endl;
	std::cout << +x << std::endl;



	return 0;
}

#endif



