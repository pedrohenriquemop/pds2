#include "Filme.hpp"

Filme::Filme(int id, string nome, string genero, int duracao) {
    _id = id;
    _nome = nome;
    _genero = genero;
    _duracao = duracao;
}

string Filme::getNome() {
    return _nome;
}

Review* Filme::adicionar_review(string comentario, float nota) {
    Review* review = new Review(this, comentario, nota);

    _reviews.push_back(review);

    return review;
}

void Filme::imprimir_nota_consolidada() {
    float total_notas = 0;
    for (Review*& review : _reviews) {
        total_notas += review->getNota();
    }

    float media = 0;

    if (_reviews.size()) media = (total_notas / _reviews.size());

    cout << _nome << '\t' << "Reviews: " << _reviews.size() << '\t' << "Nota media: ";
    cout << fixed << setprecision(1);
    cout << media << endl;
}