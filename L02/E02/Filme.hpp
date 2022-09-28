#ifndef FILME_H
#define FILME_H

#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

#include "Review.hpp"

using namespace std;

class Filme {
    int _id, _duracao;
    string _nome, _genero;
    vector<Review *> _reviews;

   public:
    Filme(int id, string nome, string genero, int duracao);

    Review *adicionar_review(string comentario, float nota);

    void imprimir_nota_consolidada();

    string getNome();
};

#endif