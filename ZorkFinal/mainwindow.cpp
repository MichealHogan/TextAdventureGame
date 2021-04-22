#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <stdlib.h>
#include <unistd.h>
#include <cstdlib>
#include <QPixmap>
Monster globalMonsters[4]; //Global Variable
int end = 0;




MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) , a{nullptr}, b{nullptr}, c{nullptr}, d{nullptr},
      e{nullptr}, f{nullptr}, g{nullptr}, h{nullptr}, i{nullptr},j{nullptr},k{nullptr},grave{nullptr}, Ettin{nullptr} ,
      jailer{nullptr}, warg{nullptr}, Goblin{nullptr}
{
    createRooms();

    QString intro = "Command Words:\n'take' followed by -> items name will add the item to your inventory\n'drop' followed by -> items name will remove the item from your inventory\n\nYou awaken lying on a cold stone floor,your head hurts and you have faint memories of your adventuring party being ambushed.\nA small window illuminates the confines of the small jail you've found yourself imprisoned in.\nSomething shiny catches your eye in the corner of the room.\nWhat do you do?\n";
    ui->setupUi(this);
    ui->plainTextEdit->appendPlainText(intro+elf.getCurrentRoom()->longDescription());
    ui->progressBar->setValue(elf.getHealth());
    ui->pushButton_5->hide();
    ui->progressBar_2->hide();
    MainWindow::setWindowTitle("Ettins Dilema");


    int HplayerImage = ui->playerImageLabel->height();
    int WplayerImage = ui->playerImageLabel->width();
    QPixmap playerImage(":/images/Images/playerImage.jpeg");
    ui->playerImageLabel->setPixmap(playerImage.scaled(WplayerImage,HplayerImage,Qt::KeepAspectRatio));


    int HroomLabel = ui->roomLabel->height();
    int WroomLabel = ui->roomLabel->width();
    QPixmap room(":/images/Images/prison2.jpg");
    ui->roomLabel->setPixmap(room.scaled(WroomLabel,HroomLabel,Qt::KeepAspectRatio));


    //QPixmap beholder(":/images/Images/beholder.jpg");
    //    QPixmap beholder(":/images/Images/beholder.jpg");
    //    ui->beholder->setPixmap(beholder);
    //ui->beholder->hide();

}
MainWindow::~MainWindow() // deallocate memory from the data members of the class with destructor
{
    delete a;
    delete b;
    delete c;
    delete d;
    delete e;
    delete f;
    delete g;
    delete h;
    delete i;
    delete j;
    delete k;
    delete grave;
    delete Ettin; // need to create virtual destructor when we get the chance
    delete jailer;
    delete warg;
    delete Goblin;
    delete ui;
}

MainWindow::MainWindow(const MainWindow &source){ //Deep Copy Constructor - memberwise assingment of member variables
    a = new Room();
    *a = *source.a;

    b = new Room();
    *b = *source.b;

    c = new Room();
    *c = *source.c;

    d = new Room();
    *d = *source.d;

    e = new Room();
    *e = *source.e;

    f = new Room();
    *f = *source.f;

    g = new Room();
    *g = *source.g;

    h = new Room();
    *h = *source.h;

    i = new Room();
    *i = *source.i;

    j = new Room();
    *j = *source.j;

    k = new Room();
    *k = *source.k;

    grave = new Room();
    *grave = *source.grave;

    Ettin = new Monster();
    *Ettin = *source.Ettin;

    jailer = new Monster();
    *jailer = *source.jailer;

    warg = new Monster();
    *warg = *source.warg;

    Goblin = new Monster();
    *Goblin = *source.Goblin;

    elf = source.elf;
    parser = source.parser;
}
//To perform porper memory management on the room objects while keeping them pointers i should include the rooms
// as mamber variables of the class so i can destroy them in the destructor.
void MainWindow::createRooms(){
    // True = Room locked / False = Room open
    //name of item - weapon check - potion check - key check - weight - damage

    a = new Room("Prison", ":/images/Images/prison2.jpg", true, "\nThe jail is a small room with nothing but a small window passing in the cold breeze of the night air, and a rusty jail door with a keyhole.\n");
    a->addItem(Item("PrisonKey",false,false,true));

    b = new Room("Prison Passage",":/images/Images/jailescaped2.jpg",false,"\nA trechorous bridge leads over a deep raven that descends into darkness. Past the bridge and to the east there seems to be a stairs leading up to a metal door. To the north flickering fire light illuminates the cavern wall, the source of the light is close.\n");
    b->addItem(Item("club", true, false, false, 30, 25));

    c = new Room("Jailers Quaters", ":/images/Images/jailer.jpg",false,"\nThe illuminated cavern wall leads round a bend, until you discover the source of the light. You have now entered the jailers lair.\n");

    d = new Room("PrisonExit", ":/images/Images/roomd2.jpg", true,"\nYou pull on the heavy metal door, and it scrapes as it opens. Past the door a stones stairs leads upwards.\n");
    d->addItem(Item("roomKey", false, false, true, 1));

    e = new Room("Cellar", ":/images/Images/cellar.jpg",  false,"\nYou find yourself in a large cellar, the funiture is extremely large and the wine barrels enormous...this couldn't be a humans home...\n");
    e->addItem(Item("HealthPotion", false, true, false, 15));
    e->addItem(Item("AtticKey", false, false, true, 1));

    f = new Room("room", ":/images/Images/WARG.jpg", true,"\nYou push open the now unlocked door, scratch marks line the floors and walls as you step into the dark room. The smell of rotting flesh fills the air. On the opposite side of the room a shiny door glimmers.\n");

    g = new Room("Chamber", ":/images/Images/livingq.jpg",false,"\nYou finally leave the lower leaves of this strange place to find a large stone built chamber room, chains dangle from the impossibly high ceilings and horrifying ornaments decorate the walls.\n");
    g->addItem(Item ("ParchmentPaper",false,false,false,10));
    g->addItem(Item ("Chains",false,false,false,30));

    h = new Room("Attic", ":/images/Images/attic.jpg", true,"\nYou push open the now unlocked trap door into an attic, small compared to the rest of this place, but still huge compared to you. The room is jam packed with every bit and bob you could imagine.\n");
    h->addItem(Item ("gold",false,false,false,30));
    h->addItem(Item ("PocketWatch",false,false,false,5));
    h->addItem(Item ("Bauble",false,false,false,5));
    h->addItem(Item ("Rope",false,false,false,15));
    h->addItem(Item("ArmoryKey", false, false, true, 1));
    h->addItem(Item ("SpyGlass",false,false,false,10));
    h->addItem(Item ("Shell",false,false,false,5));
    h->addItem(Item ("candle",false,false,false,5));

    i = new Room("Kitchen", ":/images/Images/goblin.jpg", false,"\nAs you enter the kitchen, the smell of beef stew hits you as a pot of beef stew bubbles away.\n");

    j = new Room("EttinsHall", ":/images/Images/ETTIN.jpg", true,"\nYou push the extremely heavy doors open leading out of the chambers in hope of freedom, only to come face to face with your captor...\n");

    k = new Room("Armory", ":/images/Images/armory.jpg", true,"");
    k->addItem(Item("FlamingSword", true, false, false, 30, 100));

    grave = new Room("grave", ":/images/Images/goblin.jpg", true,"");

    //             (N, E, S, W)
    a->setExits(b, NULL, NULL, NULL);
    b->setExits(c,NULL , a,d );
    c->setExits(NULL, NULL, b, NULL);
    d->setExits(e, b, NULL,NULL);
    e->setExits(g,NULL , d, f);
    f->setExits(NULL, e, NULL, k);
    g->setExits(j, h, e, i);
    h->setExits(NULL, NULL, NULL, g);
    i->setExits(NULL, g, NULL, NULL);
    j->setExits(NULL, NULL,g, NULL);
    k->setExits(NULL, f, NULL,NULL);

    grave->setExits(NULL, NULL, NULL, NULL);

    //Set heros starting position in game
    elf.setCurrentRoom(a);
    //Need to postion them in such a way that easy mosters at start and harder ones at the end
    //Weapon selection -------- Held in monsters inventorys --------//
    //name of item - weapon check - potion check - key check - weight - damage
    Item weapon1("Maul",true, false, false, 10, 110);
    Item weapon2("GreatAxe",true, false, false, 25, 35);
    Item weapon3("Claws",true, false, false, 60, 45);
    Item weapon4("Spear",true, false, false, 30, 45);
    Item weapon5("Moonblade",true, false, false, 100, 8);
    Item weapon6("LuckBlade",true, false, false, 100, 9);
    Item cloth("Cloth",false, false, false, 20);
    Item Tusk("Tusk",false, false, false, 20);
    // Types of food ---------------------------------
    Item food1("HumblePie", false, true, false,15);
    Item food2("Meat", false, true, false,10);
    Item food3("ElvenBread", false, true, false,10);
    Item food4("BeefStew", false, true, false,10);
    Item food5("RoastChicken", false, true, false,10);
    // All keys for locked rooms
    Item fur("fur",false,false,false,15);
    Item eKey("eKey",false,false,true,1);
    Item fKey("fKey",false,false,true,1);
    Item hKey("hKey",false,false,true,1);
    Item PrisonExitKey("PrisonExitKey",false,false,true,1);
    Item EttinsHallKey("EttinsHallKey", false, false, true, 1);

    Ettin = new Monster("Ettin",weapon1,Tusk,cloth);
    Ettin->setCurrentRoom(j);
    globalMonsters[0] = *Ettin;

    jailer = new Monster("Jailer",weapon2,cloth,PrisonExitKey);
    jailer->setCurrentRoom(c);
    globalMonsters[1] = *jailer;

    warg = new Monster("Warg",food2,fur,weapon3);
    warg->setCurrentRoom(f);
    globalMonsters[2] = *warg;

    Goblin = new Monster("Goblin",weapon4,food4,EttinsHallKey);
    Goblin->setCurrentRoom(i);
    globalMonsters[3] = *Goblin;
}

int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}

void MainWindow::processCommand(Command command){

    QString commandWord = command.getCommandWord();
    if (commandWord.compare("info") == 0)
        printHelp();

    else if (commandWord.compare("go") == 0){
        goRoom(command);
    }

    else if (commandWord.compare("take") == 0){
        if (!command.hasSecondWord()){
            ui->plainTextEdit->appendPlainText("incomplete input");
        }
        else if (command.hasSecondWord()){
            QString item = command.getSecondWord();
            int index = elf.getCurrentRoom()->isItemInRoom(item);
            if(index != -1){ // check to see the item is the room and gives the index/location
                bool temp = elf.addItem(elf.getCurrentRoom()->getItem(index)); // add the item to the characters inventory
                if(temp){
                    elf.getCurrentRoom()->removeItemFromRoom(item);// remove the item from the rooms inventory
                    ui->plainTextEdit->appendPlainText(item + " was picked up");
                    ui->plainTextEdit->appendPlainText(elf.getCurrentRoom()->displayItem());
                }
                else{
                    ui->plainTextEdit->appendPlainText("cannot add " + item + " to the bag there is not enough room");
                }
            }else{
                ui->plainTextEdit->appendPlainText("That item does not exist");
            }
        }
    }
    else if (commandWord.compare("quickTake") == 0){
        if(elf.getCurrentRoom()->numberOfItems() != 0){ //Makes sure theres items in the room to pick up!
            bool temp = elf.addItem(elf.getCurrentRoom()->getItem(0)); //Adds item from index one in room into characters inventory
            QString itemName = elf.getCurrentRoom()->getItem(0).getShortDescription();
            if(temp){
                ui->plainTextEdit->appendPlainText(itemName + " was picked up");
                elf.getCurrentRoom()->removeItemFromRoom(itemName);// remove the item from the rooms inventory
                ui->plainTextEdit->appendPlainText(elf.getCurrentRoom()->displayItem());
            } else {
                ui->plainTextEdit->appendPlainText("cannot add " + itemName + " to the bag there is not enough room");
            }

        } else {
            ui->plainTextEdit->appendPlainText("Theres nothing here");
        }
    }
    else if (commandWord.compare("quickDrop") == 0){
        if(elf.getInventory().getInventory().size() != 1){ // Need to keep the map item
            Item* temp = elf.getInventory().getItem(1);
            elf.dropItem(temp);
            ui->plainTextEdit->appendPlainText(temp->getShortDescription() + " was dropped in " + elf.getCurrentRoom()->shortDescription());
            ui->plainTextEdit->appendPlainText(elf.getCurrentRoom()->displayItem());
        } else {
            ui->plainTextEdit->appendPlainText("You cannot drop your trusty map.");
        }
    }
    else if (commandWord.compare("quickEat") == 0){
        bool event;
        vector<Item> tempList = elf.getInventory().getInventory();
        for(auto x: tempList){
            event = elf.consumeFood(x.getShortDescription());
            if(event){
                ui->progressBar->setValue(elf.getHealth());
                ui->plainTextEdit->appendPlainText("You have eaten " + x.getShortDescription() + " and are now back to 100 percent health" );
                break;
            }
        }
    }

    else if(commandWord.compare("inventory") == 0){

        ui->plainTextEdit->appendPlainText("Items in your bag: ");

        vector<Item> tempList = elf.getInventory().getInventory();
        for(auto x: tempList){
            ui->plainTextEdit->appendPlainText(x.getShortDescription());
        }

    }

    else if(commandWord.compare("drop") == 0){
        dropItem(command);
    }

    else if(commandWord.compare("fight") == 0){
        if(elf.getCurrentRoom()->getDoorType()){
            for(Monster &monsterType : globalMonsters){

                if(elf.getCurrentRoom()->shortDescription() == monsterType.getCurrentRoom()->shortDescription()){
                    //Player attacks
                    monsterType.setHealth<int>(monsterType.getHealth() - elf.combat());

                    QString intCombatToQString = QString::number(elf.combat());
                    ui->progressBar_2->setValue(monsterType.getHealth());

                    ui->plainTextEdit->appendPlainText("The " + monsterType.getName() + " has been hit for " + intCombatToQString + " damage");

                    //Monster attacks
                    elf.setHealth<double>(elf.getHealth() - monsterType.combat());

                    QString intCombatToQString2 = QString::number(monsterType.combat());
                    ui->progressBar->setValue(elf.getHealth());
                    ui->plainTextEdit->appendPlainText("The " + monsterType.getName() + " has hit you for " + intCombatToQString2 + " damage");
                    //Check player to see if they are alive
                    if(!elf.aliveCheck()){
                        elf.setHealth(0);
                        ui->progressBar->setValue(elf.getHealth());
                        ui->plainTextEdit->appendPlainText("you have been killed by the " + monsterType.getName());
                        sleep(2);
                        QApplication::quit();
                    }
                    //Check monster to see if they are alive
                    if(!monsterType.aliveCheck()){ //when the monsters health is 0 or below
                        monsterType.setHealth(0);
                        ::end++;
                        ui->progressBar_2->setValue(monsterType.getHealth());
                        ui->plainTextEdit->appendPlainText("The " + monsterType.getName() + " has been slayed");
                        ui->pushButton_5->hide();
                        monsterType.dropInventory(); // Drop items in the room after death
                        elf.getCurrentRoom()->setDoorType(false); // room has been unlocked
                        ui->plainTextEdit->appendPlainText("The room has now been unlocked you are free to leave");
                        ui->plainTextEdit->appendPlainText("The " + monsterType.getName() + "s items can now be picked up");
                        monsterType.setCurrentRoom(grave); // graveyard
                        ui->plainTextEdit->appendPlainText(elf.getCurrentRoom()->longDescription());
                        sleep(1);
                        int HroomLabel = ui->roomLabel->height();
                        int WroomLabel = ui->roomLabel->width();
                        QPixmap room(":/images/Images/gravestone.PNG");
                        ui->roomLabel->setPixmap(room.scaled(WroomLabel,HroomLabel,Qt::KeepAspectRatio));
                        ui->progressBar_2->hide();
                        if(::end==4){
                            ui->plainTextEdit->appendPlainText("You have killed the Ettin and escaped!");
                            sleep(2);
                            QApplication::quit();
                        }
                    }
                }
            }
        } else {
            ui->plainTextEdit->appendPlainText("There is no enemy to fight in this room");

        }
        if(Ettin->getCurrentRoom()->shortDescription() == "grave"){
            ui->plainTextEdit->appendPlainText("Congratulations On Winning The Game");
            sleep(2);
            QApplication::quit();
        }
    }

    else if(commandWord.compare("eat") == 0){
        eatFood(command);
    }
}

/** COMMANDS **/
void MainWindow::printHelp(){
    ui->plainTextEdit->appendPlainText("valid inputs are");
    parser.showCommands();
}

void MainWindow::dropItem(Command command){

    if (!command.hasSecondWord()){
        ui->plainTextEdit->appendPlainText("incomplete input");
        return;
    }

    QString item = command.getSecondWord();
    if(item == "map"){
        ui->plainTextEdit->appendPlainText("Cant get rid of that!");
        return;
    }

    Item* temp = elf.getInventory().getItem(item);
    if(temp != NULL){
        elf.dropItem(temp);
        ui->plainTextEdit->appendPlainText(item + " was dropped in " + elf.getCurrentRoom()->shortDescription());
        ui->plainTextEdit->appendPlainText(elf.getCurrentRoom()->longDescription());
    } else {
        ui->plainTextEdit->appendPlainText("That item does not exist in your backpack");
    }
}

void MainWindow::eatFood(Command command){
    if (!command.hasSecondWord()){
        ui->plainTextEdit->appendPlainText("incomplete input");
        return;
    }
    QString foodType = command.getSecondWord();
    bool event = elf.consumeFood(foodType);
    if(event){
        ui->progressBar->setValue(elf.getHealth());
        ui->plainTextEdit->appendPlainText("You have eaten " + foodType + " and are now back to 100 percent health");
    } else {
        ui->plainTextEdit->appendPlainText("The food you have choosen to eat does not exist and your health remains unchanged");
    }
}

void MainWindow::goRoom(Command command){ 
    QString direction = command.getSecondWord();
    Room *nextRoom = elf.getCurrentRoom()->nextRoom(direction);
    if(elf.getCurrentRoom()->getDoorType()){
        if(elf.getInventory().getItem(elf.getCurrentRoom()->shortDescription() + "Key") != NULL){
            ui->plainTextEdit->appendPlainText("The door is locked you need a key to open it");
            ui->plainTextEdit->appendPlainText("unlock the door with your key");
            Command *command = parser.getCommand("open");
            elf.useKey(elf.getCurrentRoom());
            ui->plainTextEdit->appendPlainText(elf.getCurrentRoom()->shortDescription() + " " + " has been opened with your key");
        }else {
            if(elf.getCurrentRoom()->shortDescription() != "Prison"){
                ui->plainTextEdit->appendPlainText("The room is locked you must fight the monester to get out");
            } else{
                ui->plainTextEdit->appendPlainText("The prison door is locked and wont budge.");
            }

        }
    }

    else if(nextRoom == NULL){
        ui->plainTextEdit->appendPlainText("You cannot go that way.");
    }

    else if(nextRoom->getDoorType()){
        ui->plainTextEdit->appendPlainText("The door is locked you need a key to open it");
        QString roomName = nextRoom->shortDescription();
        if(elf.getInventory().getItem(roomName + "Key") != NULL){
            ui->plainTextEdit->appendPlainText("unlock the door with your key");
            Command *command = parser.getCommand("open");
            QString commandWord = command->getCommandWord();
            elf.useKey(nextRoom);  //Open door and remove key from inventory
            ui->plainTextEdit->appendPlainText(roomName + " " + " has been opened with your key");
        }
    }
    else{
        //If the exit was not set as null then the current room is updated
        elf.setCurrentRoom(nextRoom);

        int HroomLabel = ui->roomLabel->height();
        int WroomLabel = ui->roomLabel->width();

        ui->roomLabel->setPixmap(elf.getCurrentRoom()->getPixmap().scaled(WroomLabel,HroomLabel,Qt::KeepAspectRatio));
        ui->plainTextEdit->appendPlainText(elf.getCurrentRoom()->longDescription());
        //To look through all monsters to check their positions
        for(Monster &monsterType : ::globalMonsters){
            if(elf.getCurrentRoom()->shortDescription() == monsterType.getCurrentRoom()->shortDescription()){
                ui->pushButton_5->show();
                ui->progressBar_2->setValue(monsterType.getHealth());
                ui->progressBar_2->show();
                ui->plainTextEdit->appendPlainText("You have entered a room where a " + monsterType.getName() + " has been sleeping. But you have awoken it and you must fight");
                elf.getCurrentRoom()->setDoorType(true); // room has locked
                if(!monsterType.aliveCheck()){ //when the monsters health is 0 or below
                    elf.getCurrentRoom()->setDoorType(false); // room has been unlocked
                    ui->plainTextEdit->appendPlainText("The room has now been unlocked you are free to leave");
                }
            }
        }
    }
}

void MainWindow::on_lineEdit_returnPressed()
{
    QString userInput = ui->lineEdit->text();
    ui->lineEdit->clear();
    string text = userInput.toLocal8Bit().constData();

    Command *command  = parser.getCommand(text);
    processCommand(*command);
}

void MainWindow::on_pushButton_clicked()
{
    Command *command  = parser.getCommand("go north");
    processCommand(*command);


}

void MainWindow::on_pushButton_2_clicked()
{
    Command *command  = parser.getCommand("go west");
    processCommand(*command);


}

void MainWindow::on_pushButton_3_clicked()
{
    Command *command  = parser.getCommand("go east");
    processCommand(*command);


}

void MainWindow::on_pushButton_4_clicked()
{
    Command *command  = parser.getCommand("go south");
    processCommand(*command);


}

void MainWindow::on_pushButton_5_clicked()
{
    Command *command  = parser.getCommand("fight");
    processCommand(*command);

}


void MainWindow::on_InventoryButton_clicked()
{
    Command *command  = parser.getCommand("inventory");
    processCommand(*command);

}

void MainWindow::on_quickTakeButton_clicked()
{
    Command *command  = parser.getCommand("quickTake");
    processCommand(*command);
}

void MainWindow::on_quickDrop_clicked()
{
    Command *command  = parser.getCommand("quickDrop");
    processCommand(*command);
}



void MainWindow::on_quickEat_clicked()
{
    Command *command  = parser.getCommand("quickEat");
    processCommand(*command);

}
