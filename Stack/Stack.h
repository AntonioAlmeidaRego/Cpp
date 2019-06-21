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
    NoStack * pop(); // remove e retorna o nó do topo da pilha
    void push(int chave, char info); // adiciona na pilha o código e o caractere
    void print(); // método de teste
    NoStack* get(int id);
    NoStack* top();
    NoStack* last();
    int size();
    virtual ~Stack(); 
private:
    NoStack * nocalda; // nó calda
    NoStack * nocabeca; // nó cabeca
    int length; // tamanho da pilha
};

#endif /* STACK_H */

