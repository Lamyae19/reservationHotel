// reservationHotel.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <string.h>
#include <iomanip>
#include <ctime>

using namespace std;

             // Class client
class Client {
    string nom;
    string prenom;
    string adresse;
    string telephone;
    string cin;
    int jours = 0;
    float Avance_de_paiement;
    double facture=0 ;
    int id_reservation ;
    int chambre;
    int statut; 
public :
    Client() {
        jours = 0;
        Avance_de_paiement = 0;
        facture = 0;
        id_reservation = 0;
        statut = 0;
        chambre = 0;
    }
    void accepter();
    void afficher(); 
    friend class chambre;
    friend class htoel;

};
void Client::accepter() {
    cout << "Saisir le nom de client ";
    std::basic_istream::getline(cin, nom);
    cout << "Saisir le prenom de client ";
    std::basic_istream::getline(cin, prenom);
}




class chambre
{
	char type;				
	char taille;				//stype= taille
	char ac;				//AC OR NON AC 
	int num_chambre;			//roomNumber
	double prix;			//rent=prix
	int statu=0;			//ROOM IS BOOKED OR NOT
public:
	friend class Hotel;
	void acceptchambre(int numch);		//rno = numch
	void displaychambre();		//DISPLAY ROOMS
	chambre()					//DEFAULT CONSTRUCTOR
	{
		type='\0';
		taille='\0';
		ac='\0';
		num_chambre=0;
		prix=0;
		statu=0;
	}
};
void Room::acceptchambre(int numch)		//ACCEPTING ALL ROOM DETAILS
{
	num_chambre=numch;	//ROOM NUMBER
	cout<<"Type: AC/Non-AC [AC=air conditionné](A/N) : ";
	cin>>ac;
	while(ac!='A'&& ac!='N')		//VALIDATIONS
	{
		cout<<"Veuillez ré-entrer le Type: AC/Non-AC (A/N) : ";
		cin>>ac;
	}
	cout<<"Type Suite Confort ou Normal(S/N) : ";
	cin>>type;
	while(type!='S' && type!='N')
	{
		cout<<"Veuillez saisir à nouveau Type Suite Confort ou Normal(S/N) : ";
		cin>>type;
	}
	cout<<"taille du chambre grand ou petit (G/P) : "; // B=G;S=P
	cin>>taille;
	while(taille!='G'&& taille!='P')
	{
		cout<<"Veuillez saisir à nouveau la taille du chambre grand ou petit (G/P) : ";
		cin>>taille;
	}
	cout<<"Loyer journalier : ";
	cin>>prix;
	while(prix<0 || prix>20000)
	{
		cout<<"Veuillez entrer un loyer valide.";
		cin>>prix;
	}
	statu=0;	//BOOKING STATUS OF THE ROOM
	cout<<"\nchambre ajoutée avec succès!"<<endl;
}



int main()
{
  
    return 0;
}
