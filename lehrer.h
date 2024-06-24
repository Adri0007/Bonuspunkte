#ifndef LEHRER_H
#define LEHRER_H

#include "Person.h"

class Lehrer : public Person {
public:
    int lehrerID;
    std::string fach;

    Lehrer(std::string name, std::string nachname, int alter, std::string fach, int lehrerID);

    virtual ~Lehrer() = default;

    virtual void setName(const std::string &newName);

    virtual std::string getName();

    virtual void setAlter(const int &newAlter);

    virtual int getAlter();

    virtual void setFach(const std::string &newFach);

    virtual std::string getFach();

    virtual void setLehrerID(const int &newLehrerID);

    virtual int getLehrerID();

    virtual void setNachname(const std::string &newNachname);

    virtual std::string getNachname();
};

#endif // LEHRER_H
