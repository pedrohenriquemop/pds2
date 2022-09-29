#include "Livro.hpp"

Livro::Livro(int id, float valor, string titulo, string autor, int ano) : Produto(id, valor) {
    _titulo = titulo;
    _autor = autor;
    _ano = ano;
}

void Livro::imprimir_info() {
    cout << getId() << "\tLivro\t" << _titulo << '\t' << _autor << '\t' << _ano << " R$ ";
    cout << fixed << setprecision(2);
    cout << getValorUnitario() << endl;
}