#include "reclamation.h"
#include "includes.h"

Reclamation::Reclamation()
{

}

Reclamation::Reclamation(QString id_reclamation,QString titre_reclamation,QString sujet_reclamation,QString id_client){
    this->id_reclamation=id_reclamation;
    this->titre_reclamation=titre_reclamation;
    this->sujet_reclamation=sujet_reclamation;
    this->id_client=id_client;
}
Reclamation::~Reclamation(){

}
//geters
QString Reclamation::getIdReclamation(){
    return this->id_reclamation;
}
QString Reclamation::getTitreReclamation(){
    return this->titre_reclamation;
}
QString Reclamation::getSujetReclamation(){
    return this->sujet_reclamation;
}
QString Reclamation::getIdClient(){
    return this->id_client;
}
//setters
void Reclamation::setIdReclamation(QString id_reclamation){
    this->id_reclamation=id_reclamation;
}
void Reclamation::setTitreReclamation(QString titre_reclamation){
    this->titre_reclamation=titre_reclamation;
}
void Reclamation::setSujetReclamation(QString sujet_reclamation){
    this->sujet_reclamation=sujet_reclamation;
}
void Reclamation::setIdClient(QString id_client){
    this->id_client=id_client;
}

//fonction
bool Reclamation::ajouterReclamation(){

    QSqlQuery query;

    query.prepare("insert into RECLAMATION(TITRE_RECLAMATION, SUJET_RECLAMATION, ID_CLIENT)"
                  "values(:ID_RECLAMATION, :TITRE_RECLAMATION, :SUJET_RECLAMATION, :ID_CLIENT)");


    query.bindValue(":TITRE_RECLAMATION",this->titre_reclamation);
    query.bindValue(":SUJET_RECLAMATION",this->sujet_reclamation);
    query.bindValue(":ID_CLIENT",this->id_client);

    return query.exec();
}

QSqlQueryModel* Reclamation::afficherReclamation(){
    QSqlQueryModel* model=new QSqlQueryModel();

    model->setQuery("SELECT * FROM RECLAMATION");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_RECLAMATION"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("TITRE_RECLAMATION"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("SUJET_RECLAMATION"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("ID_CLIENT"));

    return model;
}
bool Reclamation::supprimerReclamation(QString ID){
    QSqlQuery query;

    query.prepare("Delete from RECLAMATION where ID_RECLAMATION= :id");
    query.bindValue(":id",ID);

    return query.exec();
}

bool Reclamation::modifierReclamation(QString ID){
    QSqlQuery query;

    query.prepare("UPDATE RECLAMATION SET TITRE_RECLAMATION=:TITRE_RECLAMATION,\
                   SUJET_RECLAMATION=:SUJET_RECLAMATION Where ID_RECLAMATION=:ID");

    query.bindValue(":TITRE_RECLAMATION",this->titre_reclamation);
    query.bindValue(":SUJET_RECLAMATION",this->sujet_reclamation);
    query.bindValue(":ID",ID);

    return query.exec();
}
