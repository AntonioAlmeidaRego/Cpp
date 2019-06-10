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

#include "NoString.h"
#include <string.h>
using namespace std;
/*
 Classe Queue.h 
 */
class Queue {
     /*
     Métodos e atributos publicos
     */
public:
    Queue(); // construtor
    void enqueue(wchar_t info); // método de adiciona na fila
    wchar_t dequeue(); // método que remove na fila
    void print(); // método de teste
    bool isempty(); // método que verifica se a fila está vazia
    int size(); // retorna o tamanho da fila;
    NoString * get(int id); // retorna o nó pelo id
    wchar_t getchar(wchar_t info); // retorna o caractere pelo 'info'
    int lenghtfreq(wchar_t info); // retorna o tamanho da frequencia pelo caractere
    wchar_t firt(); // retorna o primeiro da fila
    string caracteres(); // retorna todos os caracteres
    Queue(const Queue& orig);
    virtual ~Queue();
     /*
     Métodos e atributos privados
     */
private:
    int lenght; // tamanho da fila
    NoString *cabeca; // nó cabeca;
    NoString *calda; // nó calda
    int freq; // frequencia
    bool notrepete(wchar_t info); // método privado que verifica se o caractere já foi adicionado 

};
#endif /* QUEUE_H */

