/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: antonioalmeida
 *
 * Created on 20 de Junho de 2019, 22:54
 */

#include <iostream>
#include "Queue.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    Queue *fila = new Queue();
    fila->enqueue(5, 'A');
    fila->enqueue(6, 'R');
    fila->enqueue(9, 'G');
    fila->enqueue(10, 'K');
    fila->enqueue(45, 'J');
    fila->print();
    return 0;
}

