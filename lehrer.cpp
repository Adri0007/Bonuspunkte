#include "Lehrer.h"
#include "Person.h"

Lehrer::Lehrer(QString name, QString nachname, int alter, QString fach, int lehrerID) : Person(name, nachname, alter) {
    this->name = name;
    this->nachname = nachname;
    this->alter = alter;
    this->fach = fach;
    this->lehrerID = lehrerID;
}

void Lehrer::setFach(const QString &newFach) {
    this->fach = newFach;
}

QString Lehrer::getFach() {
    return fach;
}

void Lehrer::setName(const QString &newName) {
    this->name = newName;
}

QString Lehrer::getName() {
    return name;
}

void Lehrer::setAlter(const int &newAlter) {
    this->alter = newAlter;
}

int Lehrer::getAlter() {
    return alter;
}

void Lehrer::setLehrerID(const int &newLehrerID) {
    this->lehrerID = newLehrerID;
}

int Lehrer::getLehrerID() {
    return lehrerID;
}

void Lehrer::setNachname(const QString &newNachname) {
    this->nachname = newNachname;
}

QString Lehrer::getNachname() {
    return nachname;
}
