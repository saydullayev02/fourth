#include "form.h"
#include "ui_form.h"

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery("SELECT dish FROM 'menu'");
    ui->comboBox->setModel(model);




}

Form::~Form()
{
    delete ui;
}

void Form::slot()
{

}

void Form::on_pushButton_clicked()
{
    QString client = ui->textEdit->toPlainText();
    int count = ui->spinBox->text().toInt();
    int price;
    QString dish = ui->comboBox->currentText();
    QSqlQuery * query = new QSqlQuery;
    query->prepare("SELECT price FROM 'menu' WHERE dish = :search");
    query->bindValue(":search", dish);
    query->exec();
    while(query->next()){
        price = query->value(0).toInt();
        ui->label->setText(QString::number(price*count));
    }


        QSqlQuery * query2 = new QSqlQuery;
        query2->prepare("INSERT INTO zakaz  (client,product,count,price) VALUES (:client, :product, :count, :price)");
        query2->bindValue(":client", client);
        query2->bindValue(":product", dish);
        query2->bindValue(":count", count);
        query2->bindValue(":price", price);

        if(query2->exec()){
        ui->label_6->setText("Готово");
        }
        else{
            ui->label_6->setText("что-то пошло не так");
        }
}


void Form::on_pushButton_2_clicked()
{
    close();
}

