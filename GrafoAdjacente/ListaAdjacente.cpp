/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ListaAdjacencia.cpp
 * Author: antonioalmeida
 * 
 * Created on 13 de Junho de 2019, 12:13
 */
#include <iostream>
#include "ListaAdjacente.h"
using namespace std;
/* Classe ListaAdjacente.cpp */
// Construtor padrão
ListaAdjacente::ListaAdjacente() {
    this->nocabeca = new NodeAdjacente; // instancio o nó cabeca
    this->calda = new NodeAdjacente; // instancio o nó calda
    // A ListaAdjacente foi implementada com caracteristicas de uma lista duplamente encadeada circular
    this->nocabeca->setant(calda); // nó cabeca anterior aponta para a calda
    this->nocabeca->setprox(calda); // nó cabeca proximo aponta para a calda
    this->calda->setant(nocabeca); // nó calda anterior aponta para a cabeca
    this->calda->setprox(nocabeca); // nó calda proximo aponta para a cabeca
}
/*Método que verifica se a lista está vazia*/
bool ListaAdjacente::isempty() {
    if(this->nocabeca->getprox() == calda){// Se nó cabeca proximo for igual a calda, a lista está vazia, senão false
        return true;
    }
    return false;
}
/* Método que verifica se existe os vertices na lista*/
bool ListaAdjacente::isexist(int v, int u) {
    bool existV = false;// variavel auxiliar
    bool existU = false; // variavel auxiliar
    NodeAdjacente * aux = nocabeca->getprox(); // retorna o proximo do nó cabeca
    while(aux != calda){ // enquanto a variavel aux for diferente de calda, ele faz a busca
        if(aux->getvertice() == v){ // Se o vertice da variavel aux for igual ao do parametro
            existV = true; // Seta true na variavel auxiliar
        }
        if(aux->getvertice() == u){// Se o vertice da variavel aux for igual ao do parametro
            existU = true;// Seta true na variavel auxiliar
        }
        aux = aux->getprox(); // faz o percurso na lista até enquanto o aux for diferente do calda
    }
    return (existU == existV) ? true : false;  // Se as duas variaveis são true retorna true, senao retorna false
}

/*Método de adicionar na lista*/
void ListaAdjacente::add(int vertice, int custo, bool dir) {
    NodeAdjacente *novo = new NodeAdjacente(custo, vertice, dir);// instancia um novo nó
    if(isempty()){// verifica se a lista está vazia
        // Se a lista está vazia segue o fluxo abaixo
        nocabeca->setprox(novo); // nó cabeca próximo aponta para o novo
        novo->setant(nocabeca); // nó novo anterior aponta para o cabeca
        novo->setprox(calda); // nó novo proximo aponta para a calda
        calda->setant(novo); // nó calda anterior aponta para o novo
    } else{
        // Senão segue o fluxo abaixo
        NodeAdjacente *aux = calda->getant(); // retorna o ultimo nó
        aux->setprox(novo);// nó aux proximo aponta para o novo
        novo->setant(aux); // nó novo anterior aponta para aux
        novo->setprox(calda); // nó novo proximo aponta para a calda
        calda->setant(novo); // nó calda anterior aponta para o novo
    }
}
/* Método de adicionar na lista */
void ListaAdjacente::add(int vertice, int custo, bool dir, int id) {
    NodeAdjacente *novo = new NodeAdjacente(custo, vertice, dir);// instancia um novo nó
    novo->setid(id);// seta o identificador
    if(isempty()){// verifica se a lista está vazia
        // Se a lista está vazia segue o fluxo abaixo
        nocabeca->setprox(novo);// nó cabeca próximo aponta para o novo
        novo->setant(nocabeca);// nó novo anterior aponta para o cabeca
        novo->setprox(calda);// nó novo proximo aponta para a calda
        calda->setant(novo);// nó calda anterior aponta para o novo
    }
    else{
        // Senão segue o fluxo abaixo
        NodeAdjacente *aux = calda->getant(); // retorna o ultimo nó
        aux->setprox(novo);// nó aux proximo aponta para o novo
        novo->setant(aux);// nó novo anterior aponta para aux
        novo->setprox(calda); // nó novo proximo aponta para a calda
        calda->setant(novo);// nó calda anterior aponta para o novo
    }
}
/*Método que remove da lista um nó não direcional*/
void ListaAdjacente::remove(NodeAdjacente* v, int vertice) {
    if(v->getdir()){// Se o nó for direcional 
        removeDir(v);// passa para outro método que remove o nó direcionado
    }else{// Senão segue o fluxo abaixo
        // Duas variaveis auxiliares: Nó anterior e proximo
        NodeAdjacente *anterior = nullptr;
        NodeAdjacente *proximo = nullptr;
        NodeAdjacente *aux = searchVertice(vertice);// faz a busca pelo vertice
        anterior = aux->getant();// seta a variavel anterior com o nó anterior da busca
        proximo = aux->getprox(); // seta a variavel proximo com o nó proximo da busca
        anterior->setprox(proximo);// a variavel anterior proximo aponta para a variavel proximo
        proximo->setant(anterior);// a variavel proximo anterior aponta para a variavel anterior
    }
}
/*Método que remove da lista um nó direcionado*/
void ListaAdjacente::removeDir(NodeAdjacente* v) {
    // Duas variaveis auxiliares: Nó anterior e proximo
    NodeAdjacente *anterior = nullptr;
    NodeAdjacente *proximo = nullptr;
    NodeAdjacente *aux = searchVertice(v->getvertice());// faz a busca pela label
    anterior = aux->getant();// seta a variavel anterior com o nó anterior da busca
    proximo = aux->getprox();// seta a variavel proximo com o nó proximo da busca
    anterior->setprox(proximo);// a variavel anterior proximo aponta para a variavel proximo
    proximo->setant(anterior);// a variavel proximo anterior aponta para a variavel anterior
}

/*Método que retorna o nó pelo identificador*/
NodeAdjacente* ListaAdjacente::getone(int id) {
    NodeAdjacente *aux = nocabeca->getprox();// retorna o nó proximo da cabeca
    NodeAdjacente*a = nullptr;// variavel auxiliar
    while(aux != calda){// Enquanto a variavel auxiliar for diferente de calda, ele segue o fluxo abaixo
        a = aux;// recebe o nó auxiliar
        if(id == aux->getid()){// se o identificador por parametro for igual ao identificador da variavel auxiliar retorna o nó com esse identificador
            return a;// retorna o nó
        }// Senão continua o fluxo
        aux = aux->getprox();// enquanto o nó é diferente do calda, ele fica fazendo o percurso na lista
    }
    return nullptr;// Caso não exista o nó retorna null
}

/* Método que exibe a lista de nós */
void ListaAdjacente::print() {
    NodeAdjacente *aux = nocabeca->getprox();// retorna o nó proximo da cabeca
    while(aux != calda){// Enquanto a variavel auxiliar for diferente de calda, ele segue o fluxo abaixo
        if(aux == calda->getant()){// Se a variavel auxiliar por igual ao calda anterior, ou seja, quando for o ultimo nó da lista
            if(aux->getcusto() > 0){// Se o custo da variavel auxiliar for maior que 0
                // printa o vertice e seu custo do nó
                cout << "[" << aux->getvertice() << " " << aux->getcusto() << "] ";
            }else{// Senão 
                // printa somente o vertice
                cout << "[" << aux->getvertice() << "] ";
            }
        }else{// Senão 
            if(aux->getcusto() > 0){// Se o custo da variavel auxiliar for maior que 0
                // printa o vertice e seu custo do nó
                cout << "[" << aux->getvertice() << " " << aux->getcusto() << "] --> ";
            }else{// Senão 
                // printa somente o vertice
                cout << "[" << aux->getvertice() << "] --> ";
            }
        }
        aux = aux->getprox();// enquanto o nó é diferente do calda, ele fica fazendo o percurso na lista
    }
}
/* Método que retorna o primeiro da lista*/
NodeAdjacente* ListaAdjacente::firt() {
    return nocabeca->getprox();
}

/*Método que retorna o nó pelo vertice*/
NodeAdjacente* ListaAdjacente::searchVertice(int vertice) {
    NodeAdjacente *aux = nocabeca->getprox();// retorna o nó proximo da cabeca
    NodeAdjacente *a = nullptr;// variavel auxiliar
    while(aux != calda){// Enquanto a variavel auxiliar for diferente de calda, ele segue o fluxo abaixo
        a = aux;// recebe o nó auxiliar
        if(vertice == aux->getvertice()){// se o vertice por parametro for igual ao vertice da variavel auxiliar retorna o nó com esse vertice
            return a;// retorna o nó
        }// Senão continua o fluxo
        aux = aux->getprox();// enquanto o nó é diferente do calda, ele fica fazendo o percurso na lista
    }
    return nullptr;// Caso não exista o nó retorna null
}

/*Método que retorna o nó pela label*/
NodeAdjacente* ListaAdjacente::searchLabel(string label) {
    NodeAdjacente *aux = nocabeca->getprox();// retorna o nó proximo da cabeca
    NodeAdjacente*a = nullptr;// variavel auxiliar
    while(aux != calda){// Enquanto a variavel auxiliar for diferente de calda, ele segue o fluxo abaixo
        a = aux;// recebe o nó auxiliar
        if(label == aux->getlabel()){// se a label por parametro for igual a label da variavel auxiliar retorna o nó com essa label
            return a;// retorna o nó
        }// Senão continua o fluxo
        aux = aux->getprox();// enquanto o nó é diferente do calda, ele fica fazendo o percurso na lista
    }
    return nullptr;// Caso não exista o nó retorna null
}


ListaAdjacente::ListaAdjacente(const ListaAdjacente& orig) {
}

ListaAdjacente::~ListaAdjacente() {
}

