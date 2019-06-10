/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ArvoreBinaria.h
 * Author: antonio
 *
 * Created on 21 de Março de 2019, 06:55
 */

#ifndef HEAPB_H
#define HEAPB_H
#include "Lista.h"
#include "No.h"
#include "ListaEncadeada.h"
class ArvoreBinaria {
public:
    ArvoreBinaria(int chave, char info);
    No * getraiz();
    ArvoreBinaria(const ArvoreBinaria& orig);
    virtual ~ArvoreBinaria();
    int buscaABB(No *raiz, int chave);
    bool inserirABB(No *raiz, int chave, char info);
    void removeABB(No *raiz, int chave);
    bool isemptyright();
    int size();
    ArvoreBinaria * convertListTreeBBComplete(int *v, int tamanho);
    ArvoreBinaria * treeBB(ArvoreBinaria *a);
    bool isemptyleft();
private:
    No *raiz;
    No *buscafather(No *raiz, int chave);
    No *auxPai;
    bool teste;
    No *buscaMin(No *r, int chave);
    ArvoreBinaria * completeTreeBB(No *raiz, int tamanho, ArvoreBinaria *a);
    int sucessor(int v);
    int tamanho;
    ListaEncadeada *lista;
    ListaEncadeada *lista2;
    void Teste(int chave);
    bool existe(int chave);
};

#endif /* HEAPB_H */

