#ifndef ADDNEWSELLER_H
#define ADDNEWSELLER_H

#include <QMainWindow>
#include<QLabel>
#include<QLineEdit>
#include<QPushButton>


namespace Ui {
class AddNewSeller;
}

class AddNewSeller : public QMainWindow
{
    Q_OBJECT

public:
    explicit AddNewSeller(QWidget *parent = nullptr);
    ~AddNewSeller();

    QLabel* label_picture_seller;
    QLineEdit* lineEdit_seller_name,lineEdit_seller_phone,lineEdit_seller_email,lineEdit_seller_address;
    QPushButton* pushButton_upload_seller_picture,pushButton_save_seller,pushButton_home_page_seller;


private slots:
    void on_pushButton_upload_seller_picture_clicked();

    void on_pushButton_save_seller_clicked();

    void on_pushButton_home_page_seller_clicked();

private:
    Ui::AddNewSeller *ui;
};

#endif // ADDNEWSELLER_H
