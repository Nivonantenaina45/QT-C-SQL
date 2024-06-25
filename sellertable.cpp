#include "sellertable.h"
#include "ui_sellertable.h"
#include "qsqlquery.h"
#include<QSqlQueryModel>
#include<QFileDialog>
#include<QFile>
#include<QMessageBox>
#include "mainwindow.h"

QString seller_id, path_update_seller_picture;

SellerTable::SellerTable(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SellerTable)
{
    ui->setupUi(this);
    QSqlQueryModel *tableModel = new QSqlQueryModel();

    tableModel->setQuery("SELECT id,name,phone,email,address FROM seller");


    tableModel->setHeaderData(0,Qt::Horizontal,"ID");
    tableModel->setHeaderData(1,Qt::Horizontal,"Name");
    tableModel->setHeaderData(2,Qt::Horizontal,"Phone");
    tableModel->setHeaderData(3,Qt::Horizontal,"E-Mail");
    tableModel->setHeaderData(4,Qt::Horizontal,"Address");


    QFont font("Arial",12,QFont::Bold);
    ui->tableView_seller->horizontalHeader()->setFont(font);
    ui->tableView_seller->setModel(tableModel);
}



SellerTable::~SellerTable()
{
    delete ui;
}

void SellerTable::on_tableView_seller_clicked(const QModelIndex &index)
{
    seller_id = ui->tableView_seller->model()->index(index.row(),0).data().toString();
    ui->label_id->setText("Selected Seller ID :  " + seller_id);

    QSqlQuery query;

    query.prepare("SELECT * FROM seller WHERE id = '"+seller_id+"'" );

    if(query.exec()){
        while(query.next()){
            ui->lineEdit_id->setText(query.value(0).toString());
            ui->lineEdit_name->setText(query.value(1).toString());
            ui->lineEdit_phone->setText(query.value(2).toString());
            ui->lineEdit_email->setText(query.value(3).toString());
            ui->lineEdit_address->setText(query.value(4).toString());

            QByteArray byte;
            byte = query.value(5).toByteArray();

            QPixmap pixmap = QPixmap();
            pixmap.loadFromData(byte);

            ui->label_picture->setPixmap(pixmap.scaledToHeight(400).scaledToWidth(150));

        }

    }

}

void SellerTable::on_pushButton_upload_picture_clicked()
{
    path_update_seller_picture = QFileDialog::getOpenFileName(this,"Upload Seller picture",QDir::currentPath(),"Pictures files(*.png *.jpg)");
    qDebug()<< path_update_seller_picture;

    QPixmap targetPixmap = QPixmap( path_update_seller_picture);
    qDebug()<<targetPixmap;
    ui->label_picture->setPixmap(targetPixmap.scaledToHeight(300).scaledToWidth(150));

}


void SellerTable::on_pushButton_update_picture_clicked()
{
    QByteArray byte;

    QFile file( path_update_seller_picture);
    if(file.open(QIODevice::ReadOnly)){
        byte= file.readAll();

        file.close();
    }

    QSqlQuery query;

    query.prepare("UPDATE seller SET picture=?  WHERE id = '"+seller_id+"'");

    query.addBindValue(byte);
    if(query.exec()){

        QMessageBox::information(this, "Success","Seller Picture has been Updated !");

    }else{

        QMessageBox::critical(this, "Erorr","Seller Picture has not been Updated !");
    }

}


void SellerTable::on_pushButton_update_data_clicked()
{
    QString name = ui->lineEdit_name->text();
    QString phone = ui->lineEdit_phone->text();
    QString email = ui->lineEdit_email->text();
    QString address = ui->lineEdit_address->text();

    QSqlQuery query;

    query.prepare("UPDATE seller SET name=?,phone=?,email=?,address=?  WHERE id = '"+seller_id+"'");
    query.addBindValue(name);
    query.addBindValue(phone);
    query.addBindValue(email);
    query.addBindValue(address);

    if(query.exec()){
        QMessageBox::information(this, "Success","Seller Data has been Updated !");
        this->close();

        MainWindow *MW = new MainWindow();

        MW->show();
    }else{

        QMessageBox::critical(this, "Erorr","Seller Data has not been Updated !");
    }


}


void SellerTable::on_pushButton_delete_data_clicked()
{
    QMessageBox *msgBox = new QMessageBox();

    msgBox->setWindowTitle("Question");
    msgBox->setIcon(QMessageBox::Question);
    msgBox->setWindowIcon(QIcon(":picture/new-arrival.png"));
    msgBox->setText("Are you sure ? do you relly want to delete this Seller !");

    QPushButton *button_yes, *button_no;
    button_yes = msgBox->addButton(QMessageBox::Yes);
    button_no = msgBox->addButton(QMessageBox::No);

    msgBox->exec();

    if(msgBox->clickedButton()==button_no){
        return;
    }if(msgBox->clickedButton()==button_yes){
        QSqlQuery query;
        query.prepare("DELETE FROM seller WHERE id = '"+seller_id+"'");

        if(query.exec()){
            QMessageBox::information(this,"Success","Seller Data has been deleted !");
            this->close();
            MainWindow *MW = new MainWindow();
            MW->show();

        }else{
            QMessageBox::critical(this,"Erorr","Seller Data has not been deleted !");
        }
    }

}


void SellerTable::on_pushButton_homePage_clicked()
{
    this->close();
    MainWindow *MW = new MainWindow();
    MW->show();

}




