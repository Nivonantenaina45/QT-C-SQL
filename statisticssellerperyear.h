#ifndef STATISTICSSELLERPERYEAR_H
#define STATISTICSSELLERPERYEAR_H
#include<QLabel>
#include<QLineEdit>
#include<QComboBox>
#include<QPushButton>
#include <QMainWindow>

namespace Ui {
class Statisticssellerperyear;
}

class Statisticssellerperyear : public QMainWindow
{
    Q_OBJECT

public:
    explicit Statisticssellerperyear(QWidget *parent = nullptr);
    ~Statisticssellerperyear();
public:
    QComboBox* comboBox_name;
    QLineEdit* lineEdit_year;
    QPushButton* pushButton_statistics_seller_per_year, pushButton_home_page;
    QLabel* label_picture,label_name,label_date,label_vehicles_count,label_total_sales;


private slots:
    void on_pushButton_statisticssellerpermonth_clicked();

    void on_pushButton_home_page_clicked();

private:
    Ui::Statisticssellerperyear *ui;
};

#endif // STATISTICSSELLERPERYEAR_H
