#include "statisticscustomerperyear.h"
#include "ui_statisticscustomerperyear.h"

#include<QSqlQuery>
#include<QMessageBox>
#include"mainwindow.h"


Statisticscustomerperyear::Statisticscustomerperyear(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Statisticscustomerperyear)
{
    ui->setupUi(this);
    ui->label_picture->setPixmap(QPixmap(":picture/money.png").scaledToWidth(400).scaledToHeight(250));

    QSqlQuery query;

    query.prepare("SELECT name FROM customer");
    if(query.exec()){

        while(query.next()){

            QString name = query.value(0).toString();
            ui->comboBox_customer_name->addItem(name);
        }
    }
}


Statisticscustomerperyear::~Statisticscustomerperyear()
{
    delete ui;
}


void Statisticscustomerperyear::on_pushButton_statisticscustomerpermonth_clicked()
{
    QString name = ui->comboBox_customer_name->currentText();
    QString year = ui->lineEdit_date_year->text();

    if(year ==""){

        QMessageBox::critical(this,"Input Erorr","input fielde can not be empty !");
        return;
    }else{

        QSqlQuery query;
        query.prepare("SELECT customer_name,currency,sold_year, SUM(sold_vehicle_count),SUM(sold_total_price)FROM sale WHERE customer_name ='"+name+"' and  sold_year = '"+year+"'");
        if(query.exec()){
            while(query.next()) {
                QString result_seller_name = query.value(0).toString();
                qDebug()<<result_seller_name;

                QString result_currency = query.value(1).toString();
                qDebug()<<result_currency;

                QString result_year = query.value(2).toString();
                qDebug()<<result_year;
                int result_sum_count_vehicle = query.value(3).toInt();
                qDebug()<<result_sum_count_vehicle;
                double result_sum_total_sales = query.value(4).toDouble();
                qDebug()<<result_sum_total_sales;


                if(result_seller_name=="" && result_currency==""&&result_year==""&&result_sum_count_vehicle==0&&result_sum_total_sales==0){
                    QMessageBox::information(this,"Info","Customer has not bought Vehicles in this year !");
                    ui->label_customer_name->setText("");
                    ui->label_year->setText("");
                    ui->label_vehicles_count->setText("");
                    ui->label_total_sale->setText("");
                }else{
                    ui->label_customer_name->setText(result_seller_name);
                    ui->label_year->setText(result_year);
                    ui->label_vehicles_count->setText(QString::number(result_sum_count_vehicle));
                    ui->label_total_sale->setText(QString::number(result_sum_total_sales,'f',3) + ' ' + result_currency);

                }

            }

        }

    }

}


void Statisticscustomerperyear::on_pushButton_home_page_clicked()
{
    this->close();
    MainWindow *MW = new MainWindow();
    MW->show();

}

