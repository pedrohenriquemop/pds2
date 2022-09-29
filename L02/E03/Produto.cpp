#include "Produto.hpp"

Produto::Produto(int id, float valor_unitario) {
    _id = id;
    _valor_unitario = valor_unitario;
}

float Produto::getValorUnitario() {
    return _valor_unitario;
}

int Produto::getId() {
    return _id;
}