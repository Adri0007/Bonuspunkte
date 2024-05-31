#ifndef SUS_H
#define SUS_H

#include "person.h"

class SuS : public Person {
private:
    int room;
    std::string Class;
public:
    SuS(std::string name, int age, int room, std::string Class);

    virtual ~SuS();

    virtual void setRoom(const int &newRoom);

    virtual int getRoom();

    virtual void setClass(const std::string &newClass);

    virtual std::string getClass();
};

#endif // SUS_H
