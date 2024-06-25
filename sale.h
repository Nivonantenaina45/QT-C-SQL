#ifndef SALE_H
#define SALE_H
#include<QLabel>
#include<QLineEdit>
#include<QComboBox>
#include<QPushButton>


#include <QMainWindow>

namespace Ui {
class Sale;
}

class Sale : public QMainWindow
{
    Q_OBJECT

public:
    explicit Sale(QWidget *parent = nullptr);
    ~Sale();

public:
    QLineEdit* lineEdit_date_year;
    QComboBox* comboBox_vehicle_name,comboBox_customer_name,comboBox_seller_name,comboBox_number_of_vehicles,comboBox_date_day,comboBox_date_month;
    QPushButton* pushButton_submit,pushButton_confirm,pushButton_home_page;
    QLabel* label_doing_business_picture,label_closing_the_deal_picture,label_vehicle_name
        ,label_customer_name,label_seller_name,label_number_of_vehicles,label_sale_date,label_total_sales;


private slots:

    void on_pushButton_submit_clicked();

    void on_pushButton_confirm_clicked();

    void on_pushButton_home_page_clicked();

    void on_comboBox_vehicle_name_currentIndexChanged(int index);

private:
    Ui::Sale *ui;
};

#endif // SALE_H
