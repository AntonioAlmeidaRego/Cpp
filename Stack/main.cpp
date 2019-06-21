/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: antonioalmeida
 *
 * Created on 20 de Junho de 2019, 23:23
 */

#include <iostream>

#include "Stack.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    Stack *pilha = new Stack();
    pilha->push(5, 'A');
    pilha->push(9, 'E');
    pilha->push(6, 'F');
    pilha->push(78, 'G');
    pilha->print();
    return 0;
}

