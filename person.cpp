#include "person.h"
#include <string>

Person::Person(std::string name, std::string nachname, int alter) {
    this->name = name;
    this->nachname = nachname;
    this->alter = alter;
}

void Person::setName(const std::string &newName) {
    this->name = newName;
}

std::string Person::getName() {
    return name;
}

void Person::setAlter(const int &newAlter) {
    this->alter = newAlter;
}

int Person::getAlter() {
    return alter;
}

void Person::setNachname(const std::string &newNachname) {
    this->nachname = newNachname;
}

std::string Person::getNachname() {
    return nachname;
}