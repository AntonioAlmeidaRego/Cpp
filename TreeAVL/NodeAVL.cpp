/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NodeAVL.cpp
 * Author: antonio
 * 
 * Created on 20 de Abril de 2019, 19:46
 */

#include "NodeAVL.h"
/*Classe NodeAVL.cpp*/
/*Construtor*/
NodeAVL::NodeAVL() {
    this->bal = 0; // inicializo o balaceamento com 0
    this->chave = 0; // inicializo a chave com 0
    this->left = nullptr; // inicializo o filho esquerdo com nullptr
    this->right = nullptr; // inicializo o filho direito com nullptr
}
/*Segundo construtor*/
NodeAVL::NodeAVL(int chave, int bal) {
    this->chave = chave; // inicializo a chave por paramêtro
    this->bal = bal; // inicializo o balaceamento por paramêtro
    this->left = nullptr; // inicializo o filho esquerdo com nullptr
    this->right = nullptr; // inicializo o filho direito com nullptr
}


NodeAVL::NodeAVL(const NodeAVL& orig) {
}

NodeAVL::~NodeAVL() {
}
/*Método que retorna o balaceamento*/
int NodeAVL::getbal() {
    if(this != nullptr)
        return this->bal;
}
/*Método que retorna a chave*/
int NodeAVL::getchave() {
    if(this != nullptr)
        return this->chave;
}
/*Método que retorna o filho esquerdo*/
NodeAVL* NodeAVL::getleft() {
    return this->left;
}
/*Método que retorna o filho direito*/
NodeAVL* NodeAVL::getright() {
    return this->right;
}
/*Método que seta o balaceamento*/
void NodeAVL::setbal(int bal) {
    this->bal = bal;
}
/*Método que seta a chave*/
void NodeAVL::setchave(int chave) {
    this->chave = chave;
}
/*Método que seta o filho esquerdo*/
void NodeAVL::setleft(NodeAVL * left) {
    this->left = left;
}
/*Método que seta o filho direito*/
void NodeAVL::setright(NodeAVL * right) {
    this->right = right;
}








