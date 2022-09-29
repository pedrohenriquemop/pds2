#include "Pedido.hpp"

Pedido::Pedido(Produto* produto, int quantidade) {
    _produto = produto;
    _quantidade = quantidade;
}

double Pedido::get_valor_total() {
    return (double)(_produto->getValorUnitario() * _quantidade);
}

Produto* Pedido::getProduto() {
    return _produto;
}

int Pedido::getQuantidade() {
    return _quantidade;
}