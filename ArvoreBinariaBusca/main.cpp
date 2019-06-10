/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: antonio
 *
 * Created on 21 de Março de 2019, 06:50
 */

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ArvoreBinaria.h"
#include "Percurso.h"
#include "Lista.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    srand(time(0));
    
    ArvoreBinaria *h = new ArvoreBinaria(8, 'A');
    ArvoreBinaria *arvore = new ArvoreBinaria(7, 'A');
    
    
    arvore->inserirABB(arvore->getraiz(), 12, 'B');
    arvore->inserirABB(arvore->getraiz(), 14, 'D');
    arvore->inserirABB(arvore->getraiz(), 5, 'E');
    arvore->inserirABB(arvore->getraiz(), 24, 'F');
    
//    arvore->removeABB(arvore->getraiz(), 5);
//    arvore->removeABB(arvore->getraiz(), 24);
//    arvore->removeABB(arvore->getraiz(), 12);
    
    Percurso *p = new Percurso();
    
    Lista *l = new Lista(14);
    cout << "\nLista de chaves: \n";
    cout << endl;
    l->print();
    cout << endl;
 
    ArvoreBinaria *a = h->convertListTreeBBComplete(l->getlista(), l->size());
    
    h->inserirABB(h->getraiz(), 4, 'B');
    h->inserirABB(h->getraiz(), 12, 'C');
    h->inserirABB(h->getraiz(), 2, 'Q');
    h->inserirABB(h->getraiz(), 6, 'S');
    h->inserirABB(h->getraiz(), 10, 'G');
    h->inserirABB(h->getraiz(), 14, 'L');
    h->inserirABB(h->getraiz(), 1, 'N');
    h->inserirABB(h->getraiz(), 3, 'n');
    h->inserirABB(h->getraiz(), 5, 'W');
    h->inserirABB(h->getraiz(), 7, 'Q');
    h->inserirABB(h->getraiz(), 9, 'E');
    h->inserirABB(h->getraiz(), 11, 'c');
    h->inserirABB(h->getraiz(), 13, 'T');
    h->inserirABB(h->getraiz(), 15, 'Z');
  
//    h->removeABB(h->getraiz(), 15);
//    h->removeABB(h->getraiz(), 12);
//    h->removeABB(h->getraiz(), 2);
//    h->removeABB(h->getraiz(), 10);
//    h->removeABB(h->getraiz(), 11);
//    h->removeABB(h->getraiz(), 1);
//    h->removeABB(h->getraiz(), 3);
//    h->removeABB(h->getraiz(), 6);
//    h->removeABB(h->getraiz(), 5);
//    h->removeABB(h->getraiz(), 4);
//    h->removeABB(h->getraiz(), 9);
//    h->removeABB(h->getraiz(), 13);
//    h->removeABB(h->getraiz(), 7);
//    h->removeABB(h->getraiz(), 14);
    
    cout << "\nOrdem Simetrica\n";
    p->ordemSimetrica(h->getraiz());
    cout << "\nOrdem Pre-ordem\n";
    p->preOrdem(h->getraiz());
    cout << "\nOrdem Pos-ordem\n";
    p->posOrdem(h->getraiz());
    cout << "\n\nTotal de elementos contidos: ";
    cout << h->size() << endl;
    
    cout << "\nArvore aux: \n";
    p->preOrdem(a->getraiz());
    cout << endl;
    
    cout << "\nArvore Teste\n";
    cout << "\nOrdem Simetrica\n";
    p->ordemSimetrica(arvore->getraiz());
    cout << "\nOrdem Pre-ordem\n";
    p->preOrdem(arvore->getraiz());
    cout << "\nOrdem Pos-ordem\n";
    p->posOrdem(arvore->getraiz());
    cout << "\n\nTotal de elementos contidos: ";
    cout << arvore->size() << endl;
    
    ArvoreBinaria *aux = arvore->treeBB(arvore);
    cout << "\nArvore completa: \n";
    p->preOrdem(aux->getraiz());
    cout << endl;
    
    return 0;
}

