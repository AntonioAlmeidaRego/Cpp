/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   NoQueue.h
 * Author: antonio
 *
 * Created on 6 de Abril de 2019, 13:25
 */

#ifndef NOSTACK_H
#define NOSTACK_H
/*
 Classe NoStack.h
 */
class NoStack {
     /*
        Métodos e atributos publicos
     */
public:
    NoStack(); // construtor
    NoStack(const NoStack& orig);
    void setprox(NoStack *n); // passa o novo nó para ser apontado
    void setant(NoStack *n); // passa o novo nó anterior para ser apontado
    void setinfo(char info); // passa o novo caractere
    void setchave(int chave); // passa o nova chave
    NoStack *getprox(); // retorna o nó proximo
    NoStack *getant(); // retorna o nó anterior
    char getinfo(); // retorna o caractere
    void setid(int id); // passa o novo id
    int getid(); // retorna o id
    int getchave(); // retorna a chave
    virtual ~NoStack();
    /*
     Métodos e atributos privados
     */
private:
    NoStack * prox; // nó proximo
    NoStack * ant; // nó anterior
    int id; // id
    char info; // caractere
    int chave; // chave
};

#endif /* NOSTACK_H */

