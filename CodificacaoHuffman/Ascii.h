/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Ascii.h
 * Author: antonio
 *
 * Created on 7 de Abril de 2019, 16:22
 */

#ifndef ASCII_H
#define ASCII_H
#include <string>
using namespace std;
/*
 Classe Ascii.h
 */
class Ascii {
    /*
    métodos e atributos publicos 
     */
public:
    Ascii(); // construtor
    Ascii(const Ascii& orig);
    virtual ~Ascii();
    string getcodigo(); // método que retorna o codigo
    char getinfo(); // método que retorna o caractere
    void setcodigo(string codigo); // método que passa o novo código
    void setinfo(char info);// método que passa o novo caractere
    /*
     métodos e atributos privados
     */
private:
    string codigo; // atributo codigo
    char info; // atributo caractere
};

#endif /* ASCII_H */

