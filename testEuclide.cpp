/*
 * testEuclide.cpp
 *
 *  Created on: Oct 6, 2020
 *      Author: etudiant
 */
//#define TESTEUCLIDE
#ifdef TESTEUCLIDE

#include "Rationnel.h"
#include <iostream>

using namespace std;

int main()
{
	cout << Rationnel::pgdc(4, 2) << endl;
	cout << Rationnel::pgdc(28, 35) << endl;
	cout << Rationnel::pgdc(35, 28) << endl;
	cout <<Rationnel::pgdc(-35, 28) << endl;
	cout  << Rationnel::pgdc(35, -28) << endl;
	cout << Rationnel::pgdc(0, 56) << endl;
	cout << Rationnel::pgdc(0, 0) << endl;
	cout << Rationnel::pgdc(1234, 1234) << endl;
	return 0;
}

#endif


