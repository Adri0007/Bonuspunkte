#include "Schulverwaltungssystem.h"
#include <fstream>
#include <sstream>

void addL(int &countL) {
    std::string name;
    std::string nachname;
    int alter;
    std::string fach;
    int lehrerID = 0;

    std::cout << "\nName: ";
    std::cin.ignore();
    std::getline(std::cin, name);
    std::cout << "Nachname: ";
    std::getline(std::cin, nachname);
    std::cout << "Alter: ";
    std::cin >> alter;
    std::cin.ignore();
    std::cout << "Fach: ";
    std::getline(std::cin, fach);
    countL++;
    lehrerID = countL;

    Lehrer newLehrer(name, nachname, alter, fach, lehrerID);

    std::ofstream outputFile("lehrer.txt", std::ios::app);
    if (outputFile.is_open()) {
        outputFile << newLehrer.getLehrerID() << " " << newLehrer.getName() << " " << newLehrer.getNachname() << " "
                   << newLehrer.getAlter() << " "
                   << newLehrer.getFach() << "\n";
        outputFile.close();
    }
}

void addS(int &countS) {
    std::string name;
    std::string nachname;
    int alter;
    std::string klasse;
    int raum;
    int SuSID = 0;

    std::flush(std::cout);
    std::cout << "\nName: ";
    std::cin.ignore();
    std::getline(std::cin, name);
    std::cout << "Nachname: ";
    std::getline(std::cin, nachname);
    std::cout << "Alter: ";
    std::cin >> alter;
    std::cin.ignore();
    std::cout << "Klasse: ";
    std::getline(std::cin, klasse);
    std::cout << "Raum: ";
    std::cin >> raum;
    std::cin.ignore();
    countS++;
    SuSID = countS;

    SuS newSuS(name, nachname, alter, klasse, raum, SuSID);

    std::ofstream outputFile("SuS.txt", std::ios::app);
    if (outputFile.is_open()) {
        outputFile << newSuS.getSuSID() << " " << newSuS.getName() << " " << newSuS.getNachname() << " "
                   << newSuS.getAlter() << " "
                   << newSuS.getKlasse() << " " << newSuS.getRaum() << "\n";
        outputFile.close();
    }
}

void viewL() {
    std::string name;
    std::string nachname;
    int alter;
    std::string fach;
    int lehrerID;
    std::string line;

    std::ifstream file("lehrer.txt");

    if (!file.is_open()) {
        std::cerr << "Die Datei konnte nicht geöffnet werden!" << std::endl;
        exit(1);
    }

    while (std::getline(file, line)) {
        std::istringstream isL(line);

        if (isL >> lehrerID >> name >> nachname >> alter >> fach) {

            std::cout << lehrerID << " " << name << " " << nachname << " " << alter << " " << fach << std::endl;
        }
    }
}

void viewS() {
    std::string name;
    std::string nachname;
    int alter;
    std::string klasse;
    int raum;
    int SuSID;
    std::string line;

    std::ifstream file("SuS.txt");

    if (!file.is_open()) {
        std::cerr << "Die Datei konnte nicht geöffnet werden!" << std::endl;
        exit(1);
    }

    while (std::getline(file, line)) {
        std::istringstream isL(line);

        if (isL >> SuSID >> name >> nachname >> alter >> klasse >> raum) {
            std::cout << SuSID << " " << name << " " << nachname << " " << alter << " " << klasse << " " << raum
                      << std::endl;
        }
    }
}

void delL() {
    std::string name;
    std::string nachname;
    int alter;
    std::string fach;
    int lehrerID;
    std::string line;
    int wahlID;
    std::cout << "Bitte geben Sie die LehrerID des Lehrers ein, den Sie entfernen möchten: ";
    std::cin >> wahlID;

    std::ifstream inputFile("lehrer.txt");
    if (!inputFile.is_open()) {
        std::cerr << "Die Datei konnte nicht geöffnet werden!";
        exit(1);
    }

    std::ostringstream updatedData;

    while (std::getline(inputFile, line)) {
        std::istringstream isL(line);

        if (isL >> lehrerID >> name >> nachname >> alter >> fach) {
            if (lehrerID != wahlID) {
                // Keep teachers with IDs different from the specified one
                updatedData << line << "\n";
            } else {
                // Replace the deleted teacher's data with a blank line
                updatedData << "\n";
            }
        }
    }

    inputFile.close();

    std::ofstream outputFile("lehrer.txt");
    if (outputFile.is_open()) {
        outputFile << updatedData.str();
        outputFile.close();
        std::cout << "Lehrer mit der ID " << wahlID << " erfolgreich gelöscht.\n";
    } else {
        std::cerr << "Beim Schreiben in die Datei ‘lehrer.txt’ ist ein Fehler aufgetreten!\n";
    }
}


void delS() {
    std::string name;
    std::string nachname;
    int alter;
    std::string klasse;
    int raum;
    int SuSID;
    std::string line;
    int wahlID;
    std::cout << "Bitte geben Sie die SuS des SuS ein, den Sie entfernen möchten: ";
    std::cin >> wahlID;

    std::ifstream inputFile("SuS.txt");
    if (!inputFile.is_open()) {
        std::cerr << "Die Datei konnte nicht geöffnet werden!";
        exit(1);
    }

    std::ostringstream updatedData;

    while (std::getline(inputFile, line)) {
        std::istringstream isL(line);

        if (isL >> SuSID >> name >> nachname >> alter >> klasse >> raum) {
            if (SuSID != wahlID) {
                // Keep teachers with IDs different from the specified one
                updatedData << line << "\n";
            } else {
                // Replace the deleted teacher's data with a blank line
                updatedData << "\n";
            }
        }
    }

    inputFile.close();

    std::ofstream outputFile("SuS.txt");
    if (outputFile.is_open()) {
        outputFile << updatedData.str();
        outputFile.close();
        std::cout << "SuS mit der ID " << wahlID << " erfolgreich gelöscht.\n";
    } else {
        std::cerr << "Beim Schreiben in die Datei ‘SuS.txt’ ist ein Fehler aufgetreten!\n";
    }
}
