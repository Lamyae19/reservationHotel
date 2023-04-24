#include "client.h"
#include <iomanip>
#include <iostream>
#include <string.h>

using namespace std ;

void Client::accepter() {         //ACCEPTER LES COORDONNÉES DU CLIENT
   cout<<"Enter le nom de client: ";
	getline(cin, nom);
	getline(cin, nom);
	cout<<"Enter l' addresse de client: ";
	getline(cin,adresse);
	flag:
	cout<<"Enter le numero de telephone : ";
	cin>>telephone;
	for(int i=0;i<(telephone.length());i++)	// VALIDATIONS DU NEMERO DE TELEPHONE
  	{
		if(!isdigit(telephone[i]))      ////le numero de telephone doit etre compose uniquement de chiffre et avoir une longueur de 10
		{
			cout<<"le numero de telephone doit etre en chiffres.\n";
			goto flag;
		}
  	}
  	if(telephone.length()!=10)
  	{
  	  cout<<"le numero de telephone doit comporter 10 chiffres.\n";
  	  goto flag;
 	 }
}
void Client::afficher()		////afficher les details du client
{
	cout<<id_reservation<<"\t\t";
	cout<<"| "<<left<<setfill(' ')<<setw(30)<<nom;
	cout<<"| "<<telephone<<"\t\t\t";
	cout<<"| "<<left<<setfill(' ')<<setw(30)<<adresse;
	cout<<"| "<<chambre<<"\t\t\t";
	if(statu==1){cout<<"|\t\t-\t|"<<endl;}
	else{cout<<"|dejat sortie.\t|"<<endl;}
}
