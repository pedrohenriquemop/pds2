#include "Catalogo.hpp"

int Catalogo::_id_produto = 1;

void Catalogo::adicionar_produto(string nome, int idade_minima, float valor) {
    _produtos.push_back(new Brinquedo(_id_produto, valor, nome, idade_minima));
    _id_produto++;
}

void Catalogo::adicionar_produto(string titulo, string autor, int ano, float valor) {
    _produtos.push_back(new Livro(_id_produto, valor, titulo, autor, ano));
    _id_produto++;
}

void Catalogo::adicionar_produto(string marca, string modelo, float valor) {
    _produtos.push_back(new Eletronico(_id_produto, valor, marca, modelo));
    _id_produto++;
}

Produto* Catalogo::buscar_produto(int id) {
    for (Produto* produto : _produtos) {
        if (produto->getId() == id) return produto;
    }
    cout << "Produto não encontrado!" << endl;
    return nullptr;
}

void Catalogo::imprimir() {
    for (Produto* produto : _produtos) {
        produto->imprimir_info();
    }
}