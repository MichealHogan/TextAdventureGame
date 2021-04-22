#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "command.h"
#include "character.h"
#include "hero.h"
#include "parser.h"
#include "room.h"
#include "item.h"
#include "monster.h"
#include "inventory.h"
#include "commandwords.h"
#include "inventory.h"
#include <QString>
#include <QApplication>
#include <iostream>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    MainWindow(const MainWindow &source); // Deep Copy Constructor
    ~MainWindow();


    QString go(QString direction);
    QString string1= "default";
    void goRoom(Command command);
    void dropItem(Command command);
    void eatFood(Command commmand);

private slots:
    void on_lineEdit_returnPressed();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_InventoryButton_clicked();

    void on_quickTakeButton_clicked();

    void on_quickDrop_clicked();

    void on_quickEat_clicked();

private:

    // Pointer variables for the rooms being used in the game
    Room *a;
    Room *b;
    Room *c;
    Room *d;
    Room *e;
    Room *f;
    Room *g;
    Room *h;
    Room *i;
    Room *j;
    Room *k;
    Room *grave;


    Ui::MainWindow *ui;

    Parser parser;
    hero elf;
    //Monsters
    Monster *Ettin;
    Monster *jailer;
    Monster *warg;
    Monster *Goblin;

    void processCommand(Command command);
    void createRooms();
    void printWelcome();
    void printHelp();
    void createItems();
    void displayItems();
};
#endif // MAINWINDOW_H
