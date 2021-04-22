#ifndef COMMAND_H_
#define COMMAND_H_

#include <string>
#include <QString>
using namespace std;

class Command {
private:
    string commandWord;
    string secondWord;

public:
    Command(string firstWord, string secondWord);
    Command(const Command &source); //Shallow Copy Constructor
    QString getCommandWord();
    QString getSecondWord();
    bool isUnknown();
    bool hasSecondWord();
};

#endif /*COMMAND_H_*/
