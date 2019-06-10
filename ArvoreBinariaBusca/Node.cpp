/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Node.cpp
 * Author: antonio
 * 
 * Created on 24 de Março de 2019, 20:38
 */
#include <iostream>
#include "Node.h"

Node::Node() {
    this->prox = NULL;
}

Node::Node(const Node& orig) {
}

Node::~Node() {
}

int Node::getchave() {
    return this->chave;
}

Node* Node::getprox() {
    return this->prox;
}

void Node::setChave(int chave) {
    this->chave = chave;
}

void Node::setProx(Node* p) {
    this->prox = p;
}




