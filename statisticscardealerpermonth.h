#ifndef STATISTICSCARDEALERPERMONTH_H
#define STATISTICSCARDEALERPERMONTH_H
#include<QLabel>
#include<QLineEdit>
#include<QComboBox>
#include<QPushButton>


#include <QMainWindow>

namespace Ui {
class Statisticscardealerpermonth;
}

class Statisticscardealerpermonth : public QMainWindow
{
    Q_OBJECT

public:
    explicit Statisticscardealerpermonth(QWidget *parent = nullptr);
    ~Statisticscardealerpermonth();

public:
    QComboBox* comboBox_date_month;
    QLineEdit* lineEdit_year;
    QLabel* label_picture,label_date,label_vehicles_count,label_total_sales;
    QPushButton* pushButton_statistics_car_dealer_per_month,pushButton_home_page;


private slots:
    void on_pushButton_statisticssellerpermonth_clicked();

    void on_pushButton_home_page_clicked();

private:
    Ui::Statisticscardealerpermonth *ui;
};

#endif // STATISTICSCARDEALERPERMONTH_H
