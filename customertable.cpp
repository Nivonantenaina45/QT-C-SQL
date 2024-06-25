#include "customertable.h"
#include "ui_customertable.h"
#include "qsqlquery.h"
#include<QSqlQueryModel>
#include<QMessageBox>
#include"mainwindow.h"
QString customer_id;


CustomerTable::CustomerTable(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::CustomerTable)
{
    ui->setupUi(this);
    QSqlQueryModel *tableModel = new QSqlQueryModel();

    tableModel->setQuery("SELECT id,name,phone,email,address FROM customer");


    tableModel->setHeaderData(0,Qt::Horizontal,"ID");
    tableModel->setHeaderData(1,Qt::Horizontal,"Name");
    tableModel->setHeaderData(2,Qt::Horizontal,"Phone");
    tableModel->setHeaderData(3,Qt::Horizontal,"E-Mail");
    tableModel->setHeaderData(4,Qt::Horizontal,"Address");


    QFont font("Arial",12,QFont::Bold);
    ui->tableView_customer->horizontalHeader()->setFont(font);
    ui->tableView_customer->setModel(tableModel);

}

CustomerTable::~CustomerTable()
{
    delete ui;
}

void CustomerTable::on_tableView_customer_clicked(const QModelIndex &index)
{
    customer_id = ui->tableView_customer->model()->index(index.row(),0).data().toString();
    ui->label_id->setText("Selected Customer ID : " +customer_id);

    QSqlQuery query;

    query.prepare(" SELECT * FROM customer WHERE id = '"+customer_id+"'");
    if(query.exec()){
        while(query.next()){

            ui->lineEdit_id->setText(query.value(0).toString());
            ui->lineEdit_name->setText(query.value(1).toString());
            ui->lineEdit_phone->setText(query.value(2).toString());
            ui->lineEdit_email->setText(query.value(3).toString());
            ui->lineEdit_address->setText(query.value(4).toString());


        }

    }

}


void CustomerTable::on_pushButton_update_data_clicked()
{
    QString name = ui->lineEdit_name->text();
    QString phone = ui->lineEdit_phone->text();
    QString email = ui->lineEdit_email->text();
    QString address = ui->lineEdit_address->text();

    QSqlQuery query;

    query.prepare("UPDATE customer SET name=?,phone=?,email=?,address=?  WHERE id = '"+customer_id+"'");
    query.addBindValue(name);
    query.addBindValue(phone);
    query.addBindValue(email);
    query.addBindValue(address);

    if(query.exec()){
        QMessageBox::information(this, "Success","Customer Data has been Updated !");
        this->close();

        MainWindow *MW = new MainWindow();

        MW->show();
    }else{

        QMessageBox::critical(this, "Erorr","Customer Data has not been Updated !");
    }

}


void CustomerTable::on_pushButton_delete_data_clicked()
{
    QMessageBox *msgBox = new QMessageBox();

    msgBox->setWindowTitle("Question");
    msgBox->setIcon(QMessageBox::Question);
    msgBox->setWindowIcon(QIcon(":picture/add-user.png"));
    msgBox->setText("Are you sure ? do you relly want to delete this Customer !");

    QPushButton *button_yes, *button_no;
    button_yes = msgBox->addButton(QMessageBox::Yes);
    button_no = msgBox->addButton(QMessageBox::No);

    msgBox->exec();

    if(msgBox->clickedButton()==button_no){
        return;
    }if(msgBox->clickedButton()==button_yes){
        QSqlQuery query;
        query.prepare("DELETE FROM customer WHERE id = '"+customer_id+"'");

        if(query.exec()){
            QMessageBox::information(this,"Success","Customer Data has been deleted !");
            this->close();
            MainWindow *MW = new MainWindow();
            MW->show();

        }else{
            QMessageBox::critical(this,"Erorr","Customer Data has not been deleted !");
        }
    }


}


void CustomerTable::on_pushButton_homePage_clicked()
{
    this->close();
    MainWindow *MW = new MainWindow();
    MW->show();

}

