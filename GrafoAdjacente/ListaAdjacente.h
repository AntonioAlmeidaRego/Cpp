/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ListaAdjacencia.h
 * Author: antonioalmeida
 *
 * Created on 13 de Junho de 2019, 12:13
 */

#ifndef LISTAADJACENCIA_H
#define LISTAADJACENCIA_H

#include "NodeAdjacente.h"

/*Classe ListaAdjacente.h*/
class ListaAdjacente {
public:
    // Construtor Padrão
    ListaAdjacente();
    // Método de adicionar na lista
    void add(int vertice, int custo, bool dir);
    // Método de adicionar na lista
    void add(int vertice, int custo, bool dir, int id);
    // Método de remover nó não direcional na lista
    void remove(NodeAdjacente *v, int vertice);
    // Método de remover nó direcional na lista
    void removeDir(NodeAdjacente *v);
    // Método para verificar se a lista está vazia
    bool isempty();
    // Método para verificar se existe os vertices
    bool isexist(int v, int u);
    // Método que faz a busca pela label na lista
    NodeAdjacente * searchLabel(string label);
    // Método que faz a busca pela vertice na lista
    NodeAdjacente * searchVertice(int vertice);
    // Método que faz a busca pelo identificador da lista
    NodeAdjacente * getone(int id);
    ListaAdjacente(const ListaAdjacente& orig);
    // Método que exibe a lista
    void print();
    virtual ~ListaAdjacente();
    // Método que retorna o primeiro da lista
    NodeAdjacente * firt();
private:
    // Atributos privados
    NodeAdjacente *nocabeca; // Nó cabeca da lista
    NodeAdjacente *calda; // Nó calda da lista
};

#endif /* LISTAADJACENCIA_H */

