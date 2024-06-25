#ifndef CUSTOMERTABLE_H
#define CUSTOMERTABLE_H

#include <QMainWindow>
#include<QLabel>
#include<QLineEdit>
#include<QPushButton>
#include<QTableView>


namespace Ui {
class CustomerTable;
}

class CustomerTable : public QMainWindow
{
    Q_OBJECT

public:
    explicit CustomerTable(QWidget *parent = nullptr);
    ~CustomerTable();

public:
    QLabel* label_id;
    QLineEdit* lineEdit_id,lineEdit_name,lineEdit_phone,lineEdit_email,lineEdit_address;
    QPushButton* pushButton_update_data,pushButton_delete_data,pushButton_homePage;
    QTableView* tableView_customer;


private slots:
    void on_tableView_customer_clicked(const QModelIndex &index);

    void on_pushButton_update_data_clicked();

    void on_pushButton_delete_data_clicked();

    void on_pushButton_homePage_clicked();

private:
    Ui::CustomerTable *ui;
};

#endif // CUSTOMERTABLE_H
