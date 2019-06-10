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

#include "NoAscii.h"

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
    NoAscii * pop(); // remove e retorna o nó do topo da pilha
    void push(string cod, wchar_t info); // adiciona na pilha o código e o caractere
    void push(string cod); // outro método que adiciona o código na pilha
    void print(); // método de teste
    string codes(wchar_t info); // método que retorna os códigos pelo caractere
    string code(); // retorna o código
    int size; // tamanho da pilha
    virtual ~Stack(); 
private:
    NoAscii * nocalda; // nó calda
    NoAscii * nocabeca; // nó cabeca
    bool notrepet(wchar_t info); // método privado que verifica se o caracte foi adicionado
};

#endif /* STACK_H */

