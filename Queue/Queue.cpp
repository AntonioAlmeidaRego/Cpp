/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   Queue.cpp
 * Author: antonio
 *
 * Created on 6 de Abril de 2019, 13:24
 */
#include <iostream>
#include "NoQueue.h"
#include "Queue.h"
using namespace std;
/*
 Construtor
 */
Queue::Queue() {
    // instancia dos nós cabeca e calda
    this->cabeca = new NoQueue();
    this->calda = new NoQueue();
    
    this->cabeca->setprox(calda); // nó cabeca aponta o proximo para a calda 
    this->cabeca->setant(calda); // nó cabeca aponta o anterior para a calda
    this->calda->setprox(cabeca); // nó calda aponta o proximo para a cabeca
    this->calda->setant(cabeca); // nó calda aponta o anterior para a cabeca
    // Ou seja é uma fila duplamente encadeada circular
}

Queue::Queue(const Queue& orig) {
}

Queue::~Queue() {
}
/*
 Verifico se a fila está vazia
 */
bool Queue::isempty() {
    if(cabeca->getprox() == calda && cabeca->getant() == calda){
        return true;
    }
    return false;
}
/*
 Retorno o primeiro da fila
 */
NoQueue* Queue::firt() {
    return cabeca->getprox();
}
/*
 Retorno o tamanho da linha
 */
int Queue::size() {
    return lenght;
}

/*
 retorno o nó pelo id
 */
NoQueue * Queue::get(int id) {
    NoQueue *aux = cabeca->getprox();
    while(aux != calda){
        if(aux->getid() == id){
            return aux;
        }
        aux = aux->getprox();
    }
    return aux;
}
/*
 Adiciono na fila o caractere
 */
void Queue::enqueue(int chave, wchar_t info) {
    lenght++;
    NoQueue *n = new NoQueue();
    n->setchave(chave);
    n->setinfo(info);
    n->setid(lenght);
    if(isempty()){
        this->cabeca->setprox(n);
        n->setant(this->cabeca);
        n->setprox(this->calda);
        calda->setant(n);
    }else{
        NoQueue * aux = this->calda->getant();
        aux->setprox(n);
        n->setprox(calda);
        n->setant(aux);
        this->calda->setant(n);
    }
}
/*
 remove o nó e retorna o caractere removido
 */
NoQueue* Queue::dequeue() {
    lenght--;
    NoQueue *aux = this->cabeca->getprox();
    this->cabeca->setprox(aux->getprox());
    return aux;
}
/*
 Método de teste
 */
void Queue::print() {
    NoQueue *aux = this->cabeca->getprox();
    if(isempty()){
        cout << "Queue empty";
    }
    while(aux != this->calda){
        cout << "ch  (" << aux->getchave() << ") info --> " << aux->getinfo()  << " ";
        aux = aux->getprox();
    }
    cout << endl;
}






