#include "Review.hpp"

Review::Review(Filme* filme, string comentario, float nota) {
    _filme = filme;
    _comentario = comentario;
    _nota = nota;
}

Filme* Review::getFilme() {
    return _filme;
}

string Review::getComentario() {
    return _comentario;
}

float Review::getNota() {
    return _nota;
}
