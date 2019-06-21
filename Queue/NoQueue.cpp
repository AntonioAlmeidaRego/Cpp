/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "NoQueue.h"


/*
 * File:   NoQueue.cpp
 * Author: antonio
 *
 * Created on 6 de Abril de 2019, 13:25
 */

/*
 Construtor
 */

NoQueue::NoQueue() {
    // inicializo os ponteiros como null
    this->id = 0;
    this->ant = nullptr;
    this->prox = nullptr;
}

NoQueue::NoQueue(const NoQueue& orig) {
}

NoQueue::~NoQueue() {
}
/*
 retorno o nó anterior
 */
NoQueue* NoQueue::getant() {
    return this->ant;
}
/*
 retorn o id
 */
int NoQueue::getid() {
    return id;
}
/*
 passo o novo id
 */
void NoQueue::setid(int id) {
    this->id = id;
}
/*
 retorno o caractere
 */
char NoQueue::getinfo() {
    return info;
}
/*
 retorn o nó proximo
 */
NoQueue* NoQueue::getprox() {
    return this->prox;
}
/*
 passo o novo nó anterior
 */
void NoQueue::setant(NoQueue* n) {
    this->ant = n;
}
/*
 passo o novo caractere
 */
void NoQueue::setinfo(char info) {
    this->info = info;
}
/*
 passo o novo nó proximo
 */
void NoQueue::setprox(NoQueue* n) {
    this->prox = n;
}
/*
 retorn a chave
 */
int NoQueue::getchave() {
    return this->chave;
}
/*
 passa a chave
 */
void NoQueue::setchave(int chave) {
    this->chave = chave;
}









