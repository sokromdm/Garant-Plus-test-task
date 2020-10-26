#include "streetmodel.h"


StreetModel::StreetModel(){}

StreetModel::StreetModel(QString text, QStringList houses)
{
    this->houses = houses;
    this->setText(text);
}
QStringList StreetModel::getHouses()
{
    return houses;
}
void StreetModel::setHouses(QStringList houses)
{
    this->houses = houses;
}
