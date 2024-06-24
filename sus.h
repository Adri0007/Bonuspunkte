#ifndef SUS_H
#define SUS_H

#include "person.h"

class SuS : public Person {
public:
    int raum;
    std::string klasse;
    int SuSID;

    SuS(std::string name, std::string nachname, int alter, std::string klasse, int raum, int SuSID);

    virtual ~SuS() = default;

    virtual void setRaum(const int &newRaum);

    virtual int getRaum();

    virtual void setKlasse(const std::string &newKlasse);

    virtual std::string getKlasse();

    virtual void setSuSID(const int &newSuSID);

    virtual int getSuSID();

    virtual void setNachname(const std::string &newNachname);

    virtual std::string getNachname();
};

#endif // SUS_H
