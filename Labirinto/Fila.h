/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   Fila.h
 * Author: robso
 *
 * Created on 3 de Agosto de 2018, 18:16
 */


#ifndef FILA_H
#define FILA_H
#include "Celula.h"

class Fila {
public:
    Fila(){
            noCabeca = new Celula();
            noCabeca->setProx(noCabeca);
        }
        Fila(int l, int c){
            noCabeca = new Celula(l,c);
            noCabeca->setProx(noCabeca);
        }
    bool inserirFinal(int l, int c);
    Celula* removerInicio();
    bool isEmpty();
    Celula* getNoCabeca();
    void printCircular();
    Celula* primeiroCell();

private:
    Celula *noCabeca;

};

Celula* Fila::getNoCabeca(){
        return noCabeca;
    }

    bool Fila::isEmpty(){
        if(noCabeca == noCabeca->pegaProx()){
            return true;
        }
        return false;
    }

    bool Fila::inserirFinal(int l, int c){
        Celula *novo = new Celula(l, c);
        if(isEmpty()){
            Celula *aux = noCabeca->pegaProx();
            noCabeca->setProx(novo);
            novo->setProx(aux);
            return true;
        }else{
            Celula *aux2  = noCabeca->pegaProx();
	        Celula *inicio = noCabeca;
	        Celula *ultimo = noCabeca;
	        while(aux2 != noCabeca){
	            ultimo = aux2;
	            aux2 = aux2->pegaProx();
            }
            ultimo->setProx(novo);
            novo->setProx(inicio);
	        return true;
        }
    }

    Celula* Fila::primeiroCell(){
        Celula *aux = noCabeca->pegaProx();
        return aux;
    }

    Celula* Fila::removerInicio(){
        Celula *aux = this->primeiroCell();
        if(aux == noCabeca){
            return NULL;
        }else{
            Celula *seg = aux->pegaProx();
            noCabeca->setProx(seg);
            return aux;
        }
    }


    void Fila::printCircular(){
        Celula *aux = noCabeca->pegaProx();
        while (aux != noCabeca)
        {
            cout<< "[" << aux->pegaL() << "," << aux->pegaC() << "] ";
            aux = aux->pegaProx();
        }

    }



#endif /* FILA_H */

