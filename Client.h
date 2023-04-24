#ifndef CLIENT_H
#define CLIENT_H
#include <iostream>
#include <string.h>

using namespace std ;
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

#endif // CLIENT_H
