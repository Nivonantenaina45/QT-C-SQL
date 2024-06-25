#include "sale.h"
#include "ui_sale.h"
#include<QSqlQuery>
#include<QDebug>
#include<QMessageBox>
#include"mainwindow.h"


QString vehicle_name_sale, vehicle_id_sale,customer_id_sale, customer_name_sale,seller_id_sale,seller_name_sale,
    selected_vehicle_name, hidden_vehicle_id,selected_customer_name,hidden_customer_id,selected_seller_name, hidden_seller_id,
    selection_date_day,selection_date_month,input_date_year,currency;

int i, selected_vehicle_pieces,selection_number_of_vehicles_sold,new_vehicle_pieces,
    sold_vehicle_id,sold_customer_id,sold_seller_id;

double price, totalprice;

Sale::Sale(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Sale)
{
    ui->setupUi(this);
    ui->label_picture_bussiness->setPixmap(QPixmap(":picture/buy.png").scaledToHeight(150).scaledToWidth(150));
    ui->label_picture_deal->setPixmap(QPixmap(":picture/deal.png").scaledToHeight(150).scaledToWidth(150));

    QSqlQuery query_vehicle;
    query_vehicle.prepare("SELECT id,name FROM vehicle WHERE availability = 'available'");

    if(query_vehicle.exec()){

        while(query_vehicle.next()){
            vehicle_id_sale = query_vehicle.value(0).toString();
            vehicle_name_sale=query_vehicle.value(1).toString();

            ui->comboBox_vehicle_name->addItem(vehicle_name_sale,vehicle_id_sale);
        }
    }

    QSqlQuery query_customer;

    query_customer.prepare("SELECT id,name FROM customer");

    if(query_customer.exec()){

        while(query_customer.next()){
            customer_id_sale = query_customer.value(0).toString();
            customer_name_sale = query_customer.value(1).toString();

            ui->comboBox_customer_name->addItem(customer_name_sale, customer_id_sale);
        }
    }

    QSqlQuery query_seller;

    query_seller.prepare("SELECT id,name FROM seller");

    if(query_seller.exec()){
        while(query_seller.next()){

            seller_id_sale = query_seller.value(0).toString();
            seller_name_sale = query_seller.value(1).toString();

            ui->comboBox_seller_name->addItem(seller_name_sale,seller_id_sale);


        }
    }

}

Sale::~Sale()
{
    delete ui;
}



void Sale::on_pushButton_submit_clicked()
{
    selected_customer_name = ui->comboBox_customer_name->currentText();
    hidden_customer_id = ui->comboBox_customer_name->currentData().toString();

    selected_seller_name= ui->comboBox_seller_name->currentText();
    hidden_seller_id= ui->comboBox_seller_name->currentData().toString();

    selection_number_of_vehicles_sold = ui->comboBox_number_of_vehicles->currentText().toInt();
    selection_date_day = ui->comboBox_date_day->currentText();
    selection_date_month=ui->comboBox_date_month->currentText();
    input_date_year = ui->lineEdit_date_year->text();

    QSqlQuery query;
    query.prepare("SELECT price, currency FROM vehicle WHERE id = '"+hidden_vehicle_id+"'");

    if(query.exec()){

        while(query.next()){
            price = query.value(0).toDouble();
            currency= query.value(1).toString();
        }
    }

    if(input_date_year==""){
        QMessageBox::critical(this,"Input Erorr","input fields can not be empty !");
        return;
    }else{

        totalprice = selection_number_of_vehicles_sold * price;


        ui->label_vehicle_name->setText(selected_vehicle_name);
        ui->label_customer_name->setText(selected_customer_name);
        ui->label_seller_name->setText(selected_seller_name);
        ui->label_number_of_vehicle->setText(QString::number(selection_number_of_vehicles_sold));
        ui->label_sale_date->setText(selection_date_day +'.'+selection_date_month+'.'+input_date_year);
        ui->label_total_sale->setText(QString::number(totalprice,'f',3)+' '+currency);


    }

}




void Sale::on_pushButton_confirm_clicked()
{
    QString vehicle_name = ui->label_vehicle_name->text();
    QString customer_name = ui->label_customer_name->text();
    QString seller_name = ui->label_seller_name->text();
    QString number_of_sold_vehicle = ui->label_number_of_vehicle->text();
    QString date = ui->label_sale_date->text();
    QString total_sales = ui->label_total_sale->text();
    if(vehicle_name==""||customer_name==""||seller_name==""||number_of_sold_vehicle==""||date==""||total_sales==""){

        QMessageBox::critical(this,"Erorr","There is no data available !");
        return;
    }else{
        if(selection_number_of_vehicles_sold < selected_vehicle_pieces){
            new_vehicle_pieces = selected_vehicle_pieces - selection_number_of_vehicles_sold;

            qDebug()<<"new_vehicle_pieces:  "<<new_vehicle_pieces;

            QSqlQuery query;

            query.prepare("UPDATE vehicle SET pieces=? WHERE id = '"+hidden_vehicle_id+"'");
            query.addBindValue(new_vehicle_pieces);
            query.exec();

        } if(selection_number_of_vehicles_sold == selected_vehicle_pieces){
            new_vehicle_pieces = selected_vehicle_pieces - selection_number_of_vehicles_sold;

            qDebug()<<"new_vehicle_pieces:  "<<new_vehicle_pieces;

            QSqlQuery query;

            query.prepare("UPDATE vehicle SET pieces=?,availability='not available' WHERE id = '"+hidden_vehicle_id+"'");
            query.addBindValue(new_vehicle_pieces);
            query.exec();

        }

    }

    sold_vehicle_id = hidden_vehicle_id.toInt();
    sold_customer_id = hidden_customer_id.toInt();
    sold_seller_id = hidden_seller_id.toInt();

    /*selection_number_of_vehicles_sold;
    selection_date_day;
    selection_date_month;
    input_date_year;
    totalprice;
    currency;
    selected_seller_name;
    selected_customer_name;*/

    QSqlQuery query_sale;

    query_sale.prepare("INSERT INTO sale(sold_vehicle_id,sold_customer_id,sold_seller_id,sold_vehicle_count,sold_day,sold_month,sold_year,sold_total_price,currency,seller_name,customer_name)VALUES(?,?,?,?,?,?,?,?,?,?,?)");
    query_sale.addBindValue(sold_vehicle_id);
    query_sale.addBindValue(sold_customer_id);
    query_sale.addBindValue(sold_seller_id);
    query_sale.addBindValue(selection_number_of_vehicles_sold);
    query_sale.addBindValue(selection_date_day);
    query_sale.addBindValue(selection_date_month);
    query_sale.addBindValue(input_date_year);
    query_sale.addBindValue(totalprice);
    query_sale.addBindValue(currency);
    query_sale.addBindValue(selected_seller_name);
    query_sale.addBindValue(selected_customer_name);

    if(query_sale.exec()){

        QMessageBox::information(this,"Success","File has been added !");
        this->close();
        Sale *SA = new Sale();
        SA->show();
    }else{
        QMessageBox::critical(this,"Erorr","File has not been added !");
    }

}


void Sale::on_pushButton_home_page_clicked()
{
    this->close();
    MainWindow *MW = new MainWindow();
    MW->show();

}


void Sale::on_comboBox_vehicle_name_currentIndexChanged(int /*index*/)
{
    ui->comboBox_number_of_vehicles->clear();

    selected_vehicle_name= ui->comboBox_vehicle_name->currentText();
    qDebug()<<selected_vehicle_name;
    hidden_vehicle_id = ui->comboBox_vehicle_name->currentData().toString();
    qDebug()<<hidden_vehicle_id;

    QSqlQuery query;

    query.prepare("SELECT pieces FROM vehicle WHERE id = '"+hidden_vehicle_id+"'");

    if(query.exec()){

        while(query.next()){

            selected_vehicle_pieces= query.value(0).toInt();
            qDebug()<<selected_vehicle_pieces;
        }
    }

    for(i=1;i<=selected_vehicle_pieces;i++){
        qDebug()<<i;

        ui->comboBox_number_of_vehicles->addItem(QString::number(i));
    }

}

