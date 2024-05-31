#include "lehrer.h"
#include "person.h"

Lehrer::Lehrer(std::string name, int age, int room) : Person(name, age) {
    this->room = room;
}

Lehrer::~Lehrer() = default;

void Lehrer::setRoom(const int &newRoom) {
    this->room = newRoom;
}

int Lehrer::getRoom() {
    return room;
}
