#include "Brinquedo.hpp"

Brinquedo::Brinquedo(int id, float valor, string nome, int idade_minima) : Produto(id, valor) {
    _nome = nome;
    _idade_minima = idade_minima;
}

void Brinquedo::imprimir_info() {
    cout << getId() << "\tBrinquedo\t" << _nome << '\t' << _idade_minima << " R$ ";
    cout << fixed << setprecision(2);
    cout << getValorUnitario() << endl;
}