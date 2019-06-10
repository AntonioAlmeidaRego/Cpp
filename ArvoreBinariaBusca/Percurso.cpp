/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Percurso.cpp
 * Author: antonio
 * 
 * Created on 21 de Março de 2019, 20:20
 */
#include <iostream>
#include "Percurso.h"
#include "No.h"
using namespace std;
Percurso::Percurso() {
}

Percurso::Percurso(const Percurso& orig) {
}

Percurso::~Percurso() {
}

void Percurso::preOrdem(No *n){
    visitor(n);
    cout << "--> Altura: " << altura(n) << "; ";
    if(n->getleft() != NULL){
        preOrdem(n->getleft());
    }
    if(n->getright() != NULL){
        preOrdem(n->getright());
    }
}

void Percurso::posOrdem(No* r){
    if(r->getleft() != NULL){
        posOrdem(r->getleft());
    }
    if(r->getright() != NULL){
        posOrdem(r->getright());
    }
    visitor(r);
    cout << "--> Altura: " << altura(r) << "; ";
}

void Percurso::ordemSimetrica(No* r){
    if(r->getleft() != NULL){
        ordemSimetrica(r->getleft());
    }
    visitor(r);
    cout << "--> Altura: " << altura(r) << "; ";
    if(r->getright() != NULL){
        ordemSimetrica(r->getright());
    }
}

int Percurso::altura(No* n) {
    int altE, altD, max;
    
    if(n == NULL){
        return 0;
    }
    altE = altura(n->getleft());
    altD = altura(n->getright());
    
    if(altE > altD){
        max = altE + 1;
    }else{
        max = altD + 1;
    }
    
    return max;
}

void Percurso::visitor(No *n){
    cout << n->getchave() <<" "; 
}
