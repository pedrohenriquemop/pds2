#include "Usuario.hpp"

Usuario::Usuario(string login, string nome) {
    _login = login;
    _nome = nome;
}

void Usuario::associar_review(Review* review) {
    _reviews.push_back(review);
}

void Usuario::imprimir_info() {
    cout << _nome << '\t' << "Reviews: " << _reviews.size() << endl;
}

void Usuario::imprimir_reviews() {
    if (!_reviews.size()) {
        cout << "Usuario " << _nome << " nao possui reviews!";
        return;
    }
    imprimir_info();
    for (Review* review : _reviews) {
        cout << review->getFilme()->getNome() << '\t' << review->getComentario() << '\t' << review->getNota() << endl;
    }
}