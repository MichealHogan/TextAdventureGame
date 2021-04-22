#include "commandwords.h"

//private by default
vector<string> CommandWords::validCommands;

/**
 * Constructor - initialise the command words.
 */
CommandWords::CommandWords() {
    // Populate the vector if we haven't already.
    if (validCommands.empty()) {
        validCommands.push_back("go");
        validCommands.push_back("quit");
        validCommands.push_back("info");
        validCommands.push_back("map");
        validCommands.push_back("take");
        validCommands.push_back("quickTake");
        validCommands.push_back("inventory");
        validCommands.push_back("open");
        validCommands.push_back("drop");
        validCommands.push_back("fight");
        validCommands.push_back("eat");
        validCommands.push_back("quickDrop");
        validCommands.push_back("quickEat");
    }
}
/**
 * Check whether a given String is a valid command word.
 * Return true if it is, false if it isn't.
 **/
bool CommandWords::isCommand(string aString) {
    for (unsigned int i = 0; i < validCommands.size(); i++)
    {
        if (validCommands[i].compare(aString) == 0)
            return true;
    }
    // if we get here, the string was not found in the commands
    return false;
}

/*
 * Print all valid commands to System.out.
 */
QString CommandWords::showAll() {
    //Loops through validCommands and prints each to the screen.
    QString temp {""};
    for (unsigned int i = 0; i < validCommands.size(); i++)
    {
        temp += QString::fromStdString(validCommands[i]) + "/n";
    }
    return temp;
    cout << endl;
}
