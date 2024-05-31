#include "sus.h"
#include "person.h"

SuS::SuS(std::string name, int age, int room, std::string Class) : Person(name, age) {
    this->room = room;
    this->Class = Class;
}

SuS::~SuS() = default;

void SuS::setRoom(const int &newRoom) {
    this->room = newRoom;
}

int SuS::getRoom() {
    return room;
}

void SuS::setClass(const std::string &newClass) {
    this->Class = newClass;
}

std::string SuS::getClass() {
    return Class;
}
