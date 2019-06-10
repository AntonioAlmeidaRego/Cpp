/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   Celula.h
 * Author: robso
 *
 * Created on 25 de Julho de 2018, 10:01
 */

#ifndef CELULA_H
#define CELULA_H

class Celula {
public:
    Celula(){
        prox = NULL;
    }
    Celula(int l, int c){
        this->l = l;
        this->c = c;
        prox = NULL;
    }
    int pegaL();
    void setL(int l);
    int pegaC();
    void setC(int c);
    Celula *pegaProx();
    void setProx(Celula *prox);
private:
    int l; //de linha
    int c; // de coluna
    Celula *prox;

};

int Celula::pegaL(){
    return l; // get de linha, retorna a própria linha
}

void Celula::setL(int l){
    this->l = l; // instancia l
}

int Celula::pegaC(){
    return c; //get de coluna, retorna a própria coluna
}

void Celula::setC(int c){
    this->c = c; //instancia c
}

Celula *Celula::pegaProx(){
    return prox; //retorna o proximo
}

void Celula::setProx(Celula *prox){
    this->prox = prox; //instancio prox
}
#endif /* CELULA_H */

