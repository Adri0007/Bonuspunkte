#ifndef SCHULVERWALTUNGSSYSTEM_H
#define SCHULVERWALTUNGSSYSTEM_H

#include <QMainWindow>
#include "lehrer.h"
#include "sus.h"

QT_BEGIN_NAMESPACE
namespace Ui {
    class schulverwaltungssystem;
}
QT_END_NAMESPACE

class schulverwaltungssystem : public QMainWindow {
Q_OBJECT

public:
    schulverwaltungssystem(QWidget *parent = nullptr);

    ~schulverwaltungssystem();

private:
    Ui::schulverwaltungssystem *ui;
};

#endif // SCHULVERWALTUNGSSYSTEM_H
