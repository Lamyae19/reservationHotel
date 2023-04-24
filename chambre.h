#ifndef CHAMBRE_H
#define CHAMBRE_H
#include <iostream>
#include <string.h>

////CLASS chambre
class chambre
{
	char type;
	char taille;				// taille
	char ac;				//AC OR NON AC
	int num_chambre;			//numero de la chambre
	double prix;			//prix
	int statu=0;			//LA CHAMBRE EST RÉSERVÉE OU NON
public:
	friend class Hotel;
	void acceptchambre(int numch);		//rno = numch
	void Afficherchambre();
	chambre()					//CONSTRUCTEUR PAR DÉFAUT
	{
		type='\0';
		taille='\0';
		ac='\0';
		num_chambre=0;
		prix=0;
		statu=0;
	}
};

#endif // CHAMBRE_H
