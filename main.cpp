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




int main()
{
  
    return 0;
}
