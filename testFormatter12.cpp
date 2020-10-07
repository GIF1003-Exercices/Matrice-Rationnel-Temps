/*
 * testFormatter12.cpp
 *
 *  Created on: 2020-10-06
 *      Author: etudiant
 */
//#define TESTFORMATTER!""

#ifdef TESTFORMATTER

#include "Temps.h"

#include <iostream>

using namespace std;

int main()
{
	Temps temps(15, 20, 20);

	cout << temps.formatter() << endl;
	cout << temps.formatter12() << endl;

	Temps temps2(12, 20, 20);

	cout << temps2.formatter() << endl;
	cout << temps2.formatter12() << endl;

	Temps temps3(23, 20, 59);

	cout << temps3.formatter() << endl;
	cout << temps3.formatter12() << endl;

	Temps temps4(1, 20, 20);

	cout << temps4.formatter() << endl;
	cout << temps4.formatter12() << endl;

	Temps temps5(2, 20, 20);

	cout << temps5.formatter() << endl;
	cout << temps5.formatter12() << endl;


	return 0;
}

#endif


