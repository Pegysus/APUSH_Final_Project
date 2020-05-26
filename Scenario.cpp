//
//  Scenario.cpp
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
#include "Scenario.hpp"
using namespace std;

const int SLOW_TEXT_SPEED = 400; // speed = 400 ms per letter
const int MED_TEXT_SPEED = 175; // speed = 175 ms per letter
const int FAST_TEXT_SPEED = 100; // speed = 100 ms per letter

static void slowPrint(const string& str, int delay_time) { // prints out strings slowly (with time between letters)
    for (size_t i = 0; i != str.size(); ++i) {
        cout << str[i];
        this_thread::sleep_for(chrono::milliseconds(delay_time)); // delays between each letter
    }
    cout << endl;
}

Scenario::Scenario() {
    
}

Scenario::Scenario(string text, int c, string choices[], int next[]) {
    curText = text;
    this->choices = c;
    for(int i = 0; i < c; i++) {
        nextScenario.push_back(next[i]);
        textChoice.push_back(choices[i]);
    }
    
    if(this->choices == 0) isEnd = true;
    else isEnd = false;
}

bool Scenario::ending() {
    if(isEnd) return true;
    return false;
}

int Scenario::getSize() { return choices; }

int Scenario::goNext(int choice) { return nextScenario[choice]; }

void Scenario::printText() {
    if(ending()) slowPrint(curText, 0);
    else slowPrint(curText, FAST_TEXT_SPEED);
    //slowPrint(curText, 0);
}

void Scenario::printChoices() {
    for(int i = 0; i < choices; i++) {
        string printText = to_string(i+1) + ") " + textChoice[i];
        slowPrint(printText, FAST_TEXT_SPEED);
        //slowPrint(printText, 0);
    }
}
