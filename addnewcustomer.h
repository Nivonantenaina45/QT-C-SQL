#ifndef ADDNEWCUSTOMER_H
#define ADDNEWCUSTOMER_H
#include<QLabel>
#include<QLineEdit>
#include<QPushButton>

#include <QMainWindow>

namespace Ui {
class AddNewCustomer;
}

class AddNewCustomer : public QMainWindow
{
    Q_OBJECT

public:
    explicit AddNewCustomer(QWidget *parent = nullptr);
    ~AddNewCustomer();

public:
    QLabel* label_picture;
    QLineEdit* lineEdit_name,lineEdit_phone,lineEdit_email,lineEdit_address;
    QPushButton* pushButton_save, pushButton_home_page;


private slots:
    void on_pushButton_save_clicked();

    void on_pushButton_home_page_clicked();

private:
    Ui::AddNewCustomer *ui;
};

#endif // ADDNEWCUSTOMER_H
