// reservationHotel.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <string.h>
#include <iomanip>
#include <ctime>
#include "client.h"
#include "chambre.h"
#include "hotel.h"

using namespace std;

             
int main()
{
	Hotel slm;		//HOTEL SLM SALMA.LAMIYAE.MALAK
	char choix;
        
	cout<<endl<<"=================================================================BIENVENUE AU GROUPE D'HOTELS SLM=======================================================================";
	do           
	{		
		cout<<endl<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
		cout<<endl<<"\t\t\t\t\t\t\t\t\t"
			"MENU:\n\t\t\t\t\t\t\t\t\t"
			"1.FONCTIONNER EN TANT QU'ADMINISTRATEUR\n\t\t\t\t\t\t\t\t\t"
			"2.AGIR COMME CLIENT\n\t\t\t\t\t\t\t\t\t"
			"3.SORTIE\n\t\t\t\t\t\t\t\t\t"
			"Entrez votre choix:";
		cin>>choix;
		switch(choix)
		{
		case '1':
			cout<<"Ajouter une base de donnees des chambres de l'hotel:"<<endl;
			slm.AjoutChambre();
			cout<<"Base de donnees mise a jour. Retour au menu principal."<<endl;
			break;
		case '2':
			char choix1;
			do
			{
				cout<<endl<<"************************************************************************************************************************************************************************"<<endl;
				cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~BIENVENUE AU GROUPE D'HOTELS SLM~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
				cout<<"\n\t\t\t\t\t\t\t\t\t\t\t"
					"Menu:\n\t\t\t\t\t\t\t\t\t"
					"1.Verifier la disponibilite des chambres\n\t\t\t\t\t\t\t\t\t"
					"2.cherches une chambre\n\t\t\t\t\t\t\t\t\t"
					"3.Enregistrement\n\t\t\t\t\t\t\t\t\t"
					"4.chercher un client\n\t\t\t\t\t\t\t\t\t"
					"5.Recapitulatif des invites\n\t\t\t\t\t\t\t\t\t"
					"6.quitter la chambre\n\t\t\t\t\t\t\t\t\t"
					"7.Retournez au menu principal\n\t\t\t\t\t\t\t\t\t"
					"Entrez votre choix:";
				cin>>choix1;
				switch(choix1)
				{
				case '1':
					slm.disponibilite();
					break;
				case '2':
					slm.RecherChambre();
					break;
				case '3':
					slm.enregistr();
					break;
				case '4':
					slm.recherclient();
					break;
				case '5':
					slm.Resume();
					break;
				case '6':
					slm.quitter();
					break;
				case '7':
					break;
				default:
					cout<<"Choix invalide."<<endl;
					break;
				}
			}while(choix1!='7');
			break;
		case '3':
			cout<<"merci! :)";
			exit(0);
		default:
			cout<<"Choix invalide."<<endl;
			break;
		}
	}while(choix!='3');
	return 0;
}

