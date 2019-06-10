/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   Lista.h
 * Author: antonio
 *
 * Created on 4 de Abril de 2019, 10:07
 */

#ifndef LISTA_H
#define LISTA_H
#include "Node.h"
class Lista {
public:
    Lista();
    Lista(const Lista& orig);
    virtual ~Lista();
    int chave;
    wchar_t info;
    Node *raiz;
private:

};

#endif /* LISTA_H */

