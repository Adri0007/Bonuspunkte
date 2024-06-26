#ifndef SUS_H
#define SUS_H

#include "Person.h"

class SuS : public Person {
public:
    int raum;
    QString klasse;
    int SuSID;

    SuS(QString name, QString nachname, int alter, QString klasse, int raum, int SuSID);

    virtual ~SuS() = default;

    virtual void setRaum(const int &newRaum);

    virtual int getRaum();

    virtual void setKlasse(const QString &newKlasse);

    virtual QString getKlasse();

    virtual void setSuSID(const int &newSuSID);

    virtual int getSuSID();

    virtual void setNachname(const QString &newNachname);

    virtual QString getNachname();
};

#endif // SUS_H
