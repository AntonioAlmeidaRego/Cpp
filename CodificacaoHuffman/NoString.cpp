/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   NoString.cpp
 * Author: antonio
 *
 * Created on 6 de Abril de 2019, 13:25
 */

#include "NoString.h"

/*
 Construtor
 */

NoString::NoString() {
    // inicializo os ponteiros como null
    this->id = 0;
    this->ant = nullptr;
    this->prox = nullptr;
}

NoString::NoString(const NoString& orig) {
}

NoString::~NoString() {
}
/*
 retorno o nó anterior
 */
NoString* NoString::getant() {
    return this->ant;
}
/*
 retorn o id
 */
int NoString::getid() {
    return id;
}
/*
 passo o novo id
 */
void NoString::setid(int id) {
    this->id = id;
}
/*
 retorno o caractere
 */
wchar_t NoString::getInfo() {
    return info;
}
/*
 retorn o nó proximo
 */
NoString* NoString::getprox() {
    return this->prox;
}
/*
 passo o novo nó anterior
 */
void NoString::setant(NoString* n) {
    this->ant = n;
}
/*
 passo o novo caractere
 */
void NoString::setInfo(wchar_t info) {
    this->info = info;
}
/*
 passo o novo nó proximo
 */
void NoString::setprox(NoString* n) {
    this->prox = n;
}
/*
 retorno a frequencia
 */
int NoString::getfreq() {
    return this->freq;
}
/*
 passo a nova frequencia
 */
void NoString::setfreq(int f) {
    this->freq = f;
}








