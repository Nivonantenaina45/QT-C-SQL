#include "vehicletable.h"
#include "ui_vehicletable.h"
#include<QSqlQueryModel>
#include<QSqlQuery>
#include<QFileDialog>
#include<QFile>
#include<QMessageBox>
#include<QSqlQuery>
#include"mainwindow.h"
#include<QDebug>


QString vehicle_id,path_Update_vehicle;

VehicleTable::VehicleTable(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::VehicleTable)
{
    ui->setupUi(this);
    QSqlQueryModel *tableModel = new QSqlQueryModel();

    tableModel->setQuery("SELECT id,name,manufacturer,construction_year,km_stood,condition,pieces,price,currency,availability FROM vehicle");


    tableModel->setHeaderData(0,Qt::Horizontal,"ID");
    tableModel->setHeaderData(1,Qt::Horizontal,"Name");
    tableModel->setHeaderData(2,Qt::Horizontal,"Manufacturer");
    tableModel->setHeaderData(3,Qt::Horizontal,"Construction year");
    tableModel->setHeaderData(4,Qt::Horizontal,"Km stood");
    tableModel->setHeaderData(5,Qt::Horizontal,"Condition");
    tableModel->setHeaderData(6,Qt::Horizontal,"Pieces");
    tableModel->setHeaderData(7,Qt::Horizontal,"Price");
    tableModel->setHeaderData(8,Qt::Horizontal,"Currency");
    tableModel->setHeaderData(9,Qt::Horizontal,"Availability");

    QFont font("Arial",12,QFont::Bold);
    ui->tableView_vehicle->horizontalHeader()->setFont(font);
    ui->tableView_vehicle->setModel(tableModel);

}

VehicleTable::~VehicleTable()
{
    delete ui;
}

void VehicleTable::on_tableView_vehicle_clicked(const QModelIndex &index)
{
    vehicle_id = ui->tableView_vehicle->model()->index(index.row(),0).data().toString();
    ui->label_id->setText("Selected Vehicle ID " + vehicle_id);

    QSqlQuery query;

    query.prepare("SELECT * FROM vehicle WHERE id = '"+vehicle_id+"'");


    if(query.exec()){

        while(query.next()){
            ui->lineEdit_id->setText(query.value(0).toString());
            ui->lineEdit_name->setText(query.value(1).toString());
            ui->lineEdit_manufacturer->setText(query.value(2).toString());
            ui->lineEdit_construction_year->setText(query.value(3).toString());
            //ui->lineEdit_kmStood->setText(query.value(4).toString());
            double kmStood = query.value(4).toDouble();
            ui->lineEdit_km_stood->setText(QString::number(kmStood,'f',3));

            ui->lineEdit_condition->setText(query.value(5).toString());
            ui->lineEdit_pieces->setText(query.value(6).toString());
            // ui->lineEdit_price->setText(query.value(7).toString());
            double price = query.value(7).toDouble();
            ui->lineEdit_price->setText(QString::number(price,'f',3));

            ui->lineEdit_currency->setText(query.value(8).toString());
            ui->lineEdit_availability->setText(query.value(9).toString());

            QByteArray byte = query.value(10).toByteArray();

            QPixmap pixmap =QPixmap();
            pixmap.loadFromData(byte);

            ui->label_picture->setPixmap(pixmap.scaledToHeight(600).scaledToWidth(600));

        }

     }

}

void VehicleTable::on_pushButton_upload_picture_clicked()
{
    path_Update_vehicle = QFileDialog::getOpenFileName(this,"Upload Vehicle picture",QDir::currentPath(),"Pictures files(*.png *.jpg)");
    qDebug()<<path_Update_vehicle;

    QPixmap targetPixmap = QPixmap(path_Update_vehicle);
    qDebug()<<targetPixmap;
    ui->label_picture->setPixmap(targetPixmap.scaledToHeight(600).scaledToWidth(600));
}

void VehicleTable::on_pushButton_update_picture_clicked()
{

    QByteArray byte;

    QFile file( path_Update_vehicle);
    if(file.open(QIODevice::ReadOnly)){
        byte= file.readAll();

        file.close();
    }

    QSqlQuery query;

    query.prepare("UPDATE vehicle SET picture =? WHERE id = '"+vehicle_id+"'");
    query.addBindValue(byte);

    if(query.exec()){

        QMessageBox::information(this,"Success","Vehicle picture has been updated !");





    }else{
        QMessageBox::critical(this,"Erorr","Vehicle picture has not been updated !");
    }


}

void VehicleTable::on_pushButton_update_data_clicked()
{
    QString name = ui->lineEdit_name->text();
    QString manufacturer = ui->lineEdit_manufacturer->text();
    QString construction_year = ui->lineEdit_construction_year->text();
    double kmStood = ui->lineEdit_km_stood->text().toDouble();
    QString condition = ui->lineEdit_condition->text();
    int pieces = ui->lineEdit_pieces->text().toInt();
    double price = ui->lineEdit_price->text().toDouble();
    QString currency = ui->lineEdit_currency->text();
    QString availability = ui->lineEdit_availability->text();

    QSqlQuery query;

    query.prepare("UPDATE vehicle SET name=?,manufacturer=?,construction_year=?,km_stood=?,condition=?,pieces=?,price=?,currency=?,availability=? WHERE id='"+vehicle_id+"'");
    query.addBindValue(name);
    query.addBindValue(manufacturer);
    query.addBindValue(construction_year);
    query.addBindValue(kmStood);
    query.addBindValue(condition);
    query.addBindValue(pieces);
    query.addBindValue(price);
    query.addBindValue(currency);
    query.addBindValue(availability);

    if(query.exec()){
        QMessageBox::information(this,"Success","Vehicle Data has been updated !");
        this->close();
        MainWindow *MW = new MainWindow();
        MW->show();

    }else{
        QMessageBox::critical(this,"Erorr","Vehicle Data has not been updated !");
    }

}


void VehicleTable::on_pushButton_delete_data_clicked()
{
    QMessageBox *msgBox = new QMessageBox();

    msgBox->setWindowTitle("Question");
    msgBox->setIcon(QMessageBox::Question);
    msgBox->setWindowIcon(QIcon(":picture/Chevorlet.png"));
    msgBox->setText("Are you sure ? do you relly want to delete this Vehicle !");

    QPushButton *button_yes, *button_no;
    button_yes = msgBox->addButton(QMessageBox::Yes);
    button_no = msgBox->addButton(QMessageBox::No);

    msgBox->exec();

    if(msgBox->clickedButton()==button_no){
        return;
    }if(msgBox->clickedButton()==button_yes){
        QSqlQuery query;
        query.prepare("DELETE FROM vehicle WHERE id = '"+vehicle_id+"'");

        if(query.exec()){
            QMessageBox::information(this,"Success","Vehicle Data has been deleted !");
            this->close();
            MainWindow *MW = new MainWindow();
            MW->show();

        }else{
            QMessageBox::critical(this,"Erorr","Vehicle Data has not been deleted !");
        }
    }

}


void VehicleTable::on_pushButton_homePage_clicked()
{
    this->close();
    MainWindow *MW = new MainWindow();
    MW->show();

}

