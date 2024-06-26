#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidget>
#include <QPushButton>
#include <QLineEdit>

QT_BEGIN_NAMESPACE
namespace Ui {
    class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

    ~MainWindow();

private slots:
    void viewL();

    void viewS();

    void addL();

    void addS();

    void delL();

    void delS();

private:
    Ui::MainWindow *ui;
    QListWidget *OutputL;
    QPushButton *LoadL;
    QPushButton *SpeichernL;
    QPushButton *LoeschenL;
    QLineEdit *LehrerID_I;
    QLineEdit *NameL_I;
    QLineEdit *NachnameL_I;
    QLineEdit *AlterL_I;
    QLineEdit *Fach_I;

    QListWidget *OutputS;
    QPushButton *LoadS;
    QPushButton *SpeichernS;
    QPushButton *LoeschenS;
    QLineEdit *AlterS_I;
    QLineEdit *Klasse_I;
    QLineEdit *NachnameS_I;
    QLineEdit *NameS_I;
    QLineEdit *Raum_I;
    QLineEdit *SuSID_I;
};
#endif // MAINWINDOW_H
