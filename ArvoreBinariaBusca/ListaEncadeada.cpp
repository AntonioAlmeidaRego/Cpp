/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ListaEncadeada.cpp
 * Author: antonio
 * 
 * Created on 24 de Março de 2019, 21:06
 */

#include <iostream>
#include "ListaEncadeada.h"
using namespace std;


ListaEncadeada::ListaEncadeada() {
    tam = 0;
    this->nocabeca = new Node();
    this->nocabeca->setProx(NULL);
}

bool ListaEncadeada::isempty() {
    if(nocabeca->getprox() == NULL){
        return true;
    }
    return false;
}
ListaEncadeada::ListaEncadeada(const ListaEncadeada& orig) {
}

ListaEncadeada::~ListaEncadeada() {
}

Node* ListaEncadeada::noCabeca() {
    return this->nocabeca;
}


void ListaEncadeada::inserir(int chave) {
    Node *n = new Node();
    tam++;
    n->setChave(chave);
    if(isempty()){
        nocabeca->setProx(n);
        n->setProx(NULL);
    }else{
        Node *aux = nocabeca->getprox();
        nocabeca->setProx(n);
        n->setProx(aux);
    }
}

int ListaEncadeada::size() {
    return tam;
}


Node* ListaEncadeada::remove() {
    Node *aux = nocabeca->getprox();
    nocabeca->setProx(aux->getprox());
    return aux;
}

void ListaEncadeada::print() {
    Node *aux = nocabeca->getprox();
    while(aux != NULL){
        cout << aux->getchave() << " ";
        aux = aux->getprox();
    }
}




