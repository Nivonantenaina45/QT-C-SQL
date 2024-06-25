#ifndef SELLERTABLE_H
#define SELLERTABLE_H

#include <QMainWindow>
#include<QLabel>
#include<QLineEdit>
#include<QPushButton>


namespace Ui {
class SellerTable;
}

class SellerTable : public QMainWindow
{
    Q_OBJECT

public:
    explicit SellerTable(QWidget *parent = nullptr);
    ~SellerTable();

private slots:
    void on_pushButton_upload_picture_clicked();

    void on_pushButton_update_picture_clicked();

    void on_pushButton_update_data_clicked();

    void on_pushButton_delete_data_clicked();

    void on_pushButton_homePage_clicked();

    void on_tableView_seller_clicked(const QModelIndex &index);

private:
    QLabel* label_id,label_picture;
    QLineEdit* lineEdit_id, lineEdit_name,lineEdit_phone,lineEdit_email,lineEdit_address;
    QPushButton* pushButton_upload_picture,pushButton_update_picture,pushButton_update_data,pushButton_delete_data,pushButton_homePage;


private:
    Ui::SellerTable *ui;
};

#endif // SELLERTABLE_H
