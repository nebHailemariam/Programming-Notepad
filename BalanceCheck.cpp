//
// Created by USER on 12/8/2017.
//

#include "BalanceCheck.h"

BalanceCheck::BalanceCheck() {
    BalanceCheck::headPtr = NULL;
}

char BalanceCheck::ending() {
    node *temp = headPtr;
    if(headPtr != NULL){
        while(temp->nxt != NULL)
            temp =temp->nxt;
        return temp->data;
    }

    return '0';
}

bool BalanceCheck::isEmpty() {
    return headPtr == NULL;
}

void BalanceCheck::push(char val) {
    if(BalanceCheck::headPtr == NULL){
        BalanceCheck::headPtr = new node;
        BalanceCheck::headPtr->data = val;
        BalanceCheck::headPtr->nxt = NULL;
    }
    else{
        node *temp = BalanceCheck::headPtr;
        while(temp->nxt != NULL)
            temp = temp->nxt;
        temp->nxt = new node;
        temp->nxt->data = val;
        temp->nxt->nxt =NULL;
    }
}

char BalanceCheck::pop() {
    if(BalanceCheck::headPtr == NULL){
        return '0';
    }
    else{
        node *temp = BalanceCheck::headPtr;
        while(temp->nxt != NULL){
            temp = temp->nxt;
        }
        if(BalanceCheck::headPtr == temp){
            char val = temp->data;
            delete temp;
            BalanceCheck::headPtr = NULL;
            return val;
        }
        else{
            node *preTo = BalanceCheck::headPtr;
            while(preTo->nxt != temp)
                preTo = preTo->nxt;
            preTo->nxt = NULL;
            char val = temp->data;
            delete temp;
            return val;
        }
    }
}

int BalanceCheck::balancedCheck(string string1) {
    for (int i = 0; i < string1.length(); i++) {
        if (string1[i] == '{' or string1[i] == '}' or string1[i] == '(' or string1[i] == ')') {
            if (BalanceCheck::isEmpty()) {
                BalanceCheck::push(string1[i]);
            } else if (!isEmpty()) {
                if (string1[i] == '}' and '{' == ending()) {
                    BalanceCheck::pop();
                } else if (string1[i] == ')' and '(' == ending()) {
                    BalanceCheck::pop();
                } else {
                    BalanceCheck::push(string1[i]);
                }
            }

        }
    }
    if (isEmpty()) {
        return 0;
    } else {
        return 1;
    }
}
