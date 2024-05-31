#include "person.h"
#include <iostream>
#include <string>

Person::Person(std::string name, int age) {
    this->name = name;
    this->age = age;
}

Person::~Person() = default;

void Person::setName(const std::string &newName) {
    this->name = newName;
}

std::string Person::getName() {
    return name;
}

void Person::setAge(const int &newAge) {
    this->age = newAge;
}

int Person::getAge() {
    return age;
}
