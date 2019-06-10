/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   No.h
 * Author: antonio
 *
 * Created on 4 de Abril de 2019, 11:13
 */

#ifndef NO_H
#define NO_H
#include "Node.h"
/*
 Classe No.h
 */
class No {
    /*
     métodos e atributos publicos
     */
public:
    No(); // construtor
    No(const No& orig);
    virtual ~No();
    No * getprox(); // método que retorna o proximo nó
    void setprox(No *prox); // método que passa o novo nó que será apontado
    Node *getInfo(); // método que retorna o nó que será a nó raiz 
    void setInfo(Node *info); // método que passa o novo nó que será apontado
    /*
     métodos e atributos privados
     */
private:
    No *prox; // nó prox
    Node *info; // nó raiz;
};

#endif /* NO_H */

