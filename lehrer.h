#ifndef LEHRER_H
#define LEHRER_H

#include "Person.h"

class Lehrer : public Person {
public:
    int lehrerID;
    QString fach;

    Lehrer(QString name, QString nachname, int alter, QString fach, int lehrerID);

    virtual ~Lehrer() = default;

    virtual void setName(const QString &newName);

    virtual QString getName();

    virtual void setAlter(const int &newAlter);

    virtual int getAlter();

    virtual void setFach(const QString &newFach);

    virtual QString getFach();

    virtual void setLehrerID(const int &newLehrerID);

    virtual int getLehrerID();

    virtual void setNachname(const QString &newNachname);

    virtual QString getNachname();
};

#endif // LEHRER_H
