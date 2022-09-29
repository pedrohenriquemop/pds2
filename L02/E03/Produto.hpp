#ifndef PRODUTO_H
#define PRODUTO_H

#include <iomanip>
#include <iostream>

using namespace std;

class Produto {
    int _id;
    float _valor_unitario;

   public:
    Produto(int id, float valor_unitario);

    virtual void imprimir_info() = 0;

    int getId();

    float getValorUnitario();
};

#endif