#include <iostream>
#include <stdio.h>
#define RED "\x1b[31m";
#define GREEN "\x1b[32m";
#define BLUE "\x1b[34m";
#define WHITE "\x1b[37m";

using namespace std;

void BasicRules()
{
    cout << "\e[2J\e[H";
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    cout << "             Rules to save the reality : \n";
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    cout << RED;
    std::string first = "You have one move, so think carefully, after you, your nemesis plays";
    cout << "This is the battle for reality, Dr strange can't help you" << endl;
    cout << "Your senses have to be heightened, in such a way that...." << endl;
    cout << " after you make a move, you have to make sure, 4 of them connect" << endl;
    cout << " in atleast one of the eight directions!!!" << endl;
    cout << WHITE;
    cout << "Press Enter to continue";
    std::cin.get();
}