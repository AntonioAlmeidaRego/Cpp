/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Percurso.h
 * Author: antonio
 *
 * Created on 21 de Março de 2019, 20:20
 */

#ifndef PERCURSO_H
#define PERCURSO_H
#include "No.h"
class Percurso {
public:
    Percurso();
    Percurso(const Percurso& orig);
    void visitor(No *n);
    void preOrdem(No *n);
    void posOrdem(No *r);
    int altura(No *n);
    void ordemSimetrica(No *r);
    virtual ~Percurso();
private:

};

#endif /* PERCURSO_H */

