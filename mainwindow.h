#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWindow>
#include "secondwindow.h"
#include <QListWidgetItem>
#include "streetmodel.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    SecondWindow secondWindow;
    QStringList rawData;
    QList<StreetModel> streets;

private slots:
    /// Shows house numbers of the selected street on the second window
    void on_listWidget_itemClicked(QListWidgetItem *item);
    /// Processing .txt file with strings of streets names and house numbers, then converts strings to model 'streetmodel' and sends it to the widget
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
