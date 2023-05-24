#ifndef FORM_H
#define FORM_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlTableModel>
#include <QSqlQuery>


namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = nullptr);
    ~Form();

private:
    Ui::Form *ui;
    QSqlDatabase db; //new
    QSqlTableModel *tableModel; //new

public slots:
    void slot();
private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
};

#endif // FORM_H
