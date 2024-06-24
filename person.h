#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream>

class Person {
public:
    std::string name;
    std::string nachname;
    int alter;

    Person(std::string name, std::string nachname, int alter);

    virtual ~Person() = default;

    virtual void setName(const std::string &newName);

    virtual std::string getName();

    virtual void setAlter(const int &newAlter);

    virtual int getAlter();

    virtual void setNachname(const std::string &newNachname);

    virtual std::string getNachname();
};

#endif // PERSON_H
