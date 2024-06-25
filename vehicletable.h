#ifndef VEHICLETABLE_H
#define VEHICLETABLE_H

#include <QMainWindow>
#include<QTableView>
#include<QLabel>
#include<QLineEdit>
#include<QPushButton>


namespace Ui {
class VehicleTable;
}

class VehicleTable : public QMainWindow
{
    Q_OBJECT

public:
    explicit VehicleTable(QWidget *parent = nullptr);
    ~VehicleTable();

public:
    QTableView *tableView_vehicle;
    QLabel* label_id, label_picture;
    QLineEdit* lineEdit_id,lineEdit_name,lineEdit_manufacturer,lineEdit_construction_year,lineEdit_kmStood,lineEdit_condtion
        ,lineEdit_pieces,lineEdit_price,lineEdit_currency,lineEdit_availability;
    QPushButton* pushButton_upload_picture,pushButton_update_picture,pushButton_update_data,pushButton_delete_data,pushButton_homePage;



private slots:
    void on_tableView_vehicle_clicked(const QModelIndex &index);

    void on_pushButton_update_picture_clicked();

    void on_pushButton_upload_picture_clicked();

    void on_pushButton_update_data_clicked();

    void on_pushButton_delete_data_clicked();

    void on_pushButton_homePage_clicked();

private:
    Ui::VehicleTable *ui;
};

#endif // VEHICLETABLE_H
