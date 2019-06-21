/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   Stack.cpp
 * Author: antonio
 *
 * Created on 7 de Abril de 2019, 17:45
 */
#include <iostream>
#include "Stack.h"
using namespace std;

Stack::Stack() {
    // instância dos nós cabeca e calda
    this->nocabeca = new NoStack();
    this->nocalda = new NoStack();
    length = 0;
    this->nocabeca->setprox(nocalda);// nó cabeca aponta o proximo para a calda
    this->nocabeca->setant(nocalda);// nó cabeca aponta o anterior para a calda
    this->nocalda->setprox(nocabeca);// nó calda aponta o proximo para a cabeca
    this->nocalda->setant(nocabeca);// nó calda aponta o anterior para a cabeca
     // Ou seja é uma pilha duplamente encadeada circular
}

Stack::Stack(const Stack& orig) {
}

Stack::~Stack() {
}
/*
 Verifica se a pilha está vazia
 */
bool Stack::empty() {
    if(nocabeca->getprox() == nocalda){
        return true;
    }
    return false;
}
/*
 Retorno o tamanho da pilha
 */
int Stack::size() {
    return this->length;
}
/*
 retorna o ultimo da pilha
 */
NoStack * Stack::last() {
    return nocabeca->getprox();
}
/*
 retorna o topo da pilha
 */
NoStack * Stack::top() {
    return nocalda->getant();
}
/*
 retorno o nó pelo id
 */
NoStack * Stack::get(int id) {
    NoStack *aux = nocabeca->getprox();
    while(aux != nocalda){
        if(aux->getid() == id){
            return aux;
        }
        aux = aux->getprox();
    }
    return aux;
}

/*
 Inserir no topo da pilha
 */
void Stack::push(int chave, char info) {
    length++;
    NoStack *n = new NoStack();
    n->setinfo(info);
    n->setchave(chave);
    n->setid(length);
    if(empty()){
        nocabeca->setprox(n);
        n->setant(nocabeca);
        n->setprox(nocalda);
        nocalda->setant(n);
    }else{
        NoStack *aux = nocalda->getant();
        nocalda->setant(n);
        aux->setprox(n);
        n->setprox(nocalda);
        n->setant(aux);
    }
}
/*
 Remove do topo da pilha
 */
NoStack* Stack::pop() {
    length--;
    NoStack * aux = nocalda->getant();
    NoStack * ant = aux->getant();
    nocalda->setant(ant);
    ant->setprox(nocalda);
    return aux;
}
/*
 Print da pilha
 */
void Stack::print() {
    NoStack *aux = nocabeca->getprox();
    if(empty()){
        cout << "Stack empty";
    }
    while(aux != nocalda){
        cout << "ch (" <<aux->getchave() << ") info --> " << aux->getinfo() << " ";
        aux = aux->getprox();
    }
}




