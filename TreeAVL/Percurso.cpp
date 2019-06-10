/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Percurso.cpp
 * Author: antonio
 * 
 * Created on 20 de Abril de 2019, 20:18
 */
#include <iostream>
#include "Percurso.h"
using namespace std;
/*Classe Percuro.cpp*/
/*Construtor*/
Percurso::Percurso() {
}

Percurso::Percurso(const Percurso& orig) {
}

Percurso::~Percurso() {
}
/*Método que faz o percurso na Arvore Binaria*/
void Percurso::preordem(NodeAVL *n) {
    visitor(n);
    if(n->getleft() != nullptr){
        preordem(n->getleft());
    }
    if(n->getright() != nullptr){
        preordem(n->getright());
    }
}
/*Método que printa o nó visitado*/
void Percurso::visitor(NodeAVL* n) {
    if(n->getchave() != 0){
        cout <<" CH " << n->getchave() << " (" << n->getbal() << ")";
    }
}



