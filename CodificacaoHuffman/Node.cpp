/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   Node.cpp
 * Author: antonio
 *
 * Created on 4 de Abril de 2019, 07:31
 */

#include "Node.h"

/*
 Construtor
 */

Node::Node() {
    //inicializo os ponteiro com null
    this->left = nullptr;
    this->right = nullptr;
    this->id = 0;
}

Node::Node(const Node& orig) {
}

Node::~Node() {
}
/*
 retorno a frequencia
 */
int Node::getfreq() {
    if(this != nullptr)
        return this->freq;
}
/*
 retorno o caractere
 */
wchar_t Node::getinfo() {
    if(this != nullptr)
        return this->info;
}
/*
 retorno o nó a esquerda
 */
Node* Node::getleft() {
    return this->left;
}
/*
 retorno o nó a direita
 */
Node* Node::getright() {
    return this->right;
}
/*
 passo a nova frequencia 
 */
void Node::setfreq(int fre) {
    this->freq = fre;
}
/*
 passo o novo caractere
 */
void Node::setinfo(wchar_t info) {
    this->info = info;
}
/*
 passo o novo nó a esquerda
 */
void Node::setleft(Node* left) {
    this->left = left;
}
/*
 passo o novo nó a direita
 */
void Node::setright(Node* right) {
    this->right = right;
}
/*
 retorno o id
 */
int Node::getid() {
    return id;
}
/*
 passa o novo id
 */
void Node::setid(int id) {
    this->id = id;
}
/*
 retorna a raiz
 */
Node* Node::getraiz() {
    return this->raiz;
}
/*
 passa a raiz
 */
void Node::setraiz(Node* n) {
    this->raiz = n;
}















