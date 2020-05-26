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

const int NUMBER_OF_SCENARIOS = 42;
const int SLOW_TEXT_SPEED = 400; // speed = 400 ms per letter
const int MED_TEXT_SPEED = 175; // speed = 175 ms per letter
const int FAST_TEXT_SPEED = 100; // speed = 100 ms per letter

vector<Scenario> scenes;
string endings[5];
int ending = 0;

static void slowPrint(const string& str, int delay_time) { // prints out strings slowly (with time between letters)
    for (size_t i = 0; i != str.size(); ++i) {
        cout << str[i];
        this_thread::sleep_for(chrono::milliseconds(delay_time)); // delays between each letter
    }
    cout << endl;
}

void readfile() {
    
    ifstream fin("text.txt");
    
    for(int i = 0; i < NUMBER_OF_SCENARIOS; i++) {
        
        string text; int choices;
        getline(fin, text);
        fin >> choices;
        
        string temp;
        getline(fin, temp);
        
        string textChoices[choices]; int numChoices[choices];
        for(int j = 0; j < choices; j++) getline(fin, textChoices[j]);
        for(int j = 0; j < choices; j++) fin >> numChoices[j];
        
        fin >> temp;
        
        Scenario scene(text, choices, textChoices, numChoices);
        scenes.push_back(scene);
    }
    
}

void readendings() {
    
    ifstream ein("end.txt");
    
    for(int i = 0; i < 5; i++) {
        
        string text;
        getline(ein, text);
        endings[i] = text;
        
    }

}

void printScene(int cur) {
    scenes[cur].printText();
    scenes[cur].printChoices();
}

void playGame(int cur) {
    
    cout << endl;
    printScene(cur);
    
    if(scenes[cur].ending()) {
        ending = cur;
        return;
    }
    
    int input = 0; cin >> input;
    while(input < 1 || input > scenes[cur].getSize()) {
        cout << input << " is not a valid response, please enter a valid choice" << endl;
        cin >> input;
    }
    playGame(scenes[cur].goNext(input-1));
    
}

int main() { // main method

    srand(time(NULL));
    readfile();
    readendings();
    
    scenes[0].printText();
    string temp; cin >> temp;
    cin.clear();
    
    int startingScene = rand()%5 + 1;
    playGame(startingScene);
    
    switch(ending) {
        case 10: case 16: case 20: // bad ending, death and unfortunate circumstances
            slowPrint(endings[0], MED_TEXT_SPEED);
            break;
        case 15: case 17: case 24: case 31: case 32: case 34: // classic ending, indirect/direct affect of immigration
            slowPrint(endings[1], MED_TEXT_SPEED);
            break;
        case 30: case 37: case 38: // decent ending, hatred for immigrants and promotion of nativism
            slowPrint(endings[2], MED_TEXT_SPEED);
            break;
        case 36: case 39: // decent ending, with the immigrant finding an ok life
            slowPrint(endings[3], MED_TEXT_SPEED);
            break;
        case 41: // true ending, my story
            slowPrint(endings[4], MED_TEXT_SPEED);
            break;
        default:
            cout << "Something went wrong, you shouldn't be able to see this" << endl;
            break;
    }
    
    cout << "Looks like ya finished playing. Hope you enjoyed it!" << endl;
    return 0;
    
}
