#include "Person.h"

Person::Person(QString name, QString nachname, int alter) {
    this->name = name;
    this->nachname = nachname;
    this->alter = alter;
}

void Person::setName(const QString &newName) {
    this->name = newName;
}

QString Person::getName() {
    return name;
}

void Person::setAlter(const int &newAlter) {
    this->alter = newAlter;
}

int Person::getAlter() {
    return alter;
}

void Person::setNachname(const QString &newNachname) {
    this->nachname = newNachname;
}

QString Person::getNachname() {
    return nachname;
}
