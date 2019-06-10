/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   Percurso.cpp
 * Author: antonio
 *
 * Created on 4 de Abril de 2019, 14:11
 */
#include <iostream>
#include "Percurso.h"
using namespace std;
/*
 construtor
 */
Percurso::Percurso() {
    // instancio as pilhas
    this->pilha = new Stack();
    this->codigo = new Stack();
}

Percurso::Percurso(const Percurso& orig) {
}

Percurso::~Percurso() {
}
/*
 crio a pilha de ascii, uma outra pilha auxiliar
 */
void Percurso::criartabela() {
    this->ascii = new Stack();
}

/*
 retorno os caracteres da pilha ascii
 */
string Percurso::gettabela(wchar_t info) {
    return ascii->codes(info);
}
/*
 crio a tabela com as duas pilhas auxiliares
 */
void Percurso::tabela(wchar_t info) {
   pilha->push(pilha->codes(info), info); // Dâ um push com os códigos da pilha e o caractere 
   NoAscii * auxAs = pilha->pop(); // removo da pilha acima o nó que contém o código o caractere
   ascii->push(auxAs->getcodigo(), auxAs->getinfo()); // E dâ um push na pilha ascii.
}
/*
 verifico se a sub-arvore é folha
 */
bool Percurso::nofolha(Node* n) {
    if(n->getleft() == nullptr && n->getright() == nullptr){
        return true;
    }
    return false;
}
/*
 Percuro pos-ordem
 */
void Percurso::posordem(Node* n, Node *raiz) {
    if(!nofolha(n)){ // se não for folha
        this->codigo->push("0"); // push '0', pois o percurso começa na sub-arvore da esquerda
        posordem(n->getleft(), raiz); // faço mais um paço recursivo para a esquerda
    }
    if(!nofolha(n)){ // E verifico se a sub-arvore direita é folha
        if(n == raiz){ // apos, caso seja falso, faço a comparação se a sub-arvore é a raiz
            while(!pilha->empty() && codigo->empty()){
                pilha->pop();
                codigo->pop();
            }
            this->codigo->push("1");
            posordem(n->getright(), raiz);
        }else{ // senão continua o percurso
            this->codigo->push("1"); // push '1'
            posordem(n->getright(), raiz); // faço mais um paço recursivo para a direita
        }
    }
    // quando ele chegar na folha, adiciona na pilha os codigos e o caractere
    pilha->push(codigo->code(), n->getinfo());
    codigo->pop(); // E remove do top o caractere
    if(nofolha(n)){ // verifico se a sub-arvore é folha
        tabela(n->getinfo()); // se for true, ele passa esse nó para a tabela
    }

}
/*
 Método de teste
 */
void Percurso::visitor(Node *n){
    cout << n->getfreq() << " ";
}


