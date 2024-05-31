#include "schulverwaltungssystem.h"
#include "./ui_schulverwaltungssystem.h"

schulverwaltungssystem::schulverwaltungssystem(QWidget *parent)
        : QMainWindow(parent), ui(new Ui::schulverwaltungssystem) {
    ui->setupUi(this);
}

schulverwaltungssystem::~schulverwaltungssystem() {
    delete ui;
}
