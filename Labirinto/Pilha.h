/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   Pilha.h
 * Author: robso
 *
 * Created on 25 de Julho de 2018, 09:52
 */


#ifndef PILHA_H
#define PILHA_H
#include <iostream>
#include "Celula.h"
#include "Pilha.h"

using namespace std;
class Pilha {
public:
    Pilha(){
        topo = NULL;
        tam = 0;
    }
    Pilha(int l, int c){
        topo = new Celula(l, c);
        tam = 0;
    }
    bool VAZIA();
    void empurrar(int l, int c);
    Celula* pop();
    Celula* pegaT();
    int tamanho();
    void show();
private:
     Celula *topo; //aponta para o topo
     int tam;
};


int Pilha::tamanho(){
    return this->tam;
}

bool Pilha::VAZIA(){
    return (topo == NULL); // caso a pilha esteja vazia, retorna o topo que recebe o valor nulo (nota a diferença entre "=" e "==").
}

void Pilha::empurrar(int l, int c){
    Celula* cell2 = new Celula(l, c); //cell recebe uma nova celula que será alocada

    if(VAZIA()){
        topo = cell2; //o topo aqui será a nova célula
        tam = tam + 1;
    }
    else{
        cell2->setProx(topo); //nova cell será setada como topo
        topo = cell2;//topo será a nova cell
         tam = tam + 1;
    }
}

Celula* Pilha::pop(){
    if(!VAZIA()){
       tam = tam - 1;
       Celula *aux = topo;
       topo = topo->pegaProx();
       return aux;
    }
}

Celula* Pilha::pegaT(){
    return topo;
}

void Pilha::show(){
    Celula *t = topo;
    if(VAZIA())
        cout << "A PILHA ENCONTRA-SE VAZIA!" << endl;
    else{
        while(t){
            cout << t->pegaL() << " " << t->pegaC() << endl;
            t = t->pegaProx();
        }
    }
}


#endif /* PILHA_H */

