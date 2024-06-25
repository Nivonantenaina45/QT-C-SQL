#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QLabel>
#include<QTimer>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QLabel* label_picture;
    QTimer  *timer_picture_1,*timer_picture_2,*timer_picture_3,*timer_picture_4,*timer_picture_5;


private slots:

    void Timer_picture_1_Timeout_Event_Slot();
    void Timer_picture_2_Timeout_Event_Slot();
    void Timer_picture_3_Timeout_Event_Slot();
    void Timer_picture_4_Timeout_Event_Slot();
    void Timer_picture_5_Timeout_Event_Slot();

    void on_actionAdd_new_vehicle_triggered();

    void on_actionAdd_new_vehicle_2_triggered();

    void on_actionvehicle_Table_triggered();

    void on_actionvehicle_Table_2_triggered();

    void on_actionadd_new_seller_2_triggered();

    void on_actionAdd_new_seller_triggered();

    void on_actionseller_Table_triggered();

    void on_actionseller_table_triggered();

    void on_actionAdd_new_customer_triggered();

    void on_actionAdd_new_customer_2_triggered();

    void on_actioncustomer_Table_triggered();

    void on_actioncustomer_Table_2_triggered();

    void on_actionDoing_business_triggered();

    void on_actionDoing_bussiness_triggered();

    void on_actionStatistics_per_month_triggered();

    void on_actionStatistics_per_month_2_triggered();

    void on_actionStatistics_per_year_triggered();

    void on_actionStatistics_per_year_2_triggered();

    void on_actionStatistics_customer_per_year_triggered();

    void on_actionStatistics_customer_per_year_2_triggered();

    void on_actionStatistics_car_dealer_per_month_triggered();

    void on_actionStatistics_car_dealer_per_month_2_triggered();

    void on_actionStastistics_car_dealer_per_year_triggered();

    void on_actionStastistics_car_dealer_per_year_2_triggered();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
