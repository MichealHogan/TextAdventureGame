#include "parser.h"

Parser::Parser() {
    commands = new CommandWords();
}

Parser::Parser(const Parser &source){ //Deep Copy Constructor
    commands = new CommandWords;
    *commands = *source.commands;
}

Command* Parser::getCommand(string input) {
    string word1;
    string word2;
    vector<string> words;
    string::size_type pos = 0, last_pos = 0;

    // Break "input" up by spaces
    bool finished = false;
    while (!finished) {
        pos = input.find_first_of(' ', last_pos);    // find and remember first space.
        if (pos == string::npos ) {            // if we found the last word,
            words.push_back(input.substr(last_pos));    // add it to vector "words"
            finished = true;                // and finish searching.
        } else {                    // otherwise add to vector and move on to next word.
            words.push_back(input.substr(last_pos, pos - last_pos));
            last_pos = pos + 1;
        }
    }

    if (words.size() == 1)
        word1 = words[0];
    else if (words.size() >= 2) {
        word1 = words[0];
        word2 = words[1];
    }

    // note: we just ignore the rest of the input line.
    // Now check whether this word is known. If so, create a command with it.
    // If not, create a "nil" command (empty string for unknown command).

    if (commands->isCommand(word1))
        return new Command(word1, word2);
    else
        return new Command("", word2);
}

/**
 * Print out a list of valid command words.
 */
void Parser::showCommands() {
    commands->showAll();
}
