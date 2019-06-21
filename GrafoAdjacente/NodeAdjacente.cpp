/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NodeAdjacencia.cpp
 * Author: antonioalmeida
 * 
 * Created on 13 de Junho de 2019, 12:16
 */

#include "NodeAdjacente.h"
/* Classe NodeAdjacente.cpp */
/* Construtor padrão*/
NodeAdjacente::NodeAdjacente() {
    this->ant = nullptr; // inicializo o nó com null
    this->prox = nullptr; // inicializo o nó com null
    this->custo = 0; // inicializo o custo com 0
    this->dir = false; // inicializo o direcional
}
/* Construtor com os parametros*/
NodeAdjacente::NodeAdjacente(int custo, int vertice, bool dir) {
    this->ant = nullptr;// inicializo o nó com null
    this->prox = nullptr;// inicializo o nó com null
    this->custo = custo;// recebe por parametro o custo
    this->dir = dir; // recebe por parametro o direcional
    this->vertice = vertice; //recebe por parametro a vertice
    this->label = std::to_string(vertice); //recebe por parametro a label
}
/* Método Get que retorna o anterior da lista*/
NodeAdjacente* NodeAdjacente::getant() {
    return this->ant;
}
/* Método Get que retorna o custo*/
int NodeAdjacente::getcusto() {
    return this->custo;
}
/* Método Get que retorna true ou false*/
bool NodeAdjacente::getdir() {
    return this->dir;
}
/* Método Get que retorna o próximo da lista*/
NodeAdjacente* NodeAdjacente::getprox() {
    return this->prox;
}
/* Método Get que retorna o vertice*/
int NodeAdjacente::getvertice() {
    if(this != nullptr)
        return this->vertice;
}
/* Método Set que seta o nó anterior da lista*/
void NodeAdjacente::setant(NodeAdjacente* ant) {
    this->ant = ant;
}
/* Método Set que seta o custo*/
void NodeAdjacente::setcusto(int custo) {
    this->custo = custo;
}
/* Método Set que seta o direcional*/
void NodeAdjacente::setdir(bool dir) {
    this->dir = dir;
}
/* Método Set que seta o nó proximo da lista*/
void NodeAdjacente::setprox(NodeAdjacente* prox) {
    this->prox = prox;
}
/* Método Set que seta o vertice*/
void NodeAdjacente::setvertice(int vertice) {
    this->vertice = vertice;
}
/* Método Get que retorna a label*/
string NodeAdjacente::getlabel() {
    return this->label;
}
/* Método Set que seta a label */
void NodeAdjacente::setlabel(string label) {
    this->label = label;
}
/* Método Get que retorna o identificador*/
int NodeAdjacente::getid() {
    return this->id;
}
/* Método Set que seta o identificador*/
void NodeAdjacente::setid(int id) {
    this->id = id;
}

NodeAdjacente::NodeAdjacente(const NodeAdjacente& orig) {
}
NodeAdjacente::~NodeAdjacente() {
}

