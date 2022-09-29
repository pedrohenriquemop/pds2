#include <iostream>

#include "Carrinho.hpp"
#include "Catalogo.hpp"
#include "avaliacao_basica_ecommerce.hpp"

using namespace std;

int main() {
    Catalogo catalogo;
    Carrinho carrinho;

    char opcao;

    while (cin >> opcao) {
        switch (opcao) {
            case 'q': {
                string nome;
                int idade;
                float valor;
                cin >> nome >> idade >> valor;
                catalogo.adicionar_produto(nome, idade, valor);
                break;
            }
            case 'l': {
                string titulo, autor;
                int ano;
                float valor;
                cin >> titulo >> autor >> ano >> valor;
                catalogo.adicionar_produto(titulo, autor, ano, valor);
                break;
            }
            case 'e': {
                string marca, modelo;
                float valor;
                cin >> marca >> modelo >> valor;
                catalogo.adicionar_produto(marca, modelo, valor);
                break;
            }
            case 'c': {
                catalogo.imprimir();
                break;
            }
            case 'p': {
                int id, quantidade;
                cin >> id >> quantidade;
                carrinho.adicionar_pedido(catalogo.buscar_produto(id), quantidade);
                break;
            }
            case 'r': {
                carrinho.imprimir_resumo();
                break;
            }
            case 'b': {
                avaliacao_basica();
                break;
            }
        }
    }

    return 0;
}