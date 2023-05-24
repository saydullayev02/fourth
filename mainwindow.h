#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include "form.h"
#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlTableModel>





QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_tableView_clicked(const QModelIndex &index);



    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::MainWindow *ui;
    QSqlDatabase db; //new
    QSqlTableModel *tableModel; //new
    int currentRow;
    Form *form;

signals:
    void signal();

};
#endif // MAINWINDOW_H
