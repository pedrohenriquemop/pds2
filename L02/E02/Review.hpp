#ifndef REVIEW_H
#define REVIEW_H

#include <iostream>
#include <string>

class Filme;

using namespace std;

class Review {
    Filme* _filme;
    string _comentario;
    float _nota;

   public:
    Review(Filme* filme, string comentario, float nota);

    Filme* getFilme();
    string getComentario();
    float getNota();
};

#include "Filme.hpp"

#endif