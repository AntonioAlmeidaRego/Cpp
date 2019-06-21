/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   Queue.h
 * Author: antonio
 *
 * Created on 6 de Abril de 2019, 13:24
 */

#ifndef QUEUE_H
#define QUEUE_H

#include <wchar.h>

#include "NoQueue.h"
/*
 Classe Queue.h 
 */
class Queue {
     /*
     Métodos e atributos publicos
     */
public:
    Queue(); // construtor
    void enqueue(int chave, wchar_t info); // método de adiciona na fila
    NoQueue * dequeue(); // método que remove na fila
    void print(); // método de teste
    bool isempty(); // método que verifica se a fila está vazia
    int size(); // retorna o tamanho da fila;
    NoQueue * get(int id); // retorna o nó pelo id
    NoQueue * firt(); // retorna o primeiro da fila
    Queue(const Queue& orig);
    virtual ~Queue();
     /*
     Métodos e atributos privados
     */
private:
    int lenght; // tamanho da fila
    NoQueue *cabeca; // nó cabeca;
    NoQueue *calda; // nó calda
};
#endif /* QUEUE_H */

