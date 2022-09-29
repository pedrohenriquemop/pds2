#ifndef ELETRONICO_H
#define ELETRONICO_H

#include <iostream>
#include <string>

#include "Produto.hpp"

using namespace std;

class Eletronico : public Produto {
    string _marca, _modelo;

   public:
    Eletronico(int id, float valor, string marca, string modelo);

    void imprimir_info();
};

#endif