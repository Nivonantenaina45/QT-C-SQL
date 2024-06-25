#include "addnewvehicle.h"
#include "ui_addnewvehicle.h"
#include<QFile>
#include<QFileDialog>
#include<QDebug>
#include<QMessageBox>
#include<QSqlQuery>
#include"mainwindow.h"
#include"vehicletable.h"


QString path;

AddNewVehicle::AddNewVehicle(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::AddNewVehicle)
{
    ui->setupUi(this);
    ui->label_picture->setPixmap(QPixmap(":picture/Chevorlet.png").scaledToHeight(600).scaledToWidth(600));
}

AddNewVehicle::~AddNewVehicle()
{
    delete ui;
}

void AddNewVehicle::on_pushButton_upload_vehicle_pictures_clicked()
{
    path = QFileDialog::getOpenFileName(this,"Upload Vehicle picture",QDir::currentPath(),"Pictures files(*.png *.jpg)");
    qDebug()<<path;

    QPixmap targetPixmap = QPixmap(path);
    qDebug()<<targetPixmap;
    ui->label_picture->setPixmap(targetPixmap.scaledToHeight(600).scaledToWidth(600));


}

void AddNewVehicle::on_pushButton_save_clicked()
{
    QByteArray byte;

    QFile file(path);
    if(file.open(QIODevice::ReadOnly)){
        byte= file.readAll();

        file.close();
    }

    QString name = ui->lineEdit_name->text();
    QString manufacturer = ui->lineEdit_manufacturer->text();
    QString construction_year = ui->lineEdit_construction_year->text();
    double kmStood = ui->lineEdit_km_stood->text().toDouble();
    QString condition = ui->comboBox_condition->currentText();
    int pieces = ui->lineEdit_number_of_pieces->text().toInt();
    double price = ui->lineEdit_price->text().toDouble();
    QString currency = ui->comboBox_currency->currentText();

    if(name==""||manufacturer==""||construction_year==""||condition==""||pieces==0||price==0||currency==""){
        QMessageBox::critical(this,"Input Erorr","input or selection fields can not be empty !");
        return;
    }else{
        QSqlQuery query;

        query.prepare("INSERT INTO vehicle(name,manufacturer,construction_year,km_stood,condition,pieces,price,currency,picture)VALUES(?,?,?,?,?,?,?,?,?)");
        query.addBindValue(name);
        query.addBindValue(manufacturer);
        query.addBindValue(construction_year);
        query.addBindValue(kmStood);
        query.addBindValue(condition);
        query.addBindValue(pieces);
        query.addBindValue(price);
        query.addBindValue(currency);
        query.addBindValue(byte);

        if(query.exec()){
            QMessageBox::information(this,"Success","File has been inserted");

            //TODO
            this->close();

            VehicleTable *VT = new VehicleTable();
            VT->show();


        }else{
            QMessageBox::critical(this,"Erorr","File has not been inserted");
        }
    }

}



void AddNewVehicle::on_pushButton_home_page_clicked()
{

    this->close();

    MainWindow *MW = new MainWindow();
    MW->show();

}

