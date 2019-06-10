/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   ListaEncadeada.cpp
 * Author: antonio
 *
 * Created on 4 de Abril de 2019, 11:10
 */
#include <iostream>
#include "ListaEncadeada.h"
#include "No.h"
#include "Node.h"
using namespace std;

/*
 Arquivo ListaEncadeada.cpp
 
 */
/*
 construtor
 */
ListaEncadeada::ListaEncadeada() {
    this->nocabeca = new No(); // instancio o nó cabeca

    this->nocabeca->setprox(nocabeca); // nó cabeca aponta o próximo para o nó cabeca, ou seja, é uma lista encadeada circular
}

ListaEncadeada::ListaEncadeada(const ListaEncadeada& orig) {
}

ListaEncadeada::~ListaEncadeada() {
}
/*
 Método que retorna o tamanho da lista
 */
int ListaEncadeada::lenght() {
    return size;
}

/*
 Método que verifica se a lista está vazia
 */
bool ListaEncadeada::empty() {
    if(this->nocabeca->getprox() == nocabeca){
        return true;
    }
    return false;
}

/*
 Método privado que retorna o nó anterior
 */
No* ListaEncadeada::busca_anterior(Node *n) {
    ant = nocabeca;
    nocabeca->setInfo(n);
    pont = nocabeca->getprox();

    while(pont->getInfo()->getfreq() < n->getfreq()){
        ant = pont;
        pont = pont->getprox();
    }
    if(pont != nocabeca && pont->getInfo()->getfreq() == n->getfreq()){
        return ant;
    }
    return nullptr;
}

/*
 Método privado que retorna o nó proximo
 */

No* ListaEncadeada::busca_proximo(Node *n) {
    ant = nocabeca;
    nocabeca->setInfo(n);
    pont = nocabeca->getprox();

    while(n->getfreq() > pont->getInfo()->getfreq() && pont != nocabeca){
        ant = pont;
        pont = pont->getprox();
    }
    return pont;
}

/*
 Método que retorna o primeiro da lista, a raiz da arvore
 */

Node * ListaEncadeada::front() {
    return this->nocabeca->getprox()->getInfo();
}

/*
 Método privado que verifica se o caractere já foi adicionado 
 */

bool ListaEncadeada::existeNo(wchar_t info) {
    No *aux = nocabeca->getprox();
    while(aux != nocabeca){
        if(aux->getInfo()->getinfo() == info){
            return true;
        }
        aux = aux->getprox();
    }
    return false;
}

/*
 Adiciona o nó da arvore 
 */

void ListaEncadeada::add(Node* r) {
    size++;
    No *novo = new No();
    novo->setInfo(r);
    r->setid(size);
    ant  = busca_anterior(r);
    pont = busca_proximo(r);
    novo->setprox(pont);
    ant->setprox(novo);
}

/*
 Método que adiciona o caractere e a frequencia
 */

void ListaEncadeada::add(wchar_t info, int freq) {
    if(!existeNo(info)){
        size++;
        Node* n = new Node();
        n->setinfo(info);
        n->setfreq(freq);
        n->setid(size);

        No *novo = new No();
        novo->setInfo(n);

        ant  = busca_anterior(n);
        pont = busca_proximo(n);
        novo->setprox(pont);
        ant->setprox(novo);
    }
}

/*
 Método que retorna o nó pelo caractere
 */

Node* ListaEncadeada::get(wchar_t info) {
    No * aux = nocabeca->getprox();
    while(aux != nocabeca){
        if(aux->getInfo()->getinfo() == info){
            cout << info;
            return aux->getInfo();
        }
        aux = aux->getprox();
    }
    return aux->getInfo();
}

/*
 Método que remove da lista e retorna o nó 
 */

Node* ListaEncadeada::remove() {
    size--;
    No *aux = nocabeca->getprox();
    nocabeca->setprox(aux->getprox());
    return aux->getInfo();
}

/*
 Método de teste
 */

void ListaEncadeada::print() {
    No *aux = nocabeca->getprox();
    while(aux != nocabeca){
        cout << aux->getInfo()->getfreq() << " ";
        aux = aux->getprox();
    }
}
