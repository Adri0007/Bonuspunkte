#ifndef PERSON_H
#define PERSON_H

#include <QMainWindow>

class Person {
public:
    QString name;
    QString nachname;
    int alter;

    Person(QString name, QString nachname, int alter);

    virtual ~Person() = default;

    virtual void setName(const QString &newName);

    virtual QString getName();

    virtual void setAlter(const int &newAlter);

    virtual int getAlter();

    virtual void setNachname(const QString &newNachname);

    virtual QString getNachname();
};

#endif // PERSON_H
