/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NodeAdjacencia.h
 * Author: antonioalmeida
 *
 * Created on 13 de Junho de 2019, 12:16
 */

#ifndef NODEADJACENCIA_H
#define NODEADJACENCIA_H
#include <string>
using namespace std;
/* Classe NodeAdjacente.h */
class NodeAdjacente {
public:
    // Construtor 
    // Com os parametros
    NodeAdjacente(int custo, int vertice, bool dir);
    // Construtor padrão
    NodeAdjacente();
    // Seta um custo
    void setcusto(int custo);
    // Seta um vertice
    void setvertice(int vertice);
    // Seta o direcional
    void setdir(bool dir);
    // Seta o próximo da lista
    void setprox(NodeAdjacente *prox);
    // Seta o anterior da lista
    void setant(NodeAdjacente *ant);
    // Retorna o custo
    int getcusto();
    // Retorna o vertice
    int getvertice();
    // Retorna true ou false da direcional
    bool getdir();
    // Retorna a label
    string getlabel();
    // Seta a label
    void setlabel(string label);
    // Seta o identificador 
    void setid(int id);
    // Retorna o identificador
    int getid();
    // Retorna o próximo da lista
    NodeAdjacente * getprox();
    // Retorna o anterior da lista
    NodeAdjacente * getant();
    NodeAdjacente(const NodeAdjacente& orig);
    virtual ~NodeAdjacente();
private:
    // Atributos privados
    // Atributo proximo da lista
    NodeAdjacente *prox;
    // Atributo anterior da lista
    NodeAdjacente *ant;
    // Atributo custo
    int custo;
    // Atributo vertice
    int vertice;
    // Atributo direcional
    bool dir;
    // Atributo label
    string label;
    // Atributo identificador
    int id = 0;
};

#endif /* NODEADJACENCIA_H */

