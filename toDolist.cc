#include <fstream>
#include <iostream>

#include "toDoList.h"

using namespace std;

void toDoList::loadGoals(string txt){
    string x;
    int i = 1;    
    ifstream storeFi(txt);
    while(getline(storeFi, x)){
        ta[x] = i;
        ++i;
    }
}

void toDoList::addGoal(string g, int num){
    ta[g] = num;
    ++goalsNumber;
}

void toDoList::deleteGoal(string g){    
    int x = ta.find(g)->second;
    ta.erase(g);
    if(!ta.empty()){
        for(auto it: ta){
            --it.second;
        }

    }    
}

void toDoList::storeGoals(string txt){
    ofstream storedFile(txt);
    for(auto it: ta){
        storedFile << it.first << endl;
    }

}

void toDoList:: showGoals(string txt){
    ifstream printedFile(txt);
    string x;
    int n = 1;
    while(getline(printedFile, x)){
        cout << n << ". " << x << endl;
        ++n;
    }

}

string toDoList::findGoal(int num){
    string a = "nothing";
    for(auto it: ta){
        if(it.second == num){
            a = it.first;
        }
    }
    return a;
}


