#ifndef HOTEL_H
#define HOTEL_H
#include "client.h"
#include "chambre.h"

//class Hotel
class Hotel
{
	chambre a[100];			//  TABLEAU DE CHAMBRES
	Client c[100];			//TABLEAU DE CLIENTS
	int nchambre=0, noclient=0;	//NOMBRE DE CHAMBRES ET DE CLIENTS
public:
	void AjoutChambre();		//ajouter des chambres
	void RecherChambre();		// RecherChambre
	void enregistr();			//enregistrer
	void recherclient();		//recherclient
	void disponibilite();	//disponibilite
	void quitter();		//quitter
	void Resume();			// Resume
};
#endif // HOTEL_H
