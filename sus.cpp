#include "SuS.h"
#include "Person.h"

SuS::SuS(QString name, QString nachname, int alter, QString klasse, int raum, int SuSID) : Person(name, nachname, alter) {
    this->name = name;
    this->nachname = nachname;
    this->alter = alter;
    this->raum = raum;
    this->klasse = klasse;
    this->SuSID = SuSID;
}

void SuS::setRaum(const int &newRaum) {
    this->raum = newRaum;
}

int SuS::getRaum() {
    return raum;
}

void SuS::setKlasse(const QString &newKlasse) {
    this->klasse = newKlasse;
}

QString SuS::getKlasse() {
    return klasse;
}

void SuS::setSuSID(const int &newSuSID) {
    this->SuSID = newSuSID;
}

int SuS::getSuSID() {
    return SuSID;
}

void SuS::setNachname(const QString &newNachname) {
    this->nachname = newNachname;
}

QString SuS::getNachname() {
    return nachname;
}
