/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   No.cpp
 * Author: antonio
 * 
 * Created on 21 de Março de 2019, 06:50
 */
#include <iostream>
#include "No.h"

No::No() {
    this->left = NULL;
    this->right = NULL;
}

No::No(const No& orig) {
}

No::~No() {
}

int No::getchave() {
    if (this != NULL)
    return this->chave;
}

char No::getinfo() {
    if (this != NULL)
    return this->info;
}

No* No::getleft() {
    return this->left;
}

No* No::getright() {
    return this->right;
}

void No::setchave(int c) {
    this->chave = c;
}

void No::setinfo(char inf) {
    this->info = inf;
}

void No::setleft(No* no) {
    this->left = no;
}

void No::setright(No* no) {
    this->right = no;
}






