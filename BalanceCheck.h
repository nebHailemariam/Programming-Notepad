//
// Created by USER on 12/8/2017.
//

#ifndef BALANCEDCHECK_BALANCECHECK_H
#define BALANCEDCHECK_BALANCECHECK_H
#include <iostream>
#include <string.h>
using namespace std;

class BalanceCheck {

protected:struct node{
        char data;
        node *nxt;
    };
protected: string string1;
protected: node *headPtr;
public:BalanceCheck();

private:
    char pop();
    void push(char val);
    bool isEmpty();
    char ending();
public:
    int balancedCheck(string string1);
};



#endif //BALANCEDCHECK_BALANCECHECK_H
