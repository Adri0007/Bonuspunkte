#include "schulverwaltungssystem.h"
#include <QApplication>
#include <iostream>
#include <string>

//int main(int argc, char *argv[]) {
/*QApplication a(argc, argv);
 MainWindow w;
 w.show();
 return a.exec();*/

int main() {

    Person P1("Person", 32);
    SuS S1("SuS", 11, 404, "4a");
    Lehrer L1("Lehrer", 40, 404);
    std::cout << P1.getName() << " " << P1.getAge() << "\n" << S1.getClass() << "\n" << L1.getRoom();

    return 0;
}
