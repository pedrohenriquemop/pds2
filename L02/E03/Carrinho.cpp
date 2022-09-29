#include "Carrinho.hpp"

void Carrinho::adicionar_pedido(Produto* produto, int quantidade) {
    _pedidos.push_back(new Pedido(produto, quantidade));
}

void Carrinho::imprimir_resumo() {
    double total = 0;

    for (Pedido* pedido : _pedidos) {
        pedido->getProduto()->imprimir_info();
        cout << "Qtde: " << pedido->getQuantidade() << " Total produto: R$ ";
        cout << fixed << setprecision(2);
        cout << pedido->get_valor_total() << endl;
        total += pedido->get_valor_total();
    }

    cout << "Total carrinho: R$ ";
    cout << fixed << setprecision(2);
    cout << total << endl;
}