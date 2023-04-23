// reservationHotel.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <string.h>
#include <iomanip>
#include <ctime>

using namespace std;

             // Class client
class Client {
    string nom;    //  nom complet du client 
    string adresse;//  adresse du client 
    string telephone;   // numero de telephone 
    int jours = 0;    //  la duree de reservation
    float Avance_de_paiement; 
    double facture=0 ;
    int id_reservation ;   //identifiant de reservation 
    int chambre;        //numero de chambre 
    int statu;  
public :
    Client() {
        jours = 0;
        Avance_de_paiement = 0;
        facture = 0;
        id_reservation = 0;
        statu = 0;
        chambre = 0;
    }
    void accepter();     //ACCEPTER LES COORDONNÉES DU CLIENT
    void afficher();     //AFFICHER LES COORDONNÉES DU CLIENT
    friend class chambre;
    friend class Hotel;

};
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
void Hotel::AjoutChambre()
{
	int numch;
	cout<<"Entrez le nombre des chambres: ";
	cin>>nchambre;		//ACCEPTER LE NOMBRE DE CHAMBRES
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
		for(int i=0; i<nchambre;i++)	//VALIDATIONS POUR DES NUMÉROS DE CHAMBRE RÉPÉTITIFS
		{
			if(a[i].num_chambre==numch)
			{
				cout<<"Invalide. Numero de chambre repetitifs."<<endl;
				goto flag;
			}
		}
		a[i].acceptchambre(numch);		//FONCTION D'APPEL ACCEPTER CHAMBRE DEPUIS SALLE DE CLASSE
	}
}
void Hotel::disponibilite()		//VÉRIFICATION DE LA DISPONIBILITÉ DES CHAMBRES
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
		a[i].Afficherchambre();	//AFFICHAGE DES DÉTAILS DE LA CHAMBRE
	}
}
void Hotel::RecherChambre()	//RECHERCHE D'UN TYPE PARTICULIER DE CHAMBRE
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
	cout<<"Voulez-vous une suite ou une chambre normale(S/N) ?"<<endl;
	cin>>type1;
	cout<<"taille? (G/P)"<<endl;
	cin>>taille1;
	for(int i=0;i<nchambre;i++)
	{
		if(a[i].ac==ac1 && a[i].type==type1 && a[i].taille==taille1)		// S'ASSURER QUE TOUTES LES CONDITIONS SONT SATISFAITES
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
void Hotel::enregistr()		//ENREGISTREMENT D'UN CLIENT
{
	if(nchambre==0)
	{
		cout<<"Veuillez ajouter des chambres."<<endl;
		return;
	}
	int i, numch;
	if(noclient<=nchambre){	//VÉRIFICATION DE LA CONDITION SI L'HÔTEL A DES CHAMBRES VIDE
		c[noclient].id_reservation=noclient+1;	//ATTRIBUTION D'UN IDENTIFIANT CLIENT AU CLIENT
		flag:
		int flag1=0;
		cout<<"Entrez le numero de chambre = ";		//DEMANDER DANS QUEL NUMÉRO DE CHAMBRE LE CLIENT SOUHAITE SÉJOURNER
                 cin>>numch ;
		for(i=0;i<nchambre; i++){
			if(numch==a[i].num_chambre)
			{
				flag1=1;
				break;
			}
		}
		if(flag1==0){
			cout<<"Numero de chambre invalide. Veuillez entrer a nouveau.\n";
			goto flag;
		}
		if(a[i].statu==0)		//VERIFIER SI LA CHAMBRE EST INOCCUPEE
		{
			char ch2;
			cout<<"Chambre disponible."<<endl;
			a[i].Afficherchambre();
			cout<<"Souhaitez-vous continuer? entree(Y/y)";		//CONFIRMATION
			cin>>ch2;
			if(ch2=='Y'||ch2=='y')
			{
				c[noclient].accepter();		//ACCEPTATION DES COORDONNÉES DU CLIENT
				cout<<"Entrez le nombre de jours de sejour: ";          
				cin>>c[noclient].jours;
				c[noclient].facture = c[noclient].jours*a[i].prix;		// générer la facture. bill= Nbre de jours * loyer par jour.
				cout<<"Votre facture totale sera d'environ DH."<<(c[noclient].facture)<<"."<<endl<<"le Min Avance de paiement="<<c[noclient].facture/4<<"...>"<<"Que paierez-vous?";
				cin>>c[noclient].Avance_de_paiement;
				while(c[noclient].Avance_de_paiement<c[noclient].facture/4||c[noclient].Avance_de_paiement>c[noclient].facture)
				{
					cout<<"Entrez un montant valide.";
					cin>>c[noclient].Avance_de_paiement;
				}
				cout<<"Merci. Reservation confirmee."<<endl;		//réservation confirmée
				cout<<"--------------------------------------------------------------"<<endl;		//imprimer les détails de la réservation
				cout<<"Reservation Id: "<<c[noclient].id_reservation<<"\nNom: "<<c[noclient].nom<<"\nRoom no.: "<<numch<<"\nDate: ";
				time_t my_time = time(NULL);
						// ctime() utilisé pour donner l'heure actuelle
				printf("%s", ctime(&my_time));
				a[i].statu=1;		//changer le statut de la chambre en réservé
				c[noclient].chambre=numch;		//attribuer de la place au client
				c[noclient].statu=1;
				noclient++;
			}
			else		//si besoin de changer de numéro de chambre
			{
				goto flag;
			}
		}
		else		//si la chambre est occupée
		{
			cout<<"Chambre occupee. Veuillez choisir une autre chambre."<<endl;
		}
	}
	else		//CONDITION TOUTES LES CHAMBRES SONT RÉSERVÉES
	{
		cout<<"Desole! L'hotel est plein. :("<<endl;
	}
}
void Hotel::recherclient()
{
	int id, flag=0;
	cout<<"Entrez l'identifiant de reservation du client: ";
	cin>>id;
	for(int i=0;i<=noclient;i++)		//RECHERCHE DE CLIENT
	{
		if(c[i].id_reservation==id)
		{
			cout<<"\t\t\t Nom "<<setw(20);
			cout<<"\t\t\t telephone "<<setw(20);
			cout<<"\t\t\t adresse "<<setw(20);
			cout<<"\t\t\tchambre no "<<setw(20)<<endl;
			c[i].afficher();
			flag=1;
		}
	}
	if(flag==0)		//case not found
	{
		cout<<"Aucun client trouve."<<endl;
	}
}
void Hotel::quitter()		//CHECKING OUT
{
	int numch, i, j;
	cout<<"Entrez le numero de chambre= ";
	cin>>numch;
	for(j=0;j<nchambre; j++){
		if(numch==a[j].num_chambre)
		{
			break;
		}
	}
	if(a[j].statu==0)		//SI CHAMBRE NON TROUVÉE OCCUPÉE
	{
		cout<<"Invalide."<<endl;
	}
	for(i=0;i<noclient;i++)	//VÉRIFICATION DES DONNÉES DU CLIENT
	{
		if(c[i].chambre==numch)
		{
			cout<<"dejat sortie."<<endl;
			c[i].afficher();		//Client DETAILS
			cout<<"Votre facture totale est : "<<c[i].facture<<endl;
			cout<<"Avance de paiement : "<<c[i].Avance_de_paiement;
			cout<<endl<<"le reste du paiement = DH."<<c[i].facture-c[i].Avance_de_paiement;		//PAIEMENTS EN ATTENTE
			cout<<endl<<"Merci! Visiter encore :)"<<endl;
			a[j].statu=0;	//CHANGING STATUS OF ROOM TO UNOCCUPIED
			c[i].statu=0;	//CHECKED OUT
			break;
		}
	}
}
void Hotel::Resume()		//IMPRESSION DE LA LISTE DE TOUS LES CLIENTS
{
	if(nchambre==0)
	{
		cout<<"Pas encore de clients."<<endl;
		return;
	}
	cout<<"Recapitulatif des invites:"<<endl;
	cout<<"Id.\t\t";
	cout<<"|	Nom	\t\t";
	cout<<"|	telephone\t\t";
	cout<<"|	adresse	\t\t";
	cout<<"|	chambre no \t";
	cout<<"|	Statu	\t|"<<endl;
	for(int i=0;i<noclient;i++)
	{
		c[i].afficher();
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
			slm.AjoutChambre();
			cout<<"Base de donnees mise a jour. Retour au menu principal."<<endl;
			break;
		case '2':
			char ch1;
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
				cin>>ch1;
				switch(ch1)
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

