/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   NoString.h
 * Author: antonio
 *
 * Created on 6 de Abril de 2019, 13:25
 */

#ifndef NOSTRING_H
#define NOSTRING_H
/*
 Classe NoString.h
 */
class NoString {
     /*
        Métodos e atributos publicos
     */
public:
    NoString(); // construtor
    NoString(const NoString& orig);
    void setprox(NoString *n); // passa o novo nó para ser apontado
    void setant(NoString *n); // passa o novo nó anterior para ser apontado
    void setInfo(wchar_t info); // passa o novo caractere
    NoString *getprox(); // retorna o nó proximo
    NoString *getant(); // retorna o nó anterior
    void setfreq(int f); // passa a nova frequencia
    int getfreq(); // retorna a frequencia
    wchar_t getInfo(); // retorna o caractere
    void setid(int id); // passa o novo id
    int getid(); // retorna o id
    virtual ~NoString();
    /*
     Métodos e atributos privados
     */
private:
    NoString * prox; // nó proximo
    NoString * ant; // nó anterior
    int freq; // frequencia
    int id; // id
    wchar_t info; // caractere
};

#endif /* NOSTRING_H */

