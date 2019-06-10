/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Ascii.cpp
 * Author: antonio
 * 
 * Created on 7 de Abril de 2019, 16:22
 */

#include "Ascii.h"

/*
 Arquivo Ascii.cpp
 */

Ascii::Ascii() {
}

Ascii::Ascii(const Ascii& orig) {
}

Ascii::~Ascii() {
}
/*
 Método que retorna o código
 */
string Ascii::getcodigo() {
    return this->codigo;
}
/*
 Método que retorna o caractere
 */
char Ascii::getinfo() {
    return this->info;
}
/*
 Método que recebe o novo código
 */
void Ascii::setcodigo(string codigo) {
    this->codigo = codigo;
}
/*
 Método que recebe o novo caractere
 */
void Ascii::setinfo(char info) {
    this->info = info;
}





