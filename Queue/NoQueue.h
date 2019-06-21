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

#ifndef NOQUEUE_H
#define NOQUEUE_H
/*
 Classe NoQueue.h
 */
class NoQueue {
     /*
        Métodos e atributos publicos
     */
public:
    NoQueue(); // construtor
    NoQueue(const NoQueue& orig);
    void setprox(NoQueue *n); // passa o novo nó para ser apontado
    void setant(NoQueue *n); // passa o novo nó anterior para ser apontado
    void setinfo(char info); // passa o novo caractere
    void setchave(int chave); // passa o nova chave
    NoQueue *getprox(); // retorna o nó proximo
    NoQueue *getant(); // retorna o nó anterior
    char getinfo(); // retorna o caractere
    void setid(int id); // passa o novo id
    int getid(); // retorna o id
    int getchave(); // retorna a chave
    virtual ~NoQueue();
    /*
     Métodos e atributos privados
     */
private:
    NoQueue * prox; // nó proximo
    NoQueue * ant; // nó anterior
    int id; // id
    char info; // caractere
    int chave; // chave
};

#endif /* NOQUEUE_H */

