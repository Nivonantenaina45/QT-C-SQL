#include "statisticscardealerperyear.h"
#include "ui_statisticscardealerperyear.h"
#include<QMessageBox>
#include<QSqlQuery>
#include"mainwindow.h"


Statisticscardealerperyear::Statisticscardealerperyear(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Statisticscardealerperyear)
{
    ui->setupUi(this);
    ui->label_picture->setPixmap(QPixmap(":picture/product.png").scaledToWidth(400).scaledToHeight(250));
}

Statisticscardealerperyear::~Statisticscardealerperyear()
{
    delete ui;
}

void Statisticscardealerperyear::on_pushButton_statisticssellerpermonth_clicked()
{
    QString year = ui->lineEdit_date_year->text();

    if(year ==""){

        QMessageBox::critical(this,"Input Erorr","input fielde can not be empty !");
        return;
    }else{

        QSqlQuery query;
        query.prepare("SELECT currency,sold_year, SUM(sold_vehicle_count),SUM(sold_total_price)FROM sale WHERE   sold_year = '"+year+"'");
        if(query.exec()){
            while(query.next()) {


                QString result_currency = query.value(0).toString();
                qDebug()<<result_currency;
                QString result_year = query.value(1).toString();
                qDebug()<<result_year;
                int result_sum_count_vehicle = query.value(2).toInt();
                qDebug()<<result_sum_count_vehicle;
                double result_sum_total_sales = query.value(3).toDouble();
                qDebug()<<result_sum_total_sales;


                if( result_currency==""&&result_year==""&&result_sum_count_vehicle==0&&result_sum_total_sales==0){
                    QMessageBox::information(this,"Info","no sold Vehicles in this year !");

                    ui->label_month_year->setText("");
                    ui->label_vehicles_count->setText("");
                    ui->label_total_sale->setText("");
                }else{

                    ui->label_month_year->setText(result_year);
                    ui->label_vehicles_count->setText(QString::number(result_sum_count_vehicle));
                    ui->label_total_sale->setText(QString::number(result_sum_total_sales,'f',3) + ' ' + result_currency);

                }

            }

        }

    }

}


void Statisticscardealerperyear::on_pushButton_home_page_clicked()
{
    this->close();
    MainWindow *MW = new MainWindow();
    MW->show();

}

