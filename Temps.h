/****************************************************************************//**
 * Temps.h
 *
 * \Created on: 2020-10-01
 * \Author: Pascal Charpentier
 */

#ifndef TEMPS_H_
#define TEMPS_H_

#include <string>

/****************************************************************************//**
 * \class Temps
 *
 * \brief Objet représentant un instant de la journée.  Contient 3 champs entier:
 * heure minute et secondes.
 *
 *******************************************************************************/

class Temps
{

private:

	int m_heure;
	int m_minute;
	int m_seconde;

public:

	static bool validerHeure(int heure);
	static bool validerMinute(int minute);
	static bool validerSeconde(int seconde);

	Temps();
	Temps(const int heure, const int minute, const int seconde);
	Temps(std::string& chaine);

	bool valider();

	int reqHeure() const;
	int reqMinute() const;
	int reqSeconde() const;

	int convertirHeure() const;

	void modifierHeure(const int nouvelleHeure);
	void modifierMinute(const int nouvelleMinute);
	void modifierSeconde(const int nouvelleSeconde);
	void modifier(const int nouvelleHeure, const int nouvelleMinute, const int nouvelleSeconde);
	void modifier(const std::string texte);

	void avancerUneHeure();
	void avancerUneMinute();
	void tic();

	void affiche(void) const ;
	std::string formatter(const std::string separateur = ":") const;
	std::string formatter12(const std::string separateur = ":") const;
	friend std::ostream& operator<< (std::ostream& os, const Temps& temps);

};



#endif /* TEMPS_H_ */
