#include "chambre.h"
#include <iomanip>
#include <iostream>
#include <string.h>
using namespace std ;

void chambre::acceptchambre(int numch)		//ACCEPTER TOUS LES DÉTAILS DE LA CHAMBRE
{
	num_chambre=numch;	//NUMÉRO DE CHAMBRE
	cout<<"Type: AC/Non-AC [AC=air conditionne](A/N) : ";
	cin>>ac;
	while(ac!='A'&& ac!='N')		//VALIDATIONS
	{
		cout<<"Veuillez re-entrer le Type: AC/Non-AC (A/N) : ";
		cin>>ac;
	}
	cout<<"Type Suite Confort ou Normal(S/N) : ";
	cin>>type;
	while(type!='S' && type!='N')
	{
		cout<<"Veuillez saisir a nouveau Type Suite Confort ou Normal(S/N) : ";
		cin>>type;
	}
	cout<<"taille du chambre grand ou petit (G/P) : "; // G=grand ,p= petit
	cin>>taille;
	while(taille!='G'&& taille!='P')
	{
		cout<<"Veuillez saisir a nouveau la taille du chambre grand ou petit (G/P) : ";
		cin>>taille;
	}
	cout<<"Loyer journalier : ";
	cin>>prix;
	while(prix<0 || prix>20000)
	{
		cout<<"Veuillez entrer un loyer valide.";
		cin>>prix;
	}
	statu=0;	//STATUT DE LA RESERVATION DE LA CHAMBRE
	cout<<"\nchambre ajoutee avec succes!"<<endl;
}
void chambre::Afficherchambre()
{
	cout<<"| "<<num_chambre<<".\t\t|\t"<<ac<<"\t\t|\t"<<type<<"\t\t|\t"<<taille<<"\t\t|\t"<<prix<<"\t\t|\t";
	if(statu==0){cout<<"Disponible.\t|";}
	else{cout<<"Reserve.\t\t|";}
	cout<<endl;
}
