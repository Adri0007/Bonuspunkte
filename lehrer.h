#ifndef LEHRER_H
#define LEHRER_H

#include "person.h"

class Lehrer : public Person {
protected:
    int room;
public:
    Lehrer(std::string name, int age, int room);

    virtual ~Lehrer();

    virtual void setRoom(const int &newRoom);

    virtual int getRoom();
};

#endif // LEHRER_H
