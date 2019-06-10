/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   No.cpp
 * Author: antonio
 * 
 * Created on 4 de Abril de 2019, 11:13
 */

#include "No.h"
/*
 Arquivo No.cpp
 */

/*
 construtor
 */
No::No() {
    // inicializo o ponteiro como null
    this->prox = nullptr;
}

No::No(const No& orig) {
}

No::~No() {
}
/*
 Retorno o nó 
 */
Node* No::getInfo() {
    return this->info;
}

/*
 retorno o nó proximo
 */

No* No::getprox() {
    return this->prox;
}
/*
 Passo o novo nó
 */
void No::setInfo(Node* info) {
    this->info = info;
}

/*
 
 Passo o novo nó para ser apontado
 */

void No::setprox(No* prox) {
    this->prox = prox;
}





