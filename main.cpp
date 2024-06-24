#include <iostream>
#include <fstream>
#include <string>
#include <ostream>
#include "Schulverwaltungssystem.h"

int main() {
    int countL = 0;
    int countS = 0;
    int wahl;

    std::ifstream fileL("lehrer.txt");
    std::string lineL;

    while (std::getline(fileL, lineL)) {
        ++countL;
    }

    std::ifstream fileS("SuS.txt");
    std::string lineS;

    while (std::getline(fileS, lineS)) {
        ++countS;
    }

    while (true) {
        std::cout << "\n1. View Lehrer";
        std::cout << "\n2. View SuS";
        std::cout << "\n3. Add Lehrer";
        std::cout << "\n4. Add SuS";
        std::cout << "\n5. Delete Lehrer";
        std::cout << "\n6. Delete SuS";
        std::cout << "\n7. Exit";
        std::cout << "\n\nEnter your choice: ";

        try {
            std::cin >> wahl;
            std::cout << std::endl;
            if (wahl <= 0 || wahl > 7) {
                throw "Ungültige Auswahl. Bitte Starten Sie das Programm neu und geben Sie eine Zahl zwischen 1 und 7 ein.";
            }
        } catch (const char *msg) {
            std::cerr << msg << std::endl;
            exit(1);
        }

        switch (wahl) {
            case 1:
                viewL();
                break;
            case 2:
                viewS();
                break;
            case 3:
                std::flush(std::cout);
                addL(countL);
                break;
            case 4:
                std::flush(std::cout);
                addS(countS);
                break;
            case 5:
                std::flush(std::cout);
                delL();
                break;
            case 6:
                std::flush(std::cout);
                delS();
                break;
            case 7:
                exit(0);
        }
    }
    return 0;
}
