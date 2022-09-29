#include "Eletronico.hpp"

Eletronico::Eletronico(int id, float valor, string marca, string modelo) : Produto(id, valor) {
    _marca = marca;
    _modelo = modelo;
}

void Eletronico::imprimir_info() {
    cout << getId() << "\tEletronico\t" << _marca << '\t' << _modelo << " R$ ";
    cout << fixed << setprecision(2);
    cout << getValorUnitario() << endl;
}