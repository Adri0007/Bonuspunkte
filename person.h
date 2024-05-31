#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person {
protected:
    std::string name;
    int age;
public:
    Person(std::string name, int age);

    virtual ~Person();

    virtual void setName(const std::string &newName);

    virtual std::string getName();

    virtual void setAge(const int &newAge);

    virtual int getAge();
};

#endif // PERSON_H
