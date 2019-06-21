/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "NoStack.h"


/*
 * File:   NoStack.cpp
 * Author: antonio
 *
 * Created on 6 de Abril de 2019, 13:25
 */

/*
 Construtor
 */

NoStack::NoStack() {
    // inicializo os ponteiros como null
    this->id = 0;
    this->ant = nullptr;
    this->prox = nullptr;
}

NoStack::NoStack(const NoStack& orig) {
}

NoStack::~NoStack() {
}
/*
 retorno o nó anterior
 */
NoStack* NoStack::getant() {
    return this->ant;
}
/*
 retorn o id
 */
int NoStack::getid() {
    return id;
}
/*
 passo o novo id
 */
void NoStack::setid(int id) {
    this->id = id;
}
/*
 retorno o caractere
 */
char NoStack::getinfo() {
    return info;
}
/*
 retorn o nó proximo
 */
NoStack* NoStack::getprox() {
    return this->prox;
}
/*
 passo o novo nó anterior
 */
void NoStack::setant(NoStack* n) {
    this->ant = n;
}
/*
 passo o novo caractere
 */
void NoStack::setinfo(char info) {
    this->info = info;
}
/*
 passo o novo nó proximo
 */
void NoStack::setprox(NoStack* n) {
    this->prox = n;
}
/*
 retorn a chave
 */
int NoStack::getchave() {
    return this->chave;
}
/*
 passa a chave
 */
void NoStack::setchave(int chave) {
    this->chave = chave;
}









