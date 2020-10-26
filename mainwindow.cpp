#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui_secondwindow.h"
#include <QListWidget>
#include <QStringListModel>
#include <QFileDialog>
#include <QRegExp>
#include <QDir>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    secondWindow.show();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_listWidget_itemClicked(QListWidgetItem *item)
{
    StreetModel *st = dynamic_cast<StreetModel*>(item);
    secondWindow.ui->listWidget->clear();
    secondWindow.ui->listWidget->addItems(st->getHouses());
}

void MainWindow::on_pushButton_clicked()
{
    /*
     *  File standart:
     *      - .txt filename extension;
     *      - UTF-8 encoding;
     *  Single line must contain:
     *      - Street name without numbers, may contain spaces between words, must contain at least one space before first house number;
     *      - House numbers separated by ','(may contain spaces). May contain non-numbers but first symbol must be number (example: 39а or 10/2);
     *      - End of the line symbol ('\n').
     *  Examples of lines:
     *      "Свободы 1,2,3";
     *      "Улица Пушкина 12 , 12а,1 , 10".
     *  Examples of wrong lines:
     *      "Улица 1 а1, б2" <- Street name contains numbers, house number starts with non-number;
     *      "Пушкина 10; 11/2," <- Wrong separation symbol ';'.
     */

    QFile file(QFileDialog::getOpenFileName(
                this,
                tr("Open File"),
                QDir::rootPath(),
                "Text File (*.txt)"
                ));

    QStringList rawDataList;
    if(file.exists())
    {
        file.open(QIODevice::ReadOnly);
        QString rawData = file.readAll();
        rawDataList = rawData.split('\n'); // For some reason compilator don't allow to do this in one step like "file.readAll().split('\n');"
        file.close();
    }
    //Processing strings to model and to widget
    ui->listWidget->clear();
    QRegExp rx("\\s\\d");
    for (QString s : rawDataList)
    {
        int position = rx.indexIn(s);
        QString left = s.left(position);
        QStringList right = s.right(s.length() - position -1).split(QRegExp("\\s*,\\s*"));
        StreetModel *sm = new StreetModel(left, right);
        streets << *sm;
        ui->listWidget->addItem((QListWidgetItem *)sm);
    }
}
