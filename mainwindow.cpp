#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("QT Regular Expression Tester");
    on_lineEdit_textEdited("");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_lineEdit_textEdited(const QString &arg1)
{
    QRegExp rx(ui->lineEdit->text());
    QStringList kk = ui->textEdit->toPlainText().split(rx);
    QListWidgetItem *item;
    ui->listWidget->clear();
    for(int i=0; i<kk.size(); i++)
    {
        item = new QListWidgetItem();
        item->setText(kk[i]);
        ui->listWidget->addItem(item);
    }
}

void MainWindow::on_textEdit_textChanged()
{
    on_lineEdit_textEdited("");
}
