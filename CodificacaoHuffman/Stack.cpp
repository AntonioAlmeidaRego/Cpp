/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   Stack.cpp
 * Author: antonio
 *
 * Created on 7 de Abril de 2019, 17:45
 */
#include <iostream>
#include "Stack.h"
#include "Ascii.h"
#include "Percurso.h"
using namespace std;

Stack::Stack() {
    this->nocabeca = new NoAscii();
    this->nocalda = new NoAscii();
    size = 0;
    this->nocabeca->setprox(nocalda);
    this->nocabeca->setant(nocalda);
    this->nocalda->setprox(nocabeca);
    this->nocalda->setant(nocabeca);
}

Stack::Stack(const Stack& orig) {
}

Stack::~Stack() {
}

bool Stack::empty() {
    if(nocabeca->getprox() == nocalda){
        return true;
    }
    return false;
}

bool Stack::notrepet(wchar_t info) {
    NoAscii *aux = nocabeca->getprox();
    while(aux != nocalda){
        if(aux->getinfo() != info){
            aux = aux->getprox();
        }else{
            return false;
        }
    }
    return true;
}


void Stack::push(string cod, wchar_t info) {
    size++;
    NoAscii *n = new NoAscii();
    n->setinfo(info);
    n->setcodigo(cod);
    if(empty()){
        nocabeca->setprox(n);
        n->setant(nocabeca);
        n->setprox(nocalda);
        nocalda->setant(n);
    }else{
        NoAscii *aux = nocalda->getant();
        nocalda->setant(n);
        aux->setprox(n);
        n->setprox(nocalda);
        n->setant(aux);
    }
}

NoAscii* Stack::pop() {
    size--;
    NoAscii * aux = nocalda->getant();
    NoAscii * ant = aux->getant();
    nocalda->setant(ant);
    ant->setprox(nocalda);
    return aux;
}

void Stack::push(string cod) {
    NoAscii *n = new NoAscii();
    n->setcodigo(cod);
    if(empty()){
        nocabeca->setprox(n);
        n->setant(nocabeca);
        n->setprox(nocalda);
        nocalda->setant(n);
    }else{
        NoAscii *aux = nocalda->getant();
        nocalda->setant(n);
        aux->setprox(n);
        n->setprox(nocalda);
        n->setant(aux);
    }
}

string Stack::code() {
    string codigo = "";
    NoAscii *aux = nocabeca->getprox();

    while(aux != nocalda){
        codigo += aux->getcodigo();
        aux = aux->getprox();
    }
    return codigo;
}


string Stack::codes(wchar_t info) {
    string codigo = "";
    NoAscii *aux = nocabeca->getprox();

    while(aux != nocalda){
        if(aux->getinfo() == info){
            codigo = aux->getcodigo();
        }
        aux = aux->getprox();
    }

    return codigo;
}

void Stack::print() {
    NoAscii *aux = nocabeca->getprox();
    while(aux != nocalda){
        cout << aux->getcodigo() << " " << aux->getinfo() << " ";
        aux = aux->getprox();
    }
}




