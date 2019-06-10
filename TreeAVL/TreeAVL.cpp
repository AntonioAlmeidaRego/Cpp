/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   TreeAVL.cpp
 * Author: antonio
 *
 * Created on 20 de Abril de 2019, 19:53
 */
#include <iostream>
#include <stdlib.h>
#include "TreeAVL.h"
#include "Stack.h"
#include "Percurso.h"

using namespace std;
/*Classe TreeAVL.cpp*/
/*construtor*/
TreeAVL::TreeAVL() {
}

TreeAVL::TreeAVL(const TreeAVL& orig) {
}

TreeAVL::~TreeAVL() {
}
/*variavel global*/
bool achou = false;
/*Método que faz a rotação para a esquerda*/
void TreeAVL::balanceL(NodeAVL*& pA, bool& h) {//recebe o nó por referencia, e uma variavel de controle
    switch(pA->getbal()){//faz a escolha qual caso vai escolher
        case +1: pA->setbal(0); break; // Caso for 1, ele seta 0 para o balanceamento
        case 0: pA->setbal(-1); h=false; break; // Caso for 0, ele seta -1 para o balanceamento e seta false para a variavel de controle 
        case -1: // Caso for -1
        int balB, balC; // criou duas variáveis para ter os balanceamentos dos nós auxiliares
        NodeAVL *pB; // nó auxiliar
        NodeAVL *pC; // nó auxiliar
        pB->setright(pA->getright()); // seta o nó pB direito do nó pA direito
        balB = pB->getbal(); // retorna o balanceamento do nó pB
        if(balB <= 0){ // se o balanceamento for menor ou igual a 0
            pA->setright(pB->getleft()); // seta o nó pA direito do nó pB esquerdo
            pB->setleft(pA); // seta o nó pB do nó pA
            if(balB == 0){ // verifica se o balanceamento da variavel auxiliar balB é igual a 0
                pA->setbal(-1); // seta o balanceamento do nó pA com -1
                pB->setbal(1); // seta o balanceamento do nó pB com 1
                h = false; // seta a variavel de controle com false
            }else{ // Senão
                // seta os nós pA e pB com balanceamentos com 0
                pA->setbal(0);
                pB->setbal(0);
            }
            // após verificar o balanceamento da variável balB
            // pA recebe pB
            pA = pB;
        }else{
            pC = pB->getleft();// seta o nó pC do nó pB esquerdo
            balC = pC->getbal(); // seta o balC do nó pC balaceamento
            pB->setleft(pC->getright()); // seta o nó pB esquerdo do nó pC direito
            pC->setright(pB); // seta o nó pC direito do nó pB
            pA->setright(pC->getleft());// seta o nó pA direito do nó pC esquerdo
            pC->setleft(pA);// seta o nó pC esquerdo do nó pA
            // faz a verificação se o balanceamento da variavel balC
            if(balC == -1) pA->setbal(1); else pA->setbal(0);
            if(balC == 1) pB->setbal(-1); else pB->setbal(0);
            // após isso o pA recebe pC
            pA = pC;
            // E o balancemento do pC seta com 0
            pC->setbal(0);
        }
            
    }
}
/*Método que faz a rotação para a direita*/
void TreeAVL::balanceR(NodeAVL*& pA, bool& h) {//recebe o nó por referencia, e uma variavel de controle
    switch(pA->getbal()){//faz a escolha qual caso vai escolher
         case -1:// Caso for -1, ele seta 0 para o balanceamento
            pA->setbal(0);
            break;
        case 0:// Caso for 0, ele seta 1 para o balanceamento e seta false para a variavel de controle 
            pA->setbal(+1);
            h = false;
            break;
        case +1:// Caso for 1
            int balB, balC; // criou duas variáveis para ter os balanceamentos dos nós auxiliares
            NodeAVL *pB; // nó auxiliar
            NodeAVL *pC; // nó auxiliar
            pB = pA->getleft(); // seta o nó pB do nó pA esquerdo
            balB = pB->getbal(); // retorna o balanceamento do nó pB
            if(balB >= 0){ // se o balanceamento for maior ou igual a 0
                pA->setleft(pB->getright()); // seta o nó pA esquerdo do nó pB direito
                pB->setright(pA); // seta o nó pB direito do nó pA
                if(balB == 0){ // verifica se o balanceamento da variavel auxiliar balB é igual a 0
                    pA->setbal(+1);// seta o balanceamento do nó pA com +1
                    pB->setbal(-1);// seta o balanceamento do nó pB com -1
                    h = false;// seta a variavel de controle com false
                }else{ // senao
                    // seta os nós pA e pB com balanceamentos com 0
                    pA->setbal(0);
                    pB->setbal(0);
                }
                // após verificar o balanceamento da variável balB
                // pA recebe pB
                pA = pB;
            }else{
                pC = pB->getright();// seta o nó pC do nó pB direito
                balC = pC->getbal();// seta o balC do nó pC balaceamento
                pB->setright(pC->getleft());// seta o nó pB direito do nó pC esquerdo
                pC->setleft(pB); // seta o nó pC esquerdo do nó pB
                pA->setleft(pC->getright());// seta o nó pA esquerdo do nó pC direito
                pC->setright(pA);// seta o nó pC direito do nó pA
                // faz a verificação se o balanceamento da variavel balC
                if(balC == 1) pA->setbal(-1); else pA->setbal(0);
                if(balC == -1) pB->setbal(+1); else pB->setbal(0);
                // após isso o pA recebe pC
                pA = pC;
                // E o balancemento do pC seta com 0
                pC->setbal(0);
            }
    }
}
/*Método que faz a busca pelo proximo nó da chave a ser removida*/
void TreeAVL::DelMin(NodeAVL*& q, NodeAVL*& r, bool& h) {// recebe dois nós por referencias e uma variavel de controle
    if(r->getleft() != nullptr){// Se a variavel r tem filho a esquerdo, ele faz recursivamente a busca 
        DelMin(q, r->left, h); // faz a recursivamente a busca
        if(h)// apos isso ele verifica se a variavel de controle é true
            balanceL(r, h); // Se for ele faz a rotação l
    }else{// Senão
        q->setchave(r->getchave()); // ele seta a chave 
        q = r;// recebe o nó r
        r = r->getright(); // E o nó r aponta para a direita
        h = true;// E a variavel de controle recebe true
    }
}
/* Método que faz a remoção da AVL auxiliar*/
void TreeAVL::deleteAVL(int chave, NodeAVL *&n) {
    bool h = false;//inicializo a variavel de controle
    this->setraiz(n);//seta a raiz
    Delete(chave, n, h, getraiz()); // método que faz a remoção
}
/*Método que verifica se o nó é folha*/
bool TreeAVL::isfolha(NodeAVL* n) {
    if((n->getleft() == nullptr) && (n->getright() == nullptr)){
        return true;
    }
    return false;
}
/* Método que faz a busca por uma chave*/
void TreeAVL::busca(NodeAVL* raiz, int chave) {
    
    if(raiz->getleft() != nullptr){ // se a sub-arvore tem filho a esquerda
       busca(raiz->getleft(), chave); // faz a recursão para a esquerda
    }
    if(raiz->getright() != nullptr){ // se a sub-arvore tem filho direito 
       busca(raiz->getright(), chave); // faz a recursão para a direita
    }
    if(chave == raiz->getchave()){ // se a chave for igual a sub-arvore
        achou = true; // variavel global recebe true
        cout << "\n Chave Encontrada  " << chave << "\n"; // printa a chave encontrada
    }else { // senão
        if(achou == false){ // se a variavel global for false
            system("clear"); // limpa a tela
            cout << "\n Chave não encontrada! \n"; // E exibe a mensagem 
        }
    }
}
/*Método que faz a remoção*/
void TreeAVL::Delete(int x, NodeAVL*& p, bool& h, NodeAVL *raiz) {// Método que recebe por parametro a chave e a raiz. E por referencia o nó e a variavel de controle
    if(p == nullptr){// Se o nó é igual a nullptr
        if(isfolha(raiz)){// Se a raiz é folha então arvore está vazia
            cout << "\nArvore AVL vazia!\n";
        }else{ // Senão nó nao existe para remover
            cout << "\nNó não existe!\n";
        }
    }else{// Senão
        if(x < p->getchave()){ // Se a chave é menor que a sub-arvore
            Delete(x, p->left, h, raiz); // faz recursivamente para a esquerda
            if (h){ // se a variavel de controle for igual a true
                 this->balanceL(p, h); // faz a rotação l
            }
        }else if(x > p->getchave()){// Senão se a chave for maior que a sub-arvore
            Delete(x, p->right, h, raiz);// faz recursivamente para a direita
            if (h){// se a variavel de controle for igual a true
                this->balanceR(p, h);// faz a rotação r
            }
        }else{ // senao
            if(isfolha(p)){ // se o nó for folha
                NodeAVL * pai = buscafather(raiz, x); // retorna o seu pai
                if(p->getchave() < pai->getchave()){ // se o nó filho for menor que o pai
                    pai->setleft(nullptr); // o pai seta a sua esquerda nullptr
                }else{// senão
                    pai->setright(nullptr); // o pai seta a sua direita nullptr
                }
            }else { // senão
                NodeAVL *q = p;// nó auxiliar q recebe o p
                if(q->getright() == nullptr){ // se nó q nao tem filho a direita
                    p = q->getleft();// p recebe o q a sua esquerda
                    h = true;// variavel de controle recebe true
                }else{ // senao
                    if(q->getleft() == nullptr){ // se nó q não tem filho a esquerda
                        p = q->getright();// p recebe o q a sua direita
                        h = true;// variavel de controle recebe true
                    }else{
                        DelMin(q, q->right, h);// faz a busca para encontrar a chave proxima
                        if(h) // se for true
                            balanceR(p, h); // faz a rotação r
                    }
                    delete q; // faz a remoção do nó q da memoria
                }
            } 
        } 
    }
}
/* Método que seta a raiz*/
void TreeAVL::setraiz(NodeAVL* raiz) {
    this->raiz = raiz;
}
/*Método que retorna a raiz*/
NodeAVL * TreeAVL::getraiz() {
    return this->raiz;
}
/*variaveis globais*/
Stack *pilha = new Stack;
NodeAVL *auxPai = nullptr;
/*Método auxiliar para a inserção na AVL*/
void TreeAVL::inserirAVL(int chave, NodeAVL*& n, bool& h) {
    setraiz(n);// seta a raiz
    auxPai = getraiz(); // variavel global recebe a raiz
    searchinsert(chave, n, h, getraiz());// método que faz a inserção da AVL
}
/* Método que retorna o nó pai da chave*/
NodeAVL* TreeAVL::buscafather(NodeAVL* raiz, int chave) {
    if(chave == raiz->getchave()){ // verifica se a chave é a raiz
        return auxPai; // returna o pai, se a chave for a raiz, ele retorna a propria raiz
    }else if(chave < getraiz()->getchave()){ // Senao se a chave é menor que a raiz
        if(raiz == nullptr){ // verifica se a chave é nula se for retorna o pai dessa chave passada por parametro
            return auxPai;
        }else if(chave > raiz->getchave()){ // Senao a chave for maior que a raiz da chave
            auxPai = raiz; // o pai recebe a raiz
            raiz = raiz->getright();// raiz 'anda para direita' recursivamente
            return buscafather(raiz, chave);
        }else if(chave < raiz->getchave()){ // Senao se a chave é menor que a chave da raiz ele 'anda para esquerda'
            auxPai = raiz;
            raiz = raiz->getleft();
            return buscafather(raiz, chave);
        }
    }else if(chave > getraiz()->getchave()){// Senao a chave for maior que a raiz da chave
        if(raiz == nullptr){// verifica se a chave é nula se for retorna o pai dessa chave passada por parametro
            return auxPai;
        }else if(chave > raiz->getchave()){// Senao a chave for maior que a raiz da chave
            auxPai = raiz;
            raiz = raiz->getright();
            return buscafather(raiz, chave);
        }else if(chave < raiz->getchave()){// Senao se a chave é menor que a chave da raiz ele 'anda para esquerda'
            auxPai = raiz;
            raiz = raiz->getleft();
            return buscafather(raiz, chave);
        }
    }
    return nullptr;
}
/*Método que faz a inserção da AVL*/
void TreeAVL::searchinsert(int chave, NodeAVL *&pA, bool& h, NodeAVL *raiz) {
    if((pilha->existChave(chave))){// verifica se nó já foi inserido
        cout << "\n chave já adicionada! \n";
    }else{ // senao
        if (pA == nullptr) { // verifica se o nó é nullptr
            pA = new NodeAVL(chave, 0); // instancia com o new 
            h = true;// a variavel de controle recebe true
            pilha->push(chave); // inserir a chave na pilha
        } else { // senão
            if (chave < pA->getchave()) // se a chave for menor que a sub-arvore
            {
                searchinsert(chave, pA->left, h, raiz); // faz a recursão para a esquerda
                if (h) {// se a variavel de controle for igual a true
                    switch (pA->getbal()) {// faz a escolha
                        case -1: // caso for -1
                            pA->setbal(0); // seta o balanceamento com 0
                            h = false; // a variavel de controle recebe false
                            break;
                        case 0:// caso for 0
                            pA->setbal(+1); // seta o balanceamento com 1
                            break;
                        case +1:// caso for 1
                            // criou dois nós auxiliares
                            NodeAVL *pB;
                            NodeAVL *pC;
                            pB = pA->getleft();// seta o nó pB do nó pA esquerda
                            if (pB->getbal() == +1) {// verifica se o pB balanceamento é igual a 1
                                pA->setleft(pB->getright());// seta o nó pA esquerda do nó pB direito
                                pB->setright(pA); // seta o nó pB direito do nó pA
                                pA->setbal(0); // seta o nó pA balanceamento 0
                                pA = pB;// seta o nó pA do nó pB
                            } else { // senão
                                pC = pB->getright(); // seta o nó pC do nó pB direito
                                // faz a verificação se o nó pC tem filho a direita
                                if(pC->getright() != nullptr) pA->setleft(nullptr); else pA->setleft(pC->getright());

                                pB->setright(pC->getleft());// seta o nó pB direita do nó pC esquerdo
                                pC->setleft(pB); // seta o nó pC esquerdo do nó pB
                                pC->setright(pA);// seta o nó pC direito do nó pA
                                // faz a verificação dos balanceamentos
                                if (pC->getbal() == +1) pA->setbal(-1);
                                else pA->setbal(0);
                                if (pC->getbal() == -1) pB->setbal(+1);
                                else pB->setbal(0);
                                // pA recebe pC
                                pA = pC;
                            }
                            // o nó pA seta o balanceamento 0
                            pA->setbal(0);
                            // variavel de controle recebe false
                            h = false;
                    }
                }
            } 
            else { // senão
                if (chave > pA->getchave()) { // se a chave for maior que a sub-arvore
                    searchinsert(chave, pA->right, h, raiz); // faz a recursão a direita
                    if (h) { // se a variavel for igual a true
                        switch (pA->getbal()) { // faz a escolha 
                            case +1:// Caso for 1
                                pA->setbal(0); // seta o balanceamento com 0
                                h = false; // variavel de controle recebe false
                                break;
                            case 0: // caso for 0
                                pA->setbal(-1); // seta o balanceamento com -1
                                break;
                            case -1: // caso for -1
                                // criou dois nós auxiliares
                                NodeAVL *pB;
                                NodeAVL *pC;
                                pB = pA->getright();// seta o nó pB do nó pA direita
                                if (pB->getbal() == -1) { // verifica se o balanceamento é igual a -1
                                    pA->setright(pB->getleft()); // seta o nó pA direita do nó pB esquerda
                                    pB->setleft(pA);// seta o nó pB esquerda do nó pA
                                    pA->setbal(0);// seta o balanceamento do nó pA com 0
                                    pA = pB;// seta o nó pA do nó pB
                                } else {
                                    pC = pB->getleft();// seta o nó pC do nó pB esquerda
                                    // verifica se o nó pC tem filho a esquerda
                                    if (pC->getleft() != nullptr) pA->setright(pC->getleft()); else pA->setright(nullptr);
                                    // verifica se o nó pC tem filho a direita
                                    if (pC->getright() != nullptr) pB->setleft(pC->getright()); else pB->setleft(nullptr);
                                    pC->setleft(pA); // seta o nó pC esquerdo do nó pA
                                    pC->setright(pB); // seta o nó pC direito do nó pB
                                    // verifica o balanceamento do nó pC
                                    if (pC->getbal() == -1) pA->setbal(+1);
                                    else pA->setbal(0);
                                    if (pC->getbal() == +1) pB->setbal(-1);
                                    else pB->setbal(0);
                                    // nó pA recebe pC
                                    pA = pC;
                                }
                               // seta o balanceamento de pA com 0
                                pA->setbal(0);
                                // variavel de controle recebe false
                                h = false;
                        }
                    }
                }
            }
        }
    }        
    
}


