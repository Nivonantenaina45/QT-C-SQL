#ifndef STATISTICSCARDEALERPERYEAR_H
#define STATISTICSCARDEALERPERYEAR_H
#include<QLabel>
#include<QLineEdit>
#include<QPushButton>

#include <QMainWindow>

namespace Ui {
class Statisticscardealerperyear;
}

class Statisticscardealerperyear : public QMainWindow
{
    Q_OBJECT

public:
    explicit Statisticscardealerperyear(QWidget *parent = nullptr);
    ~Statisticscardealerperyear();
public:
    QLineEdit* lineEdit_year;
    QPushButton* pushButton_statistics_car_dealer_per_year,pushButton_home_page;
    QLabel* label_picture,label_date,label_vehicles_count,label_total_sales;


private slots:
    void on_pushButton_statisticssellerpermonth_clicked();

    void on_pushButton_home_page_clicked();

private:
    Ui::Statisticscardealerperyear *ui;
};

#endif // STATISTICSCARDEALERPERYEAR_H
