/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Lista.h
 * Author: antonio
 *
 * Created on 23 de Março de 2019, 13:38
 */

#ifndef LISTA_H
#define LISTA_H

#include "Node.h"

 
class Lista {
public:
    Lista(int tamanho);
    Lista();
    Lista(int *v, int tamanho);
    Lista(const Lista& orig);
    void print();
    int * getlista();
    int getposicaoleft(int elemento);
    int getposicaoright(int elemento);
    int size();
    int * criarvetor(int t);
    bool isempty();
    void setlista(int *v);
    void setsize(int t);
    bool existenumero(int *v, int aux, int tamanho);
    int * ordenar(int *v, int tamanho);
    virtual ~Lista();
private:
    int *vetor;
    int tamanho;
    
    
    
};

#endif /* LISTA_H */

