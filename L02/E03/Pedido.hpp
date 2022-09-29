#ifndef PEDIDO_H
#define PEDIDO_H

#include <iostream>

#include "Produto.hpp"

using namespace std;

class Pedido {
    Produto* _produto;
    int _quantidade;

   public:
    Pedido(Produto* produto, int quantidade);

    double get_valor_total();

    Produto* getProduto();

    int getQuantidade();
};

#endif