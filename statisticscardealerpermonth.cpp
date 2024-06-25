#include "statisticscardealerpermonth.h"
#include "ui_statisticscardealerpermonth.h"
#include<QMessageBox>
#include<QSqlQuery>
#include"mainwindow.h"


Statisticscardealerpermonth::Statisticscardealerpermonth(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Statisticscardealerpermonth)
{
    ui->setupUi(this);
    ui->label_picture->setPixmap(QPixmap(":picture/folder.png").scaledToWidth(400).scaledToHeight(250));
}

Statisticscardealerpermonth::~Statisticscardealerpermonth()
{
    delete ui;
}

void Statisticscardealerpermonth::on_pushButton_statisticssellerpermonth_clicked()
{
    QString month = ui->comboBox_date_month->currentText();
    QString year = ui->lineEdit_date_year->text();

    if(year ==""){

        QMessageBox::critical(this,"Input Erorr","input fielde can not be empty !");
        return;
    }else{

        QSqlQuery query;
        query.prepare("SELECT currency,sold_month,sold_year, SUM(sold_vehicle_count),SUM(sold_total_price)FROM sale WHERE  sold_month = '"+month+"' and sold_year = '"+year+"'");
        if(query.exec()){
            while(query.next()) {


                QString result_currency = query.value(0).toString();
                qDebug()<<result_currency;
                QString result_month = query.value(1).toString();
                qDebug()<<result_month;
                QString result_year = query.value(2).toString();
                qDebug()<<result_year;
                int result_sum_count_vehicle = query.value(3).toInt();
                qDebug()<<result_sum_count_vehicle;
                double result_sum_total_sales = query.value(4).toDouble();
                qDebug()<<result_sum_total_sales;


                if( result_currency==""&&result_month==""&&result_year==""&&result_sum_count_vehicle==0&&result_sum_total_sales==0){
                    QMessageBox::information(this,"Info","no sold Vehicles in this selected month or in this input year !");

                    ui->label_month_year->setText("");
                    ui->label_vehicles_count->setText("");
                    ui->label_total_sale->setText("");
                }else{

                    ui->label_month_year->setText(result_month+'.'+result_year);
                    ui->label_vehicles_count->setText(QString::number(result_sum_count_vehicle));
                    ui->label_total_sale->setText(QString::number(result_sum_total_sales,'f',3) + ' ' + result_currency);

                }

            }

        }

    }

}


void Statisticscardealerpermonth::on_pushButton_home_page_clicked()
{
    this->close();

    MainWindow *MW = new MainWindow();
    MW->show();

}

