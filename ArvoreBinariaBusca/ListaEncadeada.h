/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ListaEncadeada.h
 * Author: antonio
 *
 * Created on 24 de Março de 2019, 21:06
 */

#ifndef LISTAENCADEADA_H
#define LISTAENCADEADA_H

#include "Node.h"


class ListaEncadeada {
public:
    ListaEncadeada();
    ListaEncadeada(const ListaEncadeada& orig);
    virtual ~ListaEncadeada();
    Node *remove();
    void inserir(int chave);
    bool isempty();
    void print();
    int size();
    Node *noCabeca();
private:
    int tam;
    Node *nocabeca;
};

#endif /* LISTAENCADEADA_H */

