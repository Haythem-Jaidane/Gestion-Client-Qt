#include "mainwindow1.h"
#include "ui_mainwindow1.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow1::MainWindow1(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow1)
{
    ui->setupUi(this);;
}

MainWindow1::~MainWindow1()
{
    delete ui;
}

void MainWindow1::on_connecter_clicked()
{
    MainWindow w;
    w.show();}

