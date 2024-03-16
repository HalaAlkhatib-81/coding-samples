#ifndef TODOLIST_H
#define TODOLIST_H

#include <iostream>
#include <map>
#include <fstream>

using namespace std;

class toDoList
{
private:
    int goalsNumber;
    map<string, int> ta;

public:
    toDoList(int gNumber, map<string, int>& t);
    ~toDoList();
    void loadGoals(string txt);
    void addGoal(string g, int num);
    void deleteGoal(string g);
    void storeGoals(string txt);
    void showGoals(string txt);
    string findGoal(int num);
};

toDoList::toDoList(int gNumber, map<string,int>& t){
    this->goalsNumber = gNumber;
    this->ta = t;
}

toDoList::~toDoList(){
    for(auto it: this ->ta){
        this-> ta.erase(it.first);
    }

    this -> goalsNumber = 0;
}



#endif