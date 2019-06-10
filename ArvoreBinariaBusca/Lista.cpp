/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Lista.cpp
 * Author: antonio
 * 
 * Created on 23 de Março de 2019, 13:38
 */
#include <iostream>
#include "Lista.h"
using namespace std;

Lista::Lista(int* v, int tamanho) {
    this->vetor = v;
    this->tamanho = tamanho;
}

Lista::Lista() {

}

Lista::Lista(int tamanho) {
    this->tamanho = tamanho;
    int i = 0;
    int aux;
    this->vetor = new int[this->tamanho];
    while(i >= 0){
        aux = 1 + rand()%30;
        if(i == tamanho){
            break;
        }else if(vetor[0] == 0){
            vetor[i] = aux;
        }else if(existenumero(vetor, aux, tamanho)){
            continue;
        }else{
            vetor[i] = aux;
        }
        i++;
    }
    vetor = ordenar(vetor, tamanho);
}

Lista::Lista(const Lista& orig) {
}

Lista::~Lista() {
}

int* Lista::criarvetor(int tamanho) {
    int *v = new int[tamanho];
    return v;
}


bool Lista::isempty() {
    if(tamanho == 0){
        return true;
    }
    return false;
}

void Lista::setlista(int* v) {
    this->vetor = v;
}

void Lista::setsize(int t) {
    this->tamanho -= t; 
}


int Lista::getposicaoleft(int elemento) {
    for(int i = 1;i<=tamanho;i++){
        if(vetor[i] == elemento){
            return i;
        }
    }
    return 0;
}

int Lista::getposicaoright(int elemento) {
    for(int i = tamanho;i>=0;i--){
        if(vetor[i] == elemento){
            return i;
        }
    }
    return 0;
}


int* Lista::ordenar(int* v, int tamanho) {
    int aux;
    for(int i = 0;i<tamanho;i++){
        for(int j = i+1;j<tamanho;j++){
            if(v[i] > v[j]){
                aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }
        }
    }
    return v;
}


bool Lista::existenumero(int *v, int aux, int tamanho) {
    int i = 0;
    while(i >= 0){
        if(v[i] == aux){
            return true;
        }else if(i == tamanho){
            return false;
        }
        i++;
    }
    return false;
}


int* Lista::getlista() {
    return this->vetor;
}

int Lista::size() {
    return this->tamanho;
}

void Lista::print() {
    for(int i=0;i<this->tamanho;i++){
        if(vetor[i] != 0){
           cout << "[" << this->vetor[i] << "]"; 
        }
    }
}



