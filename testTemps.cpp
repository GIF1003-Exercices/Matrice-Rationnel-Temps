/*
 * testTemps.cpp
 *
 *  Created on: Oct 6, 2020
 *      Author: etudiant
 */
#define TESTEMPS

#ifdef TESTTEMPS

#include "Temps.h"

#include <iostream>
#include <unistd.h>

using namespace std;

int main()
{
	Temps maintenant;

	cout << maintenant.formatter12() << endl;
	while (1)
	{
		sleep(1);
		maintenant.tic();
		cout << maintenant.formatter12() << endl;
	}

	return 0;
}

#endif
