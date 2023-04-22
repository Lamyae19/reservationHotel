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
	cout<<"taille du chambre grand ou petit (G/P) : "; // B=G;S=P
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
	statu=0;	//BOOKING STATUS OF THE ROOM
	cout<<"\nchambre ajoutee avec succes!"<<endl;
}
void Room::Afficherchambre()
{
	cout<<"| "<<num_chambre<<".\t\t|\t"<<ac<<"\t\t|\t"<<type<<"\t\t|\t"<<taille<<"\t\t|\t"<<prix<<"\t\t|\t";
	if(statu==0){cout<<"Disponible.\t|";}
	else{cout<<"Reserve.\t\t|";}
	cout<<endl;
}
class Hotel
{
	chambre a[100];			//ARRAY OF ROOMS
	Client c[100];			//ARRAY OF CUSTOMERS
	int nchambre=0, nclient=0;	//NO OF ROOMS AND CUSTOMERS
public:
	void AjoutChambre();		//addRooms
	void RecherChambre();		//searchroom
	void enregistr();			//CheckIn
	void recherclient();		//searchcust
	void disponibilite();	//availability
	void quitter();		//CheckOut
	void Resume();			//Summary
};
void Hotel::AjoutChambre()
{
	int numch;
	cout<<"Entrez le nombre des chambres: ";
	cin>>nchambre;		//ACCEPTING NUMBER OF ROOMS
	while(nchambre<=0)
	{
		cout<<"Invalide. Entrez un nombre valide des chambres.";
		cin>>nchambre;
	}
	for(int i=0;i<nchambre;i++)
	{
		cout<<"CHAMBRE "<<(i+1)<<endl;
		flag:
		cout<<endl<<"Entrez le numero de chambre : ";
		cin>>numch;
		if(numch<=0)		//VALIDATIONS
		{
			cout<<endl<<"Ce numero de chambre est invalide ! Veuillez ressaisir le numero de chambre : ";
			goto flag;
		}
		for(int i=0; i<nchambre;i++)	//VALIDATIONS FOR REPETITIVE ROOM NUMBERS
		{
			if(a[i].num_chambre==numch)
			{
				cout<<"Invalide. Numero de chambre repetitifs."<<endl;
				goto flag;
			}
		}
		a[i].acceptchambre(numch);		//CALLING FUNCTION ACCEPT ROOM FROM CLASS ROOM
	}
}
void Hotel::disponibilite()		//CHECKING AVAILABILITY OF THE ROOMS
{
	if(nchambre==0)
	{
		cout<<"Veuillez ajouter des chambres."<<endl;
		return;
	}
	cout<<"La liste de toutes les chambres disponibles:"<<endl;
	cout<<"| chambre No.\t|\tAC/Non-AC\t|\tType\t\t|\ttaille\t\t|\tprix\t\t|\tdisponibilite \t|"<<endl;
	for(int i=0;i<nchambre;i++)
	{
		a[i].Afficherchambre();	//DISPLAYING ROOM DETAILS
	}
}
void Hotel::RecherChambre()	//SEARCH FOR A PARTICULAR TYPE OF A ROOM
{
	if(nchambre==0)
	{
		cout<<"Veuillez ajouter des chambres."<<endl;
		return;
	}
	int flag=0;
	char ac1, type1, taille1;
	cout<<"Est-ce que tu veux AC ou Non-AC? (A/N): "<<endl;
	cin>>ac1;
	cout<<"Voulez-vous une suite ou une chambre normale ?"<<endl;
	cin>>type1;
	cout<<"taille? (G/P)"<<endl;
	cin>>taille1;
	for(int i=0;i<nchambre;i++)
	{
		if(a[i].ac==ac1 && a[i].type==type1 && a[i].taille==taille1)		//MAKING SURE ALL CONDITIONS ARE SATISFIED
		{
			flag=1;
			cout<<"Chambre trouvee."<<endl;
			a[i].Afficherchambre();
		}
	}
	if(flag==0)
	{
		cout<<"Aucune chambre n'est disponible."<<endl;
	}
}

int main()
{
	Hotel slm;		//HOTEL SLM SALMA.LAMIYA.MALAK
	char ch;
        
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
		cin>>ch;
		switch(ch)
		{
		case '1':
			cout<<"Ajouter une base de donnees des chambres de l'hotel:"<<endl;
			slm.addRooms();
			cout<<"Base de donnees mise a jour. Retour au menu principal."<<endl;
			break;
		case '2':
			char ch1;
			do
			{
				cout<<endl<<"************************************************************************************************************************************************************************"<<endl;
				cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~BIENVENUE AU GROUPE D'HOTELS SLM~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
				cout<<"\n\t\t\t\t\t\t\t\t\t"
					"Menu:\n\t\t\t\t\t\t\t\t\t"
					"1.Verifier la disponibilite des chambres\n\t\t\t\t\t\t\t\t\t"
					"2.cherches une chambre\n\t\t\t\t\t\t\t\t\t"
					"3.Enregistrement\n\t\t\t\t\t\t\t\t\t"
					"4.chercher un client\n\t\t\t\t\t\t\t\t\t"
					"5.Recapitulatif des invites\n\t\t\t\t\t\t\t\t\t"
					"6.quitter la chambre\n\t\t\t\t\t\t\t\t\t"
					"7.Retournez au menu principal\n\t\t\t\t\t\t\t\t\t"
					"Entrez votre choix:";
				cin>>ch1;
				switch(ch1)
				{
				case '1':
					slm.availability();
					break;
				case '2':
					slm.searchroom();
					break;
				case '3':
					slm.CheckIn();
					break;
				case '4':
					slm.searchcust();
					break;
				case '5':
					slm.Summary();
					break;
				case '6':
					slm.CheckOut();
					break;
				case '7':
					break;
				default:
					cout<<"Choix invalide."<<endl;
					break;
				}
			}while(ch1!='7');
			break;
		case '3':
			cout<<"merci! :)";
			exit(0);
		default:
			cout<<"Choix invalide."<<endl;
			break;
		}
	}while(ch!='3');
	return 0;
}

