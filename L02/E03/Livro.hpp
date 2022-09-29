#ifndef LIVRO_H
#define LIVRO_H

#include <iostream>
#include <string>

#include "Produto.hpp"

using namespace std;

class Livro : public Produto {
    string _titulo, _autor;
    int _ano;

   public:
    Livro(int id, float valor, string titulo, string autor, int ano);

    void imprimir_info();
};

#endif