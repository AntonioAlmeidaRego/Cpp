/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Percurso.h
 * Author: antonio
 *
 * Created on 20 de Abril de 2019, 20:18
 */

#ifndef PERCURSO_H
#define PERCURSO_H

#include "NodeAVL.h"
/*Classe Percurso.h*/
/*Classe responsavel que permite o percurso de arvores binarias */
class Percurso {
public:
    Percurso();//construtor
    Percurso(const Percurso& orig);
    void visitor(NodeAVL *n); // método que visita o nó
    void preordem(NodeAVL *n); // método que faz o percurso na arvore
    virtual ~Percurso();
    
private:

};

#endif /* PERCURSO_H */

