/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   No.h
 * Author: antonio
 *
 * Created on 21 de Março de 2019, 06:50
 */

#ifndef NO_H
#define NO_H

class No {
public:
    No();
    No(const No& orig);
    No *getright();
    No *getleft();
    int getchave();
    char getinfo();
    void setright(No *no);
    void setleft(No *no);
    void setchave(int c);
    void setinfo(char inf);
    virtual ~No();
private:
    No *right;
    No *left;
    int chave;
    char info;
};

#endif /* NO_H */

