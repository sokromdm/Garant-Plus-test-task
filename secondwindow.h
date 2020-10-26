#ifndef SECONDWINDOW_H
#define SECONDWINDOW_H

#include <QWidget>

namespace Ui {
class SecondWindow;
}

/// Second window of this programm shows house numbers of selected street from the first window
class SecondWindow : public QWidget
{
    Q_OBJECT

public:
    explicit SecondWindow(QWidget *parent = nullptr);
    ~SecondWindow();

public:
    Ui::SecondWindow *ui;
};

#endif // SECONDWINDOW_H
