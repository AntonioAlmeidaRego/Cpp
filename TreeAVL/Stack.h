/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   Stack.h
 * Author: antonio
 *
 * Created on 7 de Abril de 2019, 17:45
 */

#ifndef STACK_H
#define STACK_H

#include "NoStack.h"

/*
 Classe Stack.h
 */
class Stack {
    /*
     Métodos e atributos publicos
     */
public:
    Stack(); // construtor
    Stack(const Stack& orig);
    bool empty(); // verifica se está vazia a pilha
    int pop(); // remove e retorna o nó do topo da pilha
    void push(int chave); // outro método que adiciona a nova chave na pilha
    void print(); // método de teste
    bool existChave(int chave); // verifico se existe a chave por paramêtro
    int size; // tamanho da pilha
    virtual ~Stack(); 
private:
    NoStack * nocalda; // nó calda
    NoStack * nocabeca; // nó cabeca
};

#endif /* STACK_H */

