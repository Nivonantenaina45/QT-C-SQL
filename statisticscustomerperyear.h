#ifndef STATISTICSCUSTOMERPERYEAR_H
#define STATISTICSCUSTOMERPERYEAR_H
#include<QLabel>
#include<QLineEdit>
#include<QComboBox>
#include<QPushButton>
#include <QMainWindow>

namespace Ui {
class Statisticscustomerperyear;
}

class Statisticscustomerperyear : public QMainWindow
{
    Q_OBJECT

public:
    explicit Statisticscustomerperyear(QWidget *parent = nullptr);
    ~Statisticscustomerperyear();

public:
    QComboBox* comboBox_name;
    QLineEdit* lineEdit_year;
    QLabel* label_picture,label_name,label_date,label_vehicles_count,label_total_sales;
    QPushButton* pushButton_statistics_customer_per_year, pushButton_home_page;


private slots:
    void on_pushButton_statisticscustomerpermonth_clicked();

    void on_pushButton_home_page_clicked();

private:
    Ui::Statisticscustomerperyear *ui;
};

#endif // STATISTICSCUSTOMERPERYEAR_H
