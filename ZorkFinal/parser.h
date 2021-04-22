#ifndef PARSER_H_
#define PARSER_H_

#include "command.h"
#include "commandwords.h"

class Parser {
private:
    CommandWords *commands; //pointer a commandWords object

public:
    Parser();
    Parser(const Parser &source); //Deep Copy Constructor
    ~Parser(){
        delete commands;
    }
    Command* getCommand(string input);
    void showCommands();
};
#endif /*PARSER_H_*/
