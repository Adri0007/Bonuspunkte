#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QFileInfo>
#include <fstream>
#include "Lehrer.h"
#include "SuS.h"
#include <iostream>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    OutputL = ui->OutputL;
    LoadL = ui->LoadL;
    SpeichernL = ui->SpeichernL;
    LehrerID_I = ui->LehrerID_I;
    NameL_I = ui->NameL_I;
    NachnameL_I = ui->NachnameL_I;
    AlterL_I = ui->AlterL_I;
    Fach_I = ui->Fach_I;
    LoeschenL = ui->LoeschenL;

    OutputS = ui->OutputS;
    LoadS = ui->LoadS;
    SpeichernS = ui->SpeichernS;
    SuSID_I = ui->SuSID_I;
    NameS_I = ui->NameS_I;
    NachnameS_I = ui->NachnameS_I;
    AlterS_I = ui->AlterS_I;
    Klasse_I = ui->Klasse_I;
    Raum_I = ui->Raum_I;
    LoeschenS = ui->LoeschenS;

    viewL();
    viewS();

    connect(LoadL, &QPushButton::clicked, this, &MainWindow::viewL);
    connect(LoadS, &QPushButton::clicked, this, &MainWindow::viewS);
    connect(SpeichernL, &QPushButton::clicked, this, [=]() {
        addL();
    });
    connect(SpeichernS, &QPushButton::clicked, this, [=]() {
        addS();
    });
    connect(LoeschenL, &QPushButton::clicked, this, [=]() {
        delL();
    });
    connect(LoeschenS, &QPushButton::clicked, this, [=]() {
        delS();
    });

}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::viewL() {
    QString fileName = "/PATH/lehrer.txt";

    try {
        if (!QFileInfo::exists(fileName)) {
            throw "Lehrer.txt wurde nicht gefunden!";
        }
    } catch (const char *msg) {
        std::cerr << msg << std::endl;
        exit(1);
    }

    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        OutputL->addItem("Lehrer konnte nicht geoeffnet werden!");
    }

    QTextStream inL(&file);
    OutputL->clear();
    while (!inL.atEnd()) {
        QString line = inL.readLine().trimmed();
        if (!line.isEmpty()) {
            OutputL->addItem(line);
        }
    }

    file.close();
}

void MainWindow::viewS() {
    QString fileName = "/PATH/SuS.txt";

    try {
        if (!QFileInfo::exists(fileName)) {
            throw "SuS.txt wurde nicht gefunden!";
        }
    } catch (const char *msg) {
        std::cerr << msg << std::endl;
        exit(1);
    }

    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        OutputS->addItem("SuS konnte nicht geoeffnet werden!");
    }

    QTextStream inS(&file);
    OutputS->clear();
    while (!inS.atEnd()) {
        QString line = inS.readLine().trimmed();
        if (!line.isEmpty()) {
            OutputS->addItem(line);
        }
    }

    file.close();
}

void MainWindow::addL() {
    int countL = 0;

    std::ifstream fileL("/PATH/lehrer.txt");
    std::string lineL;

    while (std::getline(fileL, lineL)) {
        ++countL;
    }

    QString name = NameL_I->text().trimmed();
    QString nachname = NachnameL_I->text().trimmed();
    int alter = AlterL_I->text().toInt();
    QString fach = Fach_I->text().trimmed();
    int lehrerID = 0;

    countL++;
    lehrerID = countL;

    Lehrer newLehrer(name, nachname, alter, fach, lehrerID);

    QFile outL("/PATH/lehrer.txt");
    if (outL.open(QIODevice::Append | QIODevice::Text)) {
        QTextStream out(&outL);
        out << newLehrer.getLehrerID() << " " << newLehrer.getName() << " " << newLehrer.getNachname() << " "
            << newLehrer.getAlter() << " " << newLehrer.getFach() << "\n";
        outL.close();
    }

    QMessageBox::information(this, "Erfolg", "Lehrer erfolgreich hinzugefügt!");
}

void MainWindow::addS() {
    int countS = 0;

    std::ifstream fileS("/PATH/SuS.txt");
    std::string lineS;

    while (std::getline(fileS, lineS)) {
        ++countS;
    }

    QString name = NameS_I->text().trimmed();
    QString nachname = NachnameS_I->text().trimmed();
    int alter = AlterS_I->text().toInt();
    QString klasse = Klasse_I->text().trimmed();
    int raum = Raum_I->text().toInt();
    int SuSID = 0;

    countS++;
    SuSID = countS;

    SuS newSuS(name, nachname, alter, klasse, raum, SuSID);

    QFile outS("/PATH/SuS.txt");
    if (outS.open(QIODevice::Append | QIODevice::Text)) {
        QTextStream out(&outS);
        out << newSuS.getSuSID() << " " << newSuS.getName() << " " << newSuS.getNachname() << " "
            << newSuS.getAlter() << " " << newSuS.getKlasse() << " " << newSuS.getRaum() << "\n";
        outS.close();
    }

    QMessageBox::information(this, "Erfolg", "SuS erfolgreich hinzugefügt!");

}

void MainWindow::delL() {
    int wahlID = LehrerID_I->text().toInt();

    QFile inputL("/PATH/lehrer.txt");
    if (!inputL.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::critical(this, "Fehler", "Fehler beim Öffnen der Datei 'lehrer.txt' zum Lesen!");
        return;
    }

    QString updateL;
    QTextStream inL(&inputL);
    bool foundL = false;

    while (!inL.atEnd()) {
        QString lineL = inL.readLine();
        QTextStream lineStream(&lineL);

        int lehrerID;
        QString name, nachname, fach;
        int alter;

        lineStream >> lehrerID >> name >> nachname >> alter >> fach;

        if (lehrerID != wahlID) {
            updateL.append(lineL + "\n");
        } else {
            updateL.append("\n");
            foundL = true;
        }
    }
    inputL.close();

    if (!foundL) {
        QMessageBox::information(this, "Information", "LehrerID nicht gefunden.");
        return;
    }

    QFile outputL("/PATH/lehrer.txt");
    if (!outputL.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::critical(this, "Fehler", "Fehler beim Öffnen der Datei 'lehrer.txt' zum Schreiben!");
        return;
    }

    QTextStream outL(&outputL);
    outL << updateL;
    outputL.close();

    QMessageBox::information(this, "Erfolg", "Lehrer erfolgreich gelöscht");
}


void MainWindow::delS() {
    int wahlID = SuSID_I->text().toInt();

    QFile inputS("/PATH/SuS.txt");
    if (!inputS.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::critical(this, "Fehler", "Fehler beim Öffnen der Datei 'SuS.txt' zum Lesen!");
        return;
    }

    QString updateS;
    QTextStream inS(&inputS);
    bool foundS = false;

    while (!inS.atEnd()) {
        QString lineS = inS.readLine();
        QTextStream lineStream(&lineS);

        int SuSID;
        QString name, nachname, klasse;
        int alter, raum;

        lineStream >> SuSID >> name >> nachname >> alter >> klasse >> raum;

        if (SuSID != wahlID) {
            updateS.append(lineS + "\n");
        } else {
            updateS.append("\n");
            foundS = true;
        }
    }
    inputS.close();

    if (!foundS) {
        QMessageBox::information(this, "Information", "SuSID nicht gefunden.");
        return;
    }

    QFile outputS("/PATH/SuS.txt");
    if (!outputS.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::critical(this, "Fehler", "Fehler beim Öffnen der Datei 'SuS.txt' zum Schreiben!");
        return;
    }

    QTextStream outS(&outputS);
    outS << updateS;
    outputS.close();

    QMessageBox::information(this, "Erfolg", "SuS erfolgreich gelöscht");
}
