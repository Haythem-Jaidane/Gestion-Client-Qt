#include "connection.h"

Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;

QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("Projet");
db.setUserName("Haythem_1");//inserer nom de l'utilisateur
db.setPassword("h01");//inserer mot de passe de cet utilisateur

if (db.open())
    test=true;


return  test;
}
