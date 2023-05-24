#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "form.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("E:/sam_rab/Saydullayev/zadanie4/zadanie4/restoran.db");

    if(db.open()){
        tableModel = new QSqlTableModel(this, db);
        tableModel->setTable("menu");
        tableModel->select();
        ui->tableView->setModel(tableModel);

    }
    else{
        ui->statusbar->showMessage( db.lastError().text());
    }


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{

    tableModel->insertRow(tableModel->rowCount());

}


void MainWindow::on_pushButton_2_clicked()
{
    tableModel->removeRow(currentRow);
    tableModel->select();
}


void MainWindow::on_tableView_clicked(const QModelIndex &index)
{
    currentRow = index.row();
}




void MainWindow::on_pushButton_3_clicked()
{
    form = new Form;
    form->show();
}


void MainWindow::on_pushButton_4_clicked()
{
    if(db.open()){
        tableModel = new QSqlTableModel(this, db);
        tableModel->setTable("zakaz");
        tableModel->select();
        ui->tableView->setModel(tableModel);

    }
    else{
        ui->statusbar->showMessage( db.lastError().text());
    }
}


void MainWindow::on_pushButton_5_clicked()
{
    if(db.open()){
        tableModel = new QSqlTableModel(this, db);
        tableModel->setTable("menu");
        tableModel->select();
        ui->tableView->setModel(tableModel);

    }
    else{
        ui->statusbar->showMessage( db.lastError().text());
    }

}

