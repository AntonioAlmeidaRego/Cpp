/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   NoAscii.cpp
 * Author: antonio
 *
 * Created on 7 de Abril de 2019, 17:46
 */

#include "NoAscii.h"
/*
 Arquivo NoAscii.cpp
 */

/*
 construtor
 */

NoAscii::NoAscii() {
    // inicializo os ponteiros como null
    this->ant = nullptr;
    this->prox = nullptr;
    this->id = 0;
}

NoAscii::NoAscii(const NoAscii& orig) {
}

NoAscii::~NoAscii() {
}
/*
 Retorna o código
 */
string NoAscii::getcodigo() {
    return this->codigo;
}

/*
 Retorna o caractere
 */

char NoAscii::getinfo() {
    return this->info;
}
/*
 Retorna o proximo nó
 */

NoAscii* NoAscii::getprox() {
    return this->prox;
}
/*
 Passa o novo código
 */
void NoAscii::setcodigo(string cod) {
    this->codigo = cod;
}
/*
 Passa o novo caractere
 */
void NoAscii::setinfo(wchar_t info) {
    this->info = info;
}

/*
 Passa o novo nó para o proximo
 */
void NoAscii::setprox(NoAscii* ascii) {
    this->prox = ascii;
}
/*
 Retorno o nó anterior
 */
NoAscii* NoAscii::getant() {
    return this->ant;
}

/*
 Passo o novo nó anterior
 */
void NoAscii::setant(NoAscii* ascii) {
    this->ant = ascii;
}

/*
 Retorno o id
 */

int NoAscii::getid() {
    return this->id;
}
/*
 passo o novo id
 */
void NoAscii::setid(int id) {
    this->id = id;
}









