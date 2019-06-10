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
#include "NoStack.h"
#include "Percurso.h"
using namespace std;
/*Classe Stack.cpp*/
/*Construtor*/
Stack::Stack() {
    this->nocabeca = new NoStack(); // instancio o nocabeca com new
    this->nocalda = new NoStack(); // instancio o nocalda com new
    size = 0; // inicializo o size com 0
    this->nocabeca->setprox(nocalda); // aponto o nocabeca proximo para a calda
    this->nocabeca->setant(nocalda); // aponto o nocabeca anterior para a calda
    this->nocalda->setprox(nocabeca); // aponto a calda proximo para a cabeca
    this->nocalda->setant(nocabeca); // aponto a calda anterior para a cabeca
}

Stack::Stack(const Stack& orig) {
}

Stack::~Stack() {
}
/*Verifico se a pilha está vazia*/
bool Stack::empty() {
    if(nocabeca->getprox() == nocalda){//Se nocabeca proximo aponta para a calda
        return true; // Se for verdade retorna true
    }
    return false; // senao retorna false
}
/* Faço a busca pela chave*/
bool Stack::existChave(int chave) {
    NoStack *aux = nocabeca->getprox();// retorno a nó próximo da nocabeca
    while(aux != nocalda){ // Enquanto essa aux for diferente de calda faço a busca
        if(aux->getchave() == chave){ // Se a aux tiver a chave retorna verdadeiro
            return true;
        }
        aux = aux->getprox(); // senao continuo a busca
    }
    return false; // Quando não tiver elementos e não encontrou a chave retorna false
}

/*Método que remove da pilha*/

int Stack::pop() {
    size--;// decremento o size
    NoStack * aux = nocalda->getant(); // retorna o ultimo nó
    NoStack * ant = aux->getant(); // retorna o ante penultimo
    nocalda->setant(ant);// o calda aponta para esse ante penultimo
    ant->setprox(nocalda); // E o ante penultimo aponta para a calda
    return aux->getchave(); // retorna a chave removida
}
/*Método que faz a inserção na pilha*/
void Stack::push(int chave) {//recebe por paramêtro a chave
    NoStack *n = new NoStack(); // crio um nó
    n->setchave(chave); // seta a chave nesse novo nó
    if(empty()){ // verifico se a pilha está vazia
        nocabeca->setprox(n); //nocabeca aponta o proximo para o novo nó
        n->setant(nocabeca); // novo nó aponta o anterior para o nó cabeca
        n->setprox(nocalda); // novo nó aponta o proximo para o nó calda
        nocalda->setant(n); // E o nó calda aponta anterior para o nó novo
    }else{
        NoStack *aux = nocalda->getant(); // retorna o nó anterior da calda
        nocalda->setant(n); // calda anterior aponta para o novo nó
        aux->setprox(n); // nó auxiliar aponta o proximo para o nó novo
        n->setprox(nocalda); // nó novo aponta para o proximo para o nó calda
        n->setant(aux);// nó novo aponta o anterior para o nó auxiliar
    }
}
/* Método que printa a pilha*/
void Stack::print() {
    NoStack *aux = nocabeca->getprox(); // retorna o nó proximo da cabeca
    while(aux != nocalda){ // enquanto nó auxiliar for diferente de calda, ele printa a chave e aponta para o próximo
        cout << aux->getchave() << " "; // printa a chave da pilha
        aux = aux->getprox(); // aponta para o próximo
    }
}




