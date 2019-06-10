/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   Arquivo.cpp
 * Author: antonio
 *
 * Created on 4 de Abril de 2019, 07:28
 */
#include "Arquivo.h"
#include "Node.h"
#include "Lista.h"
#include "Percurso.h"

/*
 Arquivo.cpp
 
 */
/*
 
 Construtor da classe Arquivo
 */
Arquivo::Arquivo(string nomearquivo){ // passando por paramêtro o caminho do arquivo
    this->nomearquivo = nomearquivo; // atribuí o arquivo
    this->lista = new Queue(); // instancia a fila
    this->listaend = new ListaEncadeada(); // instancia a lista Encadeada
    i = 0; // inicializo atributo auxiliar
    size = 0; // inicializo atributo tamanho
}

Arquivo::Arquivo(const Arquivo& orig) {
}

Arquivo::~Arquivo() {
}

/*
 Método que abrir o arquivo
 */
void Arquivo::open() {
    this->arquivo.open(this->nomearquivo);
}
/*
 Método que retorna o tamanho do arquivo
 */
int Arquivo::totalElements() {
    return lista->size();
}

/*
 Método que retorna a lista de caracteres 
 */
Queue* Arquivo::getlista() {
    return this->lista;
}

/*
 Método privado que calcula a regra de 3 para obter a porcentagem da compactação do algoritmo de huffman
 */
double Arquivo::percentualCompactacao(int lenghtarquivo, int lenghtarquivocompactado) {
    double total8bits = (lenghtarquivo * 8);
    double subtrai = total8bits - lenghtarquivocompactado;
    double teste = subtrai * 100;
    return teste/total8bits;
}


/*
 Método que ler o arquivo
 
 */
void Arquivo::read() {
    tabela_acii.open("tabela-ascii.txt"); // arquivo auxiliar que terá todos os caracteres da tabela ASCII

    Queue *fila = new Queue(); // fila auxiliar
    string lin; // lin auxiliar

    if(tabela_acii.is_open() && tabela_acii.good()){ // verifica se o arquivo ('tabela-ascii.txt') está aberto e não está corrompido
        while(!tabela_acii.eof()){ // Enquanto tiver caracteres no arquivo, ele fica lendo
            getline (tabela_acii, this->linha); // passo a linha do arquivo para a this->linha
            lin = linha;// recebe a linha do arquivo
            for(int i = 0;i<lin.length();i++){ // passa para a fila auxiliar todos os caracteres da linha
                fila->enqueue(lin[i]); // inserindo na fila cada caractere do arquivo contido na 'lin'
            }
        }
    }else { // senão o arquivo não está aberto e está corrompido
        cout << "Arquivo não foi encontrado!";
    }
    
    tabela_acii.close(); // fecha o arquivo

    if(arquivo.is_open() && arquivo.good()){ // verifica se o arquivo que terá o texto para ser compactado está aberto e não está corrompido
        while (!arquivo.eof()) // Enquanto tiver caracteres no arquivo, ele fica lendo
        {
          getline (arquivo, this->linha); // passo a linha do arquivo para a this->linha
          lin = linha; // recebe a linha do arquivo
          for(int i = 0;i<lin.length();i++){ // passa para a fila auxiliar todos os caracteres da linha
              if(lin[i] == fila->getchar(lin[i])){ // verifica se o caractere do texto têm o caractere da tabela ASCII que está na fila auxiliar.
                 lista->enqueue(lin[i]); // Se for igual inserir na fila que terá todos os caracteres do arquivo
              }
          }
        }
        //lista->print();
    }else { // senão o arquivo não está aberto e está corrompido
        cout << "Arquivo não foi encontrado!";
    }

    arquivo.close(); // fecha o arquivo
}

/*
 Método de criar a arvore
 */

Node * Arquivo::createTree() {
    int j = 0; // variavel auxiliar para ter o controle de caracteres na fila
    /*
     Quando instanciar esse método novamente, ele terá que esvaziar a lista encadeada
     */
    while(!listaend->empty()){ // Enquanto a lista encadeada não for vazia ele fica removendo os nós
        listaend->remove(); // remove da lista encadeada
    }
    i = 0; // inicializo novamente 
    while(i <= lista->size()){ // Enquanto o 'i' for menor que o tamanho da minha fila, ele vai inserir na lista encadeada
        listaend->add(lista->get(i)->getInfo(), lista->lenghtfreq(lista->get(i)->getInfo())); // nesse método de add, já inserir ordenado pela frequencia de caracteres do arquivo
        i++; // incremento o 'i'
       // j++;
    }
    i = 0; // inicializo novamente
    listaend->remove(); // removo o vazio da lista encadeada, porque todo ele colocava um espaço no inicio
    j = listaend->lenght(); // pego o tamanho da lista encadeada
    size = listaend->lenght(); // pego o tamanho da lista
    while(i < j-1){ // Enquanto o 'i' for menor que o 'j-1' para deixar o ultimo nó ser retornado como a raiz da arvore  
        Node *left = listaend->remove(); // remove o nó que será o filho a esquerda da raiz
        Node *right = listaend->remove(); // remove o nó que será o filho a direita da raiz
        int l = left->getfreq(); // retorno a frequencia do nó da esquerda
        int r = right->getfreq(); // retorno a frequencia do nó da direita
        int rz = l + r; // faço a soma das frequencias que será o valor da nova sub-arvore
        Node *raiz = new Node(); // crio a nova sub-arvore
        raiz->setfreq(rz); // passo a soma das frequencias
        raiz->setleft(left); // passo o seu novo filho a esquerda 
        raiz->setright(right); // passo o seu novo filho a direita
        listaend->add(raiz); // e adiciono novamente na lista encadeada ordenada pela frequencia
        i++; // e incremento o 'i'

    }
    return listaend->front(); // retorno a raiz da lista encadeada
}

/*
 Método privado que criar a coluna de caracteres
 */

string Arquivo::createcolunachar() {

    ListaEncadeada *l = new ListaEncadeada(); // uma lista encadeada auxiliar
    Queue * fila = new Queue(); // uma fila auxiliar
    i = 0; // incializo novamente
    while(i <= lista->size()){ // Enquanto o 'i' for menor ou igual vai inserir na lista encadeada auxiliar
        l->add(lista->get(i)->getInfo(), lista->lenghtfreq(lista->get(i)->getInfo())); // inserindo...
        i++; // incrementando...
    }

    while(!l->empty()){// Enquanto a lista não for vazia, ele remove e inseri na fila auxiliar, que terá todos os caracteres
        Node *aux = l->remove(); // nó aux que recebe o nó removido da lista encadeada
        fila->enqueue(aux->getinfo()); // E inseri na fila o caractere
    }
    return fila->caracteres(); // retorna todos os caracteres do arquivo, sem repetição
}

/*
 
 Método privado que cria a tabela de binarios, passando a posição da fila que contém os caracteres do arquivo
 
 */
string Arquivo::createtablebin(int posicao) {
     return createbin(lista->get(posicao)->getInfo());
}

/*
 Método privado que cria os binarios, que recebe o caractere 
 */
string Arquivo::createbin(wchar_t info) {
    Node *aux = createTree(); // Retorno a arvore
    Percurso per; // Instancio o objeto percurso da arvore
    per.criartabela(); // crio a tabela que terá uma pilha com os valores referente o caractere
    per.posordem(aux, aux); // passo a raiz duas vezes nos dois paramêtros para saber se estou na raiz para limpar todos os binarios da esquerda
    return per.gettabela(info); // E torno a tabela de binarios
}

/*
 Método privado que cria a coluna de binarios e o caractere
 */
string Arquivo::createcolunabin(wchar_t info) {
    Node *aux = createTree();  // Retorno a arvore
    Percurso per; // Instancio o objeto percurso da arvore
    per.criartabela(); // crio a tabela que terá uma pilha com os valores referente o caractere
    per.posordem(aux, aux); // passo a raiz duas vezes nos dois paramêtros para saber se estou na raiz para limpar todos os binarios da esquerda
    return per.gettabela(info) + " " + (char) info;  // E torno a tabela de binarios mais o caractere
}

/*
 Método que cria a tabela passando por paramêtro a posicao do caractere 
 */
string Arquivo::createtable(int posicao) {
    return createcolunabin(createcolunachar()[posicao]); // retorno o método privado que contém os binarios da posicao passada por paramêtro
}

/*
 
 Método que passa os binarios para o arquivo com o caminho por paramêtro
 
 */
void Arquivo::creatArquivoBinario(string caminho) {
    //Abri o arquivo de saida
    this->saida_arquivo.open(caminho,  std::ios::app);
    // Verifico se o mesmo está aberto e não está corrompido
    if (saida_arquivo.is_open() && saida_arquivo.good())
    {
        cout << "Arquivo de texto aberto com sucesso!" << endl;
        int k = 1; // variável auxiliar 
        string teste = "";
        while(k <= lista->size()){ // Enquanto o 'k' for menor ou igual do que o tamanho da fila de caracteres, ele escreve no arquivo 
            saida_arquivo << createtablebin(k) << " "; // retorna os binarios na posicao
            cout << endl;
            teste += createtablebin(k);
            cout << "K " << k << " " << createtablebin(k) << endl;
            k++; // incrementa...
        }
        saida_arquivo << "\nPercentual da compactação do algoritmo de huffman " << percentualCompactacao(lista->size(), teste.length()) << "%\n"; // método privado que retorna a procentagem
        cout << endl;
        cout << "Arquivo de texto escrito com sucesso!" << endl;

    }else // Senão o arquivo não abriu e está corrompido
        cout << "Erro ao abrir arquivo de texto.";
 
    saida_arquivo.close(); // fecha o arquivo de saida
}

/*
 Método que passa os binarios e os caracteres para o arquivo com o caminho por paramêtro
 */

void Arquivo::creatArquivoTabela(string caminho) {
    //Abri o arquivo de saida
    this->saida_tabela.open(caminho, std::ios::app);
    // Verifico se o mesmo está aberto e não está corrompido
    if(saida_tabela.is_open() && saida_tabela.good()){

        cout << "Arquivo de texto aberto com sucesso!" << endl;
        int k = 1; // variável auxiliar 
        while(k <= size){ // Enquanto o 'k' for menor ou igual do que o tamanho da fila de caracteres, ele escreve no arquivo 
            saida_tabela << createtable(k) << endl; // retorna os binarios e o caractere na posicao
            cout << "K " << k << " " << createtable(k) << endl;
            k++;
        }
        cout << endl;
        cout << "Arquivo de texto escrito com sucesso!" << endl;
    }else // Senão o arquivo não abriu e está corrompido
        cout << "Erro ao abrir arquivo de texto.";

    saida_tabela.close(); // fecha o arquivo de saida
}








