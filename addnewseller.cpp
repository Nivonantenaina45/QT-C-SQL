#include "addnewseller.h"
#include "ui_addnewseller.h"
#include<QFileDialog>
#include<QFile>
#include<QMessageBox>
#include<QSqlQuery>
#include"mainwindow.h"
#include"sellertable.h"
QString path_seller_picture;

AddNewSeller::AddNewSeller(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::AddNewSeller)
{
    ui->setupUi(this);
    ui->label_picture_seller->setPixmap(QPixmap(":picture/new-arrival.png").scaledToHeight(300).scaledToWidth(300));
}

AddNewSeller::~AddNewSeller()
{
    delete ui;
}

void AddNewSeller::on_pushButton_upload_seller_picture_clicked()
{
    path_seller_picture = QFileDialog::getOpenFileName(this,"Upload Seller picture",QDir::currentPath(),"Pictures files(*.png *.jpg)");
    qDebug()<<path_seller_picture;

    QPixmap targetPixmap = QPixmap(path_seller_picture);
    qDebug()<<targetPixmap;
    ui->label_picture_seller->setPixmap(targetPixmap.scaledToHeight(300).scaledToWidth(300));

}


void AddNewSeller::on_pushButton_save_seller_clicked()
{
    QByteArray byte;

    QFile file(path_seller_picture);
    if(file.open(QIODevice::ReadOnly)){
        byte= file.readAll();

        file.close();
    }

    QString name = ui->lineEdit_seller_name->text();
    QString phone = ui->lineEdit_seller_phone->text();
    QString email = ui->lineEdit_seller_email->text();
    QString address = ui->lineEdit_seller_adress->text();

    if(name==""||phone==""||email==""||address==""){

        QMessageBox::critical(this,"Input Erorr","input fields can not be empty !");
        return;
    }else{

        QSqlQuery query;

        query.prepare("INSERT INTO seller(name,phone,email,address,picture)VALUES(?,?,?,?,?)");
        query.addBindValue(name);
        query.addBindValue(phone);
        query.addBindValue(email);
        query.addBindValue(address);
        query.addBindValue(byte);

        if(query.exec()){
            QMessageBox::information(this,"Success","file has been inserted !");

            //TODO
            this->close();
            SellerTable *ST = new SellerTable();
            ST->show();
        }else{
            QMessageBox::critical(this,"Erorr","file has not been inserted !");
        }
    }

}


void AddNewSeller::on_pushButton_home_page_seller_clicked()
{
    this->close();

    MainWindow *MW = new MainWindow();
    MW->show();

}

