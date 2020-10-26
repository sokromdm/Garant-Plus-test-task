#ifndef STREETMODEL_H
#define STREETMODEL_H
#include <QListWidgetItem>

/// The StreetModel class is a child of QListWidgetItem class that allows attaching additional data (QStringList houses) for QListWidget processing via downcast and upcast
class StreetModel :public QListWidgetItem
{
public:
    StreetModel();
    StreetModel(QString text, QStringList houses);

private:
    QStringList houses;

public:
    QStringList getHouses();
    void setHouses(QStringList houses);
};

#endif // STREETMODEL_H
