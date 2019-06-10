/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   NoAscii.h
 * Author: antonio
 *
 * Created on 7 de Abril de 2019, 17:46
 */

#ifndef NOASCII_H
#define NOASCII_H
#include <string>
using namespace std;
/*
 Classe NoAscii.h
 */
class NoAscii {
    /*
     Métodos e atributos publicos
     */
public:
    NoAscii(); // construtor
    NoAscii(const NoAscii& orig);
    NoAscii * getprox(); // retorna o proximo nó
    string getcodigo(); // retorna o código
    char getinfo(); // retorna o caractere
    void setprox(NoAscii * ascii); // passa o novo nó para ser apontado
    void setinfo(wchar_t info); // passa o novo caractere
    void setcodigo(string cod); // passa o novo código
    void setant(NoAscii *ascii); // passa o novo nó anteriro para ser apontado
    NoAscii * getant(); // retorna o nó anterior
    int getid(); // retorna o id
    void setid(int id); // passa o novo id
    virtual ~NoAscii();
    /*
     Métodos e atributos privados
     */
private:
    NoAscii * prox; // nó proximo
    NoAscii * ant; // nó anterior
    wchar_t info; // caractere
    int id; // id
    string codigo; // código
};

#endif /* NOASCII_H */

