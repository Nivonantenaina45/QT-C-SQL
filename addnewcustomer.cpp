#include "addnewcustomer.h"
#include "ui_addnewcustomer.h"
#include<QMessageBox>
#include<QSqlQuery>
#include"mainwindow.h"
#include"customertable.h"

AddNewCustomer::AddNewCustomer(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::AddNewCustomer)
{
    ui->setupUi(this);
    ui->label_picture->setPixmap(QPixmap(":picture/add-user.png").scaledToHeight(350).scaledToWidth(300));
}


AddNewCustomer::~AddNewCustomer()
{
    delete ui;
}

void AddNewCustomer::on_pushButton_save_clicked()
{
    QString name = ui->lineEdit_name->text();
    QString phone = ui->lineEdit_phone->text();
    QString email = ui->lineEdit_email->text();
    QString address = ui->lineEdit_adress->text();



    if(name==""||phone==""||email==""||address==""){

        QMessageBox::critical(this,"Erorr","Input fields can not be empty !");
        return;
    }else{
        QSqlQuery query;

        query.prepare("INSERT INTO customer(name,phone,email,address)VALUES(?,?,?,?)");
        query.addBindValue(name);
        query.addBindValue(phone);
        query.addBindValue(email);
        query.addBindValue(address);

        if(query.exec()){
            QMessageBox::information(this, "Success","Customer has been inserted !");
            //TODO

            this->close();
            CustomerTable *CT = new CustomerTable();
            CT->show();

        }else{
            QMessageBox::critical(this, "Erorr","Customer has not been inserted !");
        }


    }


}


void AddNewCustomer::on_pushButton_home_page_clicked()
{
    this->close();

    MainWindow *MW = new MainWindow();
    MW->show();

}

