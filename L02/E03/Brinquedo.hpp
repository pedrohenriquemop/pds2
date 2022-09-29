#ifndef BRINQUEDO_H
#define BRINQUEDO_H

#include <iostream>
#include <string>

#include "Produto.hpp"

using namespace std;

class Brinquedo : public Produto {
    string _nome;
    int _idade_minima;

   public:
    Brinquedo(int id, float valor, string nome, int idade_minima);

    void imprimir_info();
};

#endif