#include "SuS.h"

SuS::SuS(std::string name, std::string nachname, int alter, std::string klasse, int raum, int SuSID) : Person(name, nachname, alter) {
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

void SuS::setKlasse(const std::string &newKlasse) {
    this->klasse = newKlasse;
}

std::string SuS::getKlasse() {
    return klasse;
}

void SuS::setSuSID(const int &newSuSID) {
    this->SuSID = newSuSID;
}

int SuS::getSuSID() {
    return SuSID;
}

void SuS::setNachname(const std::string &newNachname) {
    this->nachname = newNachname;
}

std::string SuS::getNachname() {
    return nachname;
}