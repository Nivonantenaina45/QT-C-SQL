#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDebug>
#include<QSqlDatabase>
#include"addnewvehicle.h"
#include"vehicletable.h"
#include"addnewseller.h"
#include"sellertable.h"
#include"addnewcustomer.h"
#include"customertable.h"
#include"sale.h"
#include"statisticssellerpermonth.h"
#include"statisticssellerperyear.h"
#include"statisticscustomerperyear.h"
#include"statisticscardealerpermonth.h"
#include"statisticscardealerperyear.h"




MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QSqlDatabase DBConnection = QSqlDatabase::addDatabase("QSQLITE");
    DBConnection.setDatabaseName("C:/Users/SAH creator/Documents/cours_qtsql/MyDB.db");

    if(DBConnection.open()==false){
        qDebug()<<"DBConnection Erorr";
    }else{
        qDebug()<<"DBConnection Success";
    }

    /*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ this = Window @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*/

    timer_picture_1 = new QTimer(this);
    QObject::connect(timer_picture_1,SIGNAL(timeout()),this,SLOT(Timer_picture_1_Timeout_Event_Slot()));
    timer_picture_1->start();

    timer_picture_2 = new QTimer(this);
    QObject::connect(timer_picture_2,SIGNAL(timeout()),this,SLOT(Timer_picture_2_Timeout_Event_Slot()));
    timer_picture_2->start(3000);


    timer_picture_3 = new QTimer(this);
    QObject::connect(timer_picture_3,SIGNAL(timeout()),this,SLOT(Timer_picture_3_Timeout_Event_Slot()));
    timer_picture_3->start(6000);



    timer_picture_4 = new QTimer(this);
    QObject::connect(timer_picture_4,SIGNAL(timeout()),this,SLOT(Timer_picture_4_Timeout_Event_Slot()));
    timer_picture_4->start(9000);


    timer_picture_5 = new QTimer(this);
    QObject::connect(timer_picture_5,SIGNAL(timeout()),this,SLOT(Timer_picture_5_Timeout_Event_Slot()));
    timer_picture_5->start(12000);

}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Timer_picture_1_Timeout_Event_Slot()
{
    ui->label_picture->setPixmap(QPixmap(":picture/lamborghini.jpg").scaledToHeight(1200).scaledToWidth(1200));
}

void MainWindow::Timer_picture_2_Timeout_Event_Slot()
{
    timer_picture_1->stop();
    ui->label_picture->setPixmap(QPixmap(":picture/Chevorlet.png").scaledToHeight(1200).scaledToWidth(1200));
}

void MainWindow::Timer_picture_3_Timeout_Event_Slot()
{
    timer_picture_2->stop();
    ui->label_picture->setPixmap(QPixmap(":picture/Bugatti-New.jpg").scaledToHeight(1200).scaledToWidth(1200));
}

void MainWindow::Timer_picture_4_Timeout_Event_Slot()
{
    timer_picture_3->stop();
    ui->label_picture->setPixmap(QPixmap(":picture/Ford-mustang.jpg").scaledToHeight(1200).scaledToWidth(1200));
}

void MainWindow::Timer_picture_5_Timeout_Event_Slot()
{
    timer_picture_4->stop();
    ui->label_picture->setPixmap(QPixmap(":picture/Bugatti-new.png").scaledToHeight(1200).scaledToWidth(1200));
}





void MainWindow::on_actionAdd_new_vehicle_triggered()
{
    this->close();
    AddNewVehicle *ANV = new AddNewVehicle();
    ANV->show();

}


void MainWindow::on_actionAdd_new_vehicle_2_triggered()
{
    this->close();
    AddNewVehicle *ANV = new AddNewVehicle();
    ANV->show();
}


void MainWindow::on_actionvehicle_Table_triggered()
{
    this->close();
    VehicleTable *VT = new VehicleTable();
    VT->show();

}


void MainWindow::on_actionvehicle_Table_2_triggered()
{
    this->close();
    VehicleTable *VT = new VehicleTable();
    VT->show();
}


void MainWindow::on_actionadd_new_seller_2_triggered()
{
    this->close();
    AddNewSeller *ANS = new AddNewSeller();
    ANS->show();
}


void MainWindow::on_actionAdd_new_seller_triggered()
{
    this->close();
    AddNewSeller *ANS = new AddNewSeller();
    ANS->show();
}


void MainWindow::on_actionseller_Table_triggered()
{
    this->close();
    SellerTable *ST = new SellerTable();
    ST->show();
}


void MainWindow::on_actionseller_table_triggered()
{
    this->close();
    SellerTable *ST = new SellerTable();
    ST->show();
}


void MainWindow::on_actionAdd_new_customer_triggered()
{
    this->close();
    AddNewCustomer *ANC = new AddNewCustomer();
    ANC->show();
}


void MainWindow::on_actionAdd_new_customer_2_triggered()
{
    this->close();
    AddNewCustomer *ANC = new AddNewCustomer();
    ANC->show();
}


void MainWindow::on_actioncustomer_Table_triggered()
{
    this->close();
    CustomerTable *CT =new CustomerTable();
    CT->show();
}


void MainWindow::on_actioncustomer_Table_2_triggered()
{
    this->close();
    CustomerTable *CT =new CustomerTable();
    CT->show();
}


void MainWindow::on_actionDoing_business_triggered()
{
    this->close();
    Sale *SL =new Sale();
    SL->show();
}


void MainWindow::on_actionDoing_bussiness_triggered()
{
    this->close();
    Sale *SL =new Sale();
    SL->show();
}


void MainWindow::on_actionStatistics_per_month_triggered()
{
    this->close();
    Statisticssellerpermonth *SPM =new Statisticssellerpermonth();
    SPM->show();
}


void MainWindow::on_actionStatistics_per_month_2_triggered()
{
    this->close();
    Statisticssellerpermonth *SPM =new Statisticssellerpermonth();
    SPM->show();
}


void MainWindow::on_actionStatistics_per_year_triggered()
{
    this->close();
    Statisticssellerperyear *SPY =new Statisticssellerperyear();
    SPY->show();
}


void MainWindow::on_actionStatistics_per_year_2_triggered()
{
    this->close();
    Statisticssellerperyear *SPY =new Statisticssellerperyear();
    SPY->show();
}


void MainWindow::on_actionStatistics_customer_per_year_triggered()
{
    this->close();
    Statisticscustomerperyear *SCY = new Statisticscustomerperyear();
    SCY->show();
}


void MainWindow::on_actionStatistics_customer_per_year_2_triggered()
{
    this->close();
    Statisticscustomerperyear *SCY = new Statisticscustomerperyear();
    SCY->show();
}


void MainWindow::on_actionStatistics_car_dealer_per_month_triggered()
{
    this->close();
    Statisticscardealerpermonth *SCDM =new Statisticscardealerpermonth();
    SCDM->show();
}


void MainWindow::on_actionStatistics_car_dealer_per_month_2_triggered()
{
    this->close();
    Statisticscardealerpermonth *SCDM =new Statisticscardealerpermonth();
    SCDM->show();
}


void MainWindow::on_actionStastistics_car_dealer_per_year_triggered()
{
    this->close();
    Statisticscardealerperyear *SCDY =new  Statisticscardealerperyear();
    SCDY->show();
}


void MainWindow::on_actionStastistics_car_dealer_per_year_2_triggered()
{
    this->close();
    Statisticscardealerperyear *SCDY =new  Statisticscardealerperyear();
    SCDY->show();
}

