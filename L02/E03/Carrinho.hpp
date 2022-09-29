#ifndef CARRINHO_H
#define CARRINHO_H

#include <iomanip>
#include <iostream>
#include <vector>

#include "Pedido.hpp"
#include "Produto.hpp"

using namespace std;

class Carrinho {
    vector<Pedido*> _pedidos;

   public:
    void adicionar_pedido(Produto* produto, int quantidade);

    void imprimir_resumo();
};

#endif