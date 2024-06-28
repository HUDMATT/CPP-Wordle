#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
using namespace std;

vector<string> wordleWords = { //Vector with 5 words starting with each letter
    "alien",
    "annex",
    "ascot",
    "aloof",
    "axion",
    "beach",
    "bezel",
    "borax",
    "burly",
    "butch",
    "chock",
    "clock",
    "crepe",
    "circa",
    "cloud",
    "daddy",
    "dunce",
    "duvet",
    "dwell",
    "diode",
    "enema",
    "epoxy",
    "extol",
    "endow",
    "elude",
    "fetid",
    "flair",
    "forum",
    "funky",
    "fiery",
    "globe",
    "gorge",
    "grave",
    "gusto",
    "gummy",
    "helix",
    "horde",
    "hydro",
    "hyena",
    "harsh",
    "ideal",
    "irate",
    "itchy",
    "ivory",
    "ingot",
    "jaunt",
    "juicy",
    "jumbo",
    "juror",
    "jazzy",
    "kappa",
    "khaki",
    "knife",
    "koala",
    "krill",
    "lemur",
    "leave",
    "loath",
    "loyal",
    "lusty",
    "muave",
    "metro",
    "miner",
    "minty",
    "muddy",
    "nylon",
    "novel",
    "nerve",
    "nasty",
    "niche",
    "onion",
    "opera",
    "owner",
    "oxide",
    "ozone",
    "pasty",
    "pinky",
    "polka",
    "pooch",
    "prank",
    "quail",
    "quote",
    "query",
    "quasi",
    "quack",
    "rabbi",
    "rhino",
    "ripen",
    "rocky",
    "rupee",
    "score",
    "shirk",
    "siege",
    "sight",
    "slice",
    "taboo",
    "thumb",
    "toxic",
    "turbo",
    "twang",
    "udder",
    "ulcer",
    "unzip",
    "unmet",
    "umbra",
    "vague",
    "voice",
    "viola",
    "vixen",
    "vouch",
    "wharf",
    "wryly",
    "wrong",
    "whale",
    "welsh",
    "yacht",
    "yeast",
    "yield",
    "youth",
    "young",
    "zebra",
    "zesty",
    "zonal",
};

int main()
{
RESTART: //Game will go to here in the code when 'r' is typed in the at the end of the game
    srand(time(0));
    int size = wordleWords.size();
    int randIndex = rand() % size; //Random index for the script vector
    string wordProgress = "?????";
    char restart;
    cout << "This is a Wordle Game in C++!\n";
    for (int i = 0; i < 6; ++i) {
        string inputWord;
        string letterWrongPlace;
        string wordCharCheck; /*Seperate string for checking char vals, to prevent case where user input is "spool", the correct word is "wrong"
                                would previously output ??o??, now outputs, ??o??
                                                        o                        */
    OUTRANGE: //Will go to here if more or less than 5 letters are put
        cout << "Please enter your 5 letter word as a guess, all lowercase please! \n";
        cin >> inputWord;
        wordCharCheck = wordleWords[randIndex];
        if (inputWord == "ch34t") { //Cheatcode to make it easy to debug
            cout << wordleWords[randIndex] << "\n";
            cout << "Please enter your 5 letter word as a guess, all lowercase please! \n";
            cin >> inputWord;
        }
        if (inputWord.size() != 5) {
            cout << "That word does not have only 5 letters!\n";
            goto OUTRANGE;
        }
        if (inputWord == wordleWords[randIndex]) {
            cout << "That was the correct word! You win!\n";
            goto WIN;
        }
        for (int j = 0; j < 5; ++j) {
            char charToFind = inputWord[j];
            bool charFound = false;
            if (inputWord[j] == wordleWords[randIndex][j]) {
                wordProgress[j] = inputWord[j];
                wordCharCheck.replace(j, 1, 1, '*');
            }
            else {
                for (char ch : wordCharCheck) { //Checks each char in string, then outputs to letterWrongPlace string
                    if (ch == charToFind) {
                        charFound = true;
                        break;
                    }
                }
                if (charFound == true) {
                    letterWrongPlace.push_back(inputWord[j]);
                }
            }
        }
        cout << wordProgress << "\n" << letterWrongPlace << "\n";
    }
    cout << "You didn't get it right, the correct word was " << wordleWords[randIndex] << "\n";
WIN:
    cout << "To restart the game, type 'r', to quit the game, type 'q' \n"; //Endgame conditions
    cin >> restart;
    if (restart == 'q')
        exit;
    else if (restart == 'r')
        goto RESTART;
}