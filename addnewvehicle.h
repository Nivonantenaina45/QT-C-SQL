#ifndef ADDNEWVEHICLE_H
#define ADDNEWVEHICLE_H

#include <QMainWindow>
#include<QLabel>
#include<QLineEdit>
#include<QComboBox>
#include<QPushButton>


namespace Ui {
class AddNewVehicle;
}

class AddNewVehicle : public QMainWindow
{
    Q_OBJECT

public:
    explicit AddNewVehicle(QWidget *parent = nullptr);
    ~AddNewVehicle();

public:
    QLabel* label_picture;
    QLineEdit* lineEdit_name,lineEdit_manufacturer,lineEdit_construction_year,lineEdit_km_stood,lineEdit_number_of_pieces,lineEdit_price;
    QComboBox* comboBox_condtion,comboBox_currency;
    QPushButton* pushButton_upload_vehicle_picture,pushButton_save,pushButton_home_page;

private slots:
    void on_pushButton_upload_vehicle_pictures_clicked();

    void on_pushButton_save_clicked();

    void on_pushButton_home_page_clicked();

private:
    Ui::AddNewVehicle *ui;
};

#endif // ADDNEWVEHICLE_H
