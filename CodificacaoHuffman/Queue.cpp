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
#include "NoString.h"
#include "Queue.h"
using namespace std;
/*
 Construtor
 */
Queue::Queue() {
    // instancio o nó cabeca e o calda
    this->cabeca = new NoString();
    this->calda = new NoString();
    
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
wchar_t Queue::firt() {
    return cabeca->getprox()->getInfo();
}
/*
 Retorno o tamanho da linha
 */
int Queue::size() {
    return lenght;
}
/*
 retorno todos os caracteres da fila
 */
string Queue::caracteres() {
    string caractere = "";
    NoString *aux = this->cabeca->getprox();
    while(aux != this->calda){
        caractere += aux->getInfo();
        aux = aux->getprox();
    }
    return caractere;
}

/*
 verifico se o caractere já foi adicionado
 */
bool Queue::notrepete(wchar_t info) {
    NoString *aux = this->cabeca->getprox();
    while(aux != calda){
        if(aux->getInfo() != info){
            aux = aux->getprox();
        }else{
            return false;
        }
    }
    return true;
}
/*
 retorno o tamanho da frequencia do caractere
 */
int Queue::lenghtfreq(wchar_t info) {
    int freq = 0;
    if(isempty()){
        return 1;
    }else{
        NoString *aux = this->cabeca->getprox();
        while(aux != calda){
            if(aux->getInfo() == info){
                freq++;
            }
            aux = aux->getprox();
        }
    }
    return freq;
}

/*
 retorno o caractere pelo paramêtro
 */
wchar_t Queue::getchar(wchar_t info) {
    NoString *aux = cabeca->getprox();
    while(aux != calda){
        if(aux->getInfo() == info){
            return aux->getInfo();
        }
        aux = aux->getprox();
    }
    return aux->getInfo();
}

/*
 retorno o nó pelo id
 */
NoString * Queue::get(int id) {
    NoString *aux = cabeca->getprox();
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
void Queue::enqueue(wchar_t info) {
    lenght++;
    NoString *n = new NoString();
    n->setInfo(info);
    n->setid(lenght);
    if(isempty()){
        this->cabeca->setprox(n);
        n->setant(this->cabeca);
        n->setprox(this->calda);
        calda->setant(n);
    }else{
        NoString * aux = this->calda->getant();
        aux->setprox(n);
        n->setprox(calda);
        n->setant(aux);
        this->calda->setant(n);
    }
}
/*
 remove o nó e retorna o caractere removido
 */
wchar_t Queue::dequeue() {
    lenght--;
    NoString *aux = this->cabeca->getprox();
    this->cabeca->setprox(aux->getprox());
    return aux->getInfo();
}
/*
 Método de teste
 */
void Queue::print() {
    NoString *aux = this->cabeca->getprox();
    while(aux != this->calda){
        cout << aux->getInfo();
        aux = aux->getprox();
    }
    cout << endl;
}






