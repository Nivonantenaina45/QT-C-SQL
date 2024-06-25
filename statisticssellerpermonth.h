#ifndef STATISTICSSELLERPERMONTH_H
#define STATISTICSSELLERPERMONTH_H
#include<QLabel>
#include<QComboBox>
#include<QLineEdit>
#include<QPushButton>
#include <QMainWindow>

namespace Ui {
class Statisticssellerpermonth;
}

class Statisticssellerpermonth : public QMainWindow
{
    Q_OBJECT

public:
    explicit Statisticssellerpermonth(QWidget *parent = nullptr);
    ~Statisticssellerpermonth();

public:
    QLabel* label_picture,label_name,label_date,label_vehicles_count,label_total_sales;
    QComboBox* comboBox_name,comboBox_date_month;
    QLineEdit* lineEdit_year;
    QPushButton* pushButton_statistics_seller_per_month,pushButton_home_page;


private slots:
    void on_pushButton_statisticssellerpermonth_clicked();

    void on_pushButton_home_page_clicked();

private:
    Ui::Statisticssellerpermonth *ui;
};

#endif // STATISTICSSELLERPERMONTH_H
