/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NoStack.cpp
 * Author: antonio
 * 
 * Created on 21 de Maio de 2019, 15:18
 */

#include "NoStack.h"
/*Classe NoStack.cpp*/
/*Construtor*/
NoStack::NoStack() {
    this->ant = nullptr;// inicializo o nó anterior com o nullptr
    this->prox = nullptr; // inicializo o nó proximo com o nullptr
    this->chave = 0; // inicializo a chave com 0
}

NoStack::NoStack(const NoStack& orig) {
}

NoStack::~NoStack() {
}

/*
 Retorna a chave
 */
int NoStack::getchave() {
    return this->chave;
}
/*
 Retorna o proximo nó
 */

NoStack* NoStack::getprox() {
    return this->prox;
}
 
/*
 Passa o nova chave
 */
void NoStack::setchave(int ch) {
    this->chave = ch;
}

/*
 Passa o novo nó para o proximo
 */
void NoStack::setprox(NoStack* stack) {
    this->prox = stack;
}
/*
 Retorno o nó anterior
 */
NoStack* NoStack::getant() {
    return this->ant;
}

/*
 Passo o novo nó anterior
 */
void NoStack::setant(NoStack* stack) {
    this->ant = stack;
}
 


 
 
