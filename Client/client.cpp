#include "client.h"
#include <QDebug>

Client::Client(){

}

Client::Client(QString Id_client,QString nom,QString prenom,int age, QDate date_naissance,QString Vile,QString Adresse,QString sexe,
               QString Metier,float score,int niveau,QString badge,int etat_livraison,QString commande){
    this->Id_client=Id_client;
    this->nom=nom;
    this->prenom=prenom;
    this->age=age;
    this->date_naissance=date_naissance;
    this->Vile=Vile;
    this->Adresse=Adresse;
    this->sexe=sexe;
    this->Metier=Metier;
    this->score=score;
    this->niveau=niveau;
    this->badge=badge;
    this->etat_livraison=etat_livraison;
    this->commande=commande;
}

Client::~Client(){

}
// geters
QString Client::getId(){
    return this->Id_client;
}

QString Client::getNom(){
    return this->nom;
}

QString Client::getPrenom(){
    return this->prenom;
}

int Client::getage(){
    return this->age;
}

QDate Client::getDate(){
    return this->date_naissance;
}

QString Client::getVile(){
    return this->Vile;
}

QString Client::getAdresse(){
    return this->Adresse;
}

QString Client::getSexe(){
    return this->sexe;
}

QString Client::getMetier(){
    return this->Metier;
}

float Client::getScore(){
    return this->score;
}

int Client::getNiveau(){
    return this->niveau;
}

QString Client::getBadge(){
    return this->badge;
}

int Client::getEtat(){
    return this->etat_livraison;
}

QString Client::getCommande(){
    return this->commande;
}

// seters
void Client::setId(QString id){
    this->Id_client=id;
}

void Client::setNom(QString nom){
    this->nom=nom;
}

void Client::setPrenom(QString prenom){
    this->prenom=prenom;
}

void Client::setage(int age){
    this->age=age;
}

void Client::setDate(QDate date){
    this->date_naissance=date;
}
void Client::setVile(QString vile){
    this->Vile=vile;
}

void Client::setAdresse(QString adresse){
    this->Adresse=adresse;
}

void Client::setSexe(QString sexe){
    this->sexe=sexe;
}

void Client::setMetier(QString metier){
    this->Metier=metier;
}

void Client::setScore(float score){
    this->score=score;
}

void Client::setNiveau(int niveau){
    this->niveau=niveau;
}

void Client::setBadge(QString badge){
    this->badge=badge;
}

void Client::setEtat(int etat){
    this->etat_livraison=etat;
}

void Client::setCommande(QString commande){
    this->commande=commande;
}

//function
bool Client::ajouterClient(){

    QSqlQuery query;

    query.prepare("insert into CLIENT(NOM, PRENOM, AGE, DATE_NAISSANCE, VILE,\
                   ADDRESSE, SEXE, METIER,SCORE,  NIVEAU, BADGE, ETAT_LIVRAISON, COMMANDE)"
                  "values(:NOM, :PRENOM, :AGE,:DATE_NAISSANCE , :VILE,\
                   :ADDRESSE, :SEXE, :METIER,:SCORE, :NIVEAU, :BADGE, :ETAT_LIVRAISON, :COMMANDE)");

    query.bindValue(":NOM",this->getNom());
    query.bindValue(":PRENOM",this->getPrenom());
    query.bindValue(":AGE",this->getage());
    query.bindValue(":DATE_NAISSANCE",this->getDate());
    query.bindValue(":VILE",this->getVile());
    query.bindValue(":ADDRESSE",this->getAdresse());
    query.bindValue(":SEXE",this->getSexe());
    query.bindValue(":METIER",this->getMetier());
    query.bindValue(":SCORE",0.0);
    query.bindValue(":NIVEAU",this->getNiveau());
    query.bindValue(":BADGE",this->getBadge());
    query.bindValue(":ETAT_LIVRAISON",this->etat_livraison);
    query.bindValue(":COMMANDE",this->getCommande());

    qDebug() << this->getScore();


    qDebug() << query.exec();

    return query.exec();
}

QSqlQueryModel* Client::afficherClient(){
    QSqlQueryModel* model=new QSqlQueryModel();

    model->setQuery("SELECT * FROM CLIENT");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_CLIENT"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("PRENOM"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("AGE"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("DATE_NAISSANCE"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("VILE"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("ADDRESSE"));
    model->setHeaderData(7,Qt::Horizontal,QObject::tr("SEXE"));
    model->setHeaderData(8,Qt::Horizontal,QObject::tr("METIER"));
    model->setHeaderData(9,Qt::Horizontal,QObject::tr("SCORE"));
    model->setHeaderData(10,Qt::Horizontal,QObject::tr("NIVEAU"));
    model->setHeaderData(11,Qt::Horizontal,QObject::tr("BADGE"));
    model->setHeaderData(12,Qt::Horizontal,QObject::tr("ETAT_LIVRAISON"));
    model->setHeaderData(13,Qt::Horizontal,QObject::tr("COMMANDE"));

    return model;
}

bool Client::supprimerClient(QString Id){
    QSqlQuery query;

    query.prepare("Delete from Client where ID_CLIENT= :id");
    query.bindValue(":id",Id);

    return query.exec();
}

bool Client::modifierClient(QString Id){
    QSqlQuery query;

    query.prepare("UPDATE CLIENT SET NOM=:NOM, PRENOM=:PRENOM, AGE=:AGE, DATE_NAISSANCE=:DATE_NAISSANCE, \
                   VILE=:VILE,ADDRESSE=:ADDRESSE, SEXE=:SEXE, METIER=:METIER, SCORE=:SCORE, NIVEAU=:NIVEAU,\
                   BADGE=:BADGE, ETAT_LIVRAISON=:ETAT_LIVRAISON, COMMANDE=:COMMANDE Where ID_CLIENT=:ID");

    query.bindValue(":NOM",this->getNom());
    query.bindValue(":PRENOM",this->getPrenom());
    query.bindValue(":AGE",this->getage());
    query.bindValue(":DATE_NAISSANCE",this->getDate());
    query.bindValue(":VILE",this->getVile());
    query.bindValue(":ADDRESSE",this->getAdresse());
    query.bindValue(":SEXE",this->getSexe());
    query.bindValue(":METIER",this->getMetier());
    query.bindValue(":SCORE",this->getScore());
    query.bindValue(":NIVEAU",this->getNiveau());
    query.bindValue(":BADGE",this->getBadge());
    query.bindValue(":ETAT_LIVRAISON",this->getEtat());
    query.bindValue(":COMMANDE",this->getCommande());
    query.bindValue(":ID",Id);

    return query.exec();

}

void Client::fidelisation(){

}

QString Client::affichage(QString ID){

    QSqlQuery query;

    QString d="ID_CLIENT="+ID;

    QSqlTableModel model;
    model.setTable("CLIENT");
    model.setFilter(d);
    model.select();

    QString commande = model.record(0).value("COMMANDE").toString();



    query.prepare("UPDATE CLIENT SET ETAT_LIVRAISON=:ETAT_LIVRAISON Where ID_CLIENT=:ID");

    query.bindValue(":ETAT_LIVRAISON",2);
    query.bindValue(":ID",ID);

    query.exec();

    return commande;

}
