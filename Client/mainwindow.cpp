#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "reclamation.h"
#include "client.h"
//#include "SmtpMime"
#include <qDebug>

#include<QComboBox>
#include <QPieSlice>
#include <QPieSeries>
#include <QtCharts/QChartView>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    this->D.setDate(2001,02,02);

    this->C.setId("50");
    this->C.setPrenom("haythem");
    this->C.setNom("jaidane");
    this->C.setage(21);
    this->C.setDate(D);
    this->C.setVile("sousse");
    this->C.setAdresse("2 rue");
    this->C.setSexe("H");
    this->C.setMetier("etudiant");
    this->C.setScore(100.6);
    this->C.setNiveau(5);
    this->C.setBadge("gold");
    this->C.setEtat(0);
    this->C.setCommande("");

    ui->setupUi(this);

    int ret=A.connect_arduino(); // lancer la connexion à arduino
    switch(ret){
        case(0):qDebug()<< "arduino is available and connected to : "<< A.getarduino_port_name();
            break;
        case(1):qDebug() << "arduino is available but not connected to :" <<A.getarduino_port_name();
            break;
        case(-1):qDebug() << "arduino is not available";
        }

    ui->sexe->addItem("M");
    ui->sexe->addItem("F");
    ui->Vile->addItem("Ariana");
    ui->Vile->addItem("Béja");
    ui->Vile->addItem("Ben Arous");
    ui->Vile->addItem("Bizerte");
    ui->Vile->addItem("Gabès");
    ui->Vile->addItem("Gafsa");
    ui->Vile->addItem("Jendouba");
    ui->Vile->addItem("Kairouan");
    ui->Vile->addItem("Kasserine");
    ui->Vile->addItem("Kébili");
    ui->Vile->addItem("Le Kef");
    ui->Vile->addItem("Mahdia");
    ui->Vile->addItem("La Manouba");
    ui->Vile->addItem("Médenine");
    ui->Vile->addItem("Monastir");
    ui->Vile->addItem("Nabeul");
    ui->Vile->addItem("Sfax");
    ui->Vile->addItem("Sidi Bouzid");
    ui->Vile->addItem("Siliana");
    ui->Vile->addItem("Sousse");
    ui->Vile->addItem("Tataouine");
    ui->Vile->addItem("Tozeur");
    ui->Vile->addItem("Tunis");
    ui->Vile->addItem("Zaghouan");

    ui->sexe_m->addItem("M");
    ui->sexe_m->addItem("F");
    ui->Vile_m->addItem("Ariana");
    ui->Vile_m->addItem("Béja");
    ui->Vile_m->addItem("Ben Arous");
    ui->Vile_m->addItem("Bizerte");
    ui->Vile_m->addItem("Gabès");
    ui->Vile_m->addItem("Gafsa");
    ui->Vile_m->addItem("Jendouba");
    ui->Vile_m->addItem("Kairouan");
    ui->Vile_m->addItem("Kasserine");
    ui->Vile_m->addItem("Kébili");
    ui->Vile_m->addItem("Le Kef");
    ui->Vile_m->addItem("Mahdia");
    ui->Vile_m->addItem("La Manouba");
    ui->Vile_m->addItem("Médenine");
    ui->Vile_m->addItem("Monastir");
    ui->Vile_m->addItem("Nabeul");
    ui->Vile_m->addItem("Sfax");
    ui->Vile_m->addItem("Sidi Bouzid");
    ui->Vile_m->addItem("Siliana");
    ui->Vile_m->addItem("Sousse");
    ui->Vile_m->addItem("Tataouine");
    ui->Vile_m->addItem("Tozeur");
    ui->Vile_m->addItem("Tunis");
    ui->Vile_m->addItem("Zaghouan");

    ui->Afficher_Reclamation->setModel(R.afficherReclamation());
    ui->Afficher_client->setModel(C.afficherClient());

    ui->Id_client_f->setText(C.getId());
    ui->nom_prenom->setText(C.getPrenom()+" "+C.getNom());
    ui->badge->setText(C.getBadge());
    //ui->exp->setText(QString(C.getScore())+" xp");

    /*QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from CLIENT where AGE < 20 ");
    float salaire=model->rowCount();
    model->setQuery("select * from CLIENT where AGE  between 21 and 35 ");
    float salairee=model->rowCount();
    model->setQuery("select * from CLIENT where AGE>36 ");
    float salaireee=model->rowCount();
    float total=salaire+salairee+salaireee;
    QString a=QString(" personnel moins de 750dt "+QString::number((salaire*100)/total,'f',2)+"%" );
    QString b=QString(" personnel entre 750 et2500 dt "+QString::number((salairee*100)/total,'f',2)+"%" );
    QString c=QString("personnel +2600dt"+QString::number((salaireee*100)/total,'f',2)+"%" );
    QPieSeries *series = new QPieSeries();
    series->append(a,salaire);
    series->append(b,salairee);
    series->append(c,salaireee);
    if (salaire!=0){
        QPieSlice *slice = series->slices().at(0);
        slice->setLabelVisible();
        slice->setPen(QPen());
    }
    if ( salairee!=0){
                             // Add label, explode and define brush for 2nd slice
        QPieSlice *slice1 = series->slices().at(1);
                             //slice1->setExploded();
        slice1->setLabelVisible();
    }
    if(salaireee!=0){
                             // Add labels to rest of slices
        QPieSlice *slice2 = series->slices().at(2);
                             //slice1->setExploded();
        slice2->setLabelVisible();
    }
                            // Create the chart widget
    QChart *chart = new QChart();
                            // Add data to chart with title and hide legend
    chart->addSeries(series);
    chart->setTitle("Pourcentage Par Duree d'e promotion'commande des personnels :salaire  "+ QString::number(total));
    chart->legend()->hide();
                            // Used to display the chart
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->resize(1000,500);
    chartView->show();*/


    ui->quickWidget->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_r_clicked()
{
    QString titre=ui->titre_reclamation->text();
    QString reclamation=ui->reclamation->toPlainText();

    Reclamation R("5de8",titre,reclamation,"8kj4");

    bool test=R.ajouterReclamation();
    ui->Afficher_Reclamation->setModel(R.afficherReclamation());

    if(test){
        qDebug() << "yes";
    }
    else{
        qDebug() << "no";
    }
}


void MainWindow::on_pushButton_3_clicked()
{
    QString id=ui->id_reclamation->text();

    bool test=R.supprimerReclamation(id);
    ui->Afficher_Reclamation->setModel(R.afficherReclamation());

    if(test){
        qDebug() << "yes";
    }
    else{
        qDebug() << "no";
    }
}


void MainWindow::on_pushButton_5_clicked()
{
    QString id=ui->Id_reclamation_m->text();
    QString titre=ui->Titre_m->text();
    QString reclamation=ui->Reclamation_m->toPlainText();

    Reclamation R(id,titre,reclamation,"8kj4");

    bool test=R.modifierReclamation(id);
    ui->Afficher_Reclamation->setModel(R.afficherReclamation());

    if(test){
        qDebug() << "yes";
    }
    else{
        qDebug() << "no";
    }
}


void MainWindow::on_pushButton_clicked()
{
    QString nom=ui->Nom_client->text();
    QString prenom=ui->Prenom_client->text();
    int age=ui->age_Client->text().toInt();
    QDate date=ui->date->date();
    QString adresse=ui->Adresse_Client->text();
    QString vile=ui->Vile->currentText();
    QString metier=ui->Metier_Client->text();
    QString sexe=ui->sexe->currentText();

    Client C("7de8",nom,prenom,age, date,vile,adresse,sexe,
             metier,0.0f,0,"none",0,"");

    bool test=C.ajouterClient();
    ui->Afficher_client->setModel(C.afficherClient());

    if(test){
        qDebug() << "yes";
    }
    else{
        qDebug() << "no";
    }
}


void MainWindow::on_pushButton_6_clicked()
{

    QString id=ui->Id_S->text();

    bool test=C.supprimerClient(id);
    ui->Afficher_client->setModel(C.afficherClient());

    if(test){
        qDebug() << "yes";
    }
    else{
        qDebug() << "no";
    }
}


void MainWindow::on_pushButton_7_clicked()
{
    QString id=ui->id_m->text();
    QString nom=ui->nom_m->text();
    QString prenom=ui->Prenom_m->text();
    QDate date=ui->date_m->date();
    int etat=ui->etat_m->text().toInt();
    int age=ui->age_m->text().toInt();
    QString badge=ui->badge_m->text();
    QString commande=ui->commande_m->text();
    QString ville=ui->Vile_m->currentText();
    QString sexe=ui->sexe_m->currentText();
    float score=ui->score_m->text().toFloat();
    QString adresse=ui->Adresse_m->text();
    QString metier=ui->Metier_m->text();
    int niveau=ui->Niveau_m->text().toInt();

    Client C(id,nom,prenom,age, date,ville,adresse,sexe,
             metier,score,niveau,badge,etat,commande);


    bool test=C.modifierClient(id);
    ui->Afficher_client->setModel(C.afficherClient());

    if(test){
        qDebug() << "yes";
    }
    else{
        qDebug() << "no";
    }
}

bool MainWindow::on_pushButton_4_clicked()
{
    QSqlQuery query;
    QString commande=ui->commande_l->toPlainText();

    qDebug() << this->C.getId();
    qDebug() << commande;

    query.prepare("UPDATE CLIENT SET ETAT_LIVRAISON=:ETAT_LIVRAISON, COMMANDE=:COMMANDE Where ID_CLIENT=:ID");

    query.bindValue(":ETAT_LIVRAISON",1);
    query.bindValue(":COMMANDE",commande);
    query.bindValue(":ID",this->C.getId());

    return query.exec();

}


void MainWindow::on_pushButton_2_clicked()
{
    QString mail=ui->mail_text->text();
    QString content=ui->content_mail->toPlainText();
    /*SmtpClient smtp("smtp.gmail.com", 465, SmtpClient::SslConnection);

        // We need to set the username (your email address) and the password
        // for smtp authentification.

        smtp.setUser("haythemhassine.jaidane@esprit.tn");
        smtp.setPassword("201JMT2778");

        // Now we create a MimeMessage object. This will be the email.

        MimeMessage message;

        message.setSender(new EmailAddress("haythemhassine.jaidane@esprit.tn", "Our Dry"));
        message.addRecipient(new EmailAddress(mail, "Recipient's Name"));
        message.setSubject("SmtpClient for Qt - Demo");

        // Now add some text to the email.
        // First we create a MimeText object.

        MimeText text;

        text.setText(content);

        // Now add it to the mail

        message.addPart(&text);

        // Now we can send the mail

        smtp.connectToHost();
        smtp.login();
        smtp.sendMail(message);
        smtp.quit();*/
}




void MainWindow::on_arduino_clicked()
{
    QString id=ui->id_arduino->text();


    QString Commande = C.affichage(id);

    qDebug() << Commande;
    /*A.write_to_arduino(id);
    */
    A.write_to_arduino("ID : "+id.toUtf8());
    A.write_to_arduino(" ");
    A.write_to_arduino(Commande.toUtf8());
}

