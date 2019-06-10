/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NoStack.h
 * Author: antonio
 *
 * Created on 21 de Maio de 2019, 15:18
 */

#ifndef NOSTACK_H
#define NOSTACK_H

/* Classe NoStack.h */
/* Classe responsavel por criar o nó que terá uma estrutura de dois nós (anterior e proximo) e uma chave */
class NoStack {
public:
    NoStack(); // construtor
    NoStack(const NoStack& orig);
    NoStack * getprox(); // retorna o proximo nó
    void setprox(NoStack * stack); // passa o novo nó para ser apontado
    void setchave(int chave); // passa o nova chave
    void setant(NoStack *stack); // passa o novo nó anteriro para ser apontado
    NoStack * getant(); // retorna o nó anterior
    int getchave(); // retorna a chave do nó
    virtual ~NoStack();
private:
    NoStack * prox; // nó proximo
    NoStack * ant; // nó anterior
    int chave; // chave
};

#endif /* NOSTACK_H */

