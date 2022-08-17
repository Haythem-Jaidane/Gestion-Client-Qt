#ifndef RECLAMATION_H
#define RECLAMATION_H

#include <QString>
#include "includes.h"

class Reclamation
{
private:
    QString id_reclamation;
    QString titre_reclamation;
    QString sujet_reclamation;
    QString id_client;
public:
    Reclamation();
    Reclamation(QString id_reclamation,QString titre_reclamation,QString sujet_reclamation,QString id_client);
    ~Reclamation();
    //geters
    QString getIdReclamation();
    QString getTitreReclamation();
    QString getSujetReclamation();
    QString getIdClient();
    //setters
    void setIdReclamation(QString id_reclamation);
    void setTitreReclamation(QString id_reclamation);
    void setSujetReclamation(QString id_reclamation);
    void setIdClient(QString id_reclamation);
    
    //fonction
    bool ajouterReclamation();
    QSqlQueryModel* afficherReclamation();
    bool supprimerReclamation(QString ID);
    bool modifierReclamation(QString ID);
};

#endif // RECLAMATION_H
