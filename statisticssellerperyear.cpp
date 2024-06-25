#include "statisticssellerperyear.h"
#include "ui_statisticssellerperyear.h"
#include<QSqlQuery>
#include<QMessageBox>
#include"mainwindow.h"

Statisticssellerperyear::Statisticssellerperyear(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Statisticssellerperyear)
{
    ui->setupUi(this);
    ui->label_picture->setPixmap(QPixmap(":picture/confirm.png").scaledToWidth(400).scaledToHeight(250));

    QSqlQuery query;

    query.prepare("SELECT name FROM seller");
    if(query.exec()){

        while(query.next()){

            QString name = query.value(0).toString();
            ui->comboBox_seller_name->addItem(name);
        }
    }


}

Statisticssellerperyear::~Statisticssellerperyear()
{
    delete ui;
}

void Statisticssellerperyear::on_pushButton_statisticssellerpermonth_clicked()
{
    QString name = ui->comboBox_seller_name->currentText();
    QString year = ui->lineEdit_date_year->text();

    if(year ==""){

        QMessageBox::critical(this,"Input Erorr","input fielde can not be empty !");
        return;
    }else{

        QSqlQuery query;
        query.prepare("SELECT seller_name,currency,sold_year, SUM(sold_vehicle_count),SUM(sold_total_price)FROM sale WHERE seller_name ='"+name+"' and  sold_year = '"+year+"'");
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
                    QMessageBox::information(this,"Info","Seller has not sold Vehicles in this year !");
                    ui->label_seller_name->setText("");
                    ui->label_month_year->setText("");
                    ui->label_vehicles_count->setText("");
                    ui->label_total_sale->setText("");
                }else{
                    ui->label_seller_name->setText(result_seller_name);
                    ui->label_month_year->setText(result_year);
                    ui->label_vehicles_count->setText(QString::number(result_sum_count_vehicle));
                    ui->label_total_sale->setText(QString::number(result_sum_total_sales,'f',3) + ' ' + result_currency);

                }

            }

        }

    }

}



void Statisticssellerperyear::on_pushButton_home_page_clicked()
{
    this->close();
    MainWindow *MW = new MainWindow();
    MW->show();

}

