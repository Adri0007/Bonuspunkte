#include "Lehrer.h"
#include "Person.h"

Lehrer::Lehrer(std::string name, std::string nachname, int alter, std::string fach, int lehrerID) : Person(name, nachname, alter) {
    this->name = name;
    this->nachname = nachname;
    this->alter = alter;
    this->fach = fach;
    this->lehrerID = lehrerID;
}

void Lehrer::setFach(const std::string &newFach) {
    this->fach = newFach;
}

std::string Lehrer::getFach() {
    return fach;
}

void Lehrer::setName(const std::string &newName) {
    this->name = newName;
}

std::string Lehrer::getName() {
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

void Lehrer::setNachname(const std::string &newNachname) {
    this->nachname = newNachname;
}

std::string Lehrer::getNachname() {
    return nachname;
}
