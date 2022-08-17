#ifndef CLIENT_H
#define CLIENT_H

#include <QString>
#include <QDate>
#include "includes.h"


class Client
{
private:

    QString Id_client;
    QString nom;
    QString prenom;
    int age;
    QDate date_naissance;
    QString Vile;
    QString Adresse;
    QString sexe;
    QString Metier;
    float score;
    int niveau;
    QString badge;
    int etat_livraison;
    QString commande;
public:
    Client();
    Client(QString Id_client,QString nom,QString prenom,int age, QDate date_naissance,QString Vile,QString Adresse,QString sexe,
           QString Metier,float score,int niveau,QString badge,int etat_livraison,QString commande);
    ~Client();
    // geters
    QString getId();
    QString getNom();
    QString getPrenom();
    int getage();
    QDate getDate();
    QString getVile();
    QString getAdresse();
    QString getSexe();
    QString getMetier();
    float getScore();
    int getNiveau();
    QString getBadge();
    int getEtat();
    QString getCommande();
    // seters
    void setId(QString id);
    void setNom(QString nom);
    void setPrenom(QString prenom);
    void setage(int age);
    void setDate(QDate date);
    void setVile(QString vile);
    void setAdresse(QString adresse);
    void setSexe(QString sexe);
    void setMetier(QString metier);
    void setScore(float score);
    void setNiveau(int niveau);
    void setBadge(QString badge);
    void setEtat(int etat);
    void setCommande(QString commande);
    //function
    bool ajouterClient();
    QSqlQueryModel* afficherClient();
    bool supprimerClient(QString Id);
    bool modifierClient(QString Id);
    void fidelisation();
    QString affichage(QString ID);
};

#endif // CLIENT_H
