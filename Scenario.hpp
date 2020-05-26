//
//  Scenario.hpp
//  apush_final_project
//
//  Created by Max Yeh on 5/22/20.
//  Copyright © 2020 Max Yeh. All rights reserved.
//
#include <iostream>
#include <fstream>
#include <chrono>
#include <thread>
#include <string>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <vector>
#include <iomanip>
using namespace std;

/*
 * Scenario class is a class that contains a scenario a player can be in.
 * It has the text that is meant to be outputed as well as the choices, with each choice having its
 * respective next scenario.
 * It also can be an ending, so there is a boolean that checks whether or not it's an end
 */

class Scenario {
    
public:
    Scenario(); // default constructor (not used)
    Scenario(string text, int c, string choices[], int next[]); // creating new Scenario
    bool ending(); // if it is ending or not
    int goNext(int choice); // next choice and following scenario
    int getSize();
    void printText(); // prints the current text
    void printChoices(); // prints all of the choices
    
    
private:
    string curText; // current text
    int choices; // number choices
    bool isEnd; // if it is ending
    vector<string> textChoice; // choices
    vector<int> nextScenario; // respective scenarios
    
};
