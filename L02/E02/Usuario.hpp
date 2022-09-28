#ifndef USUARIO_H
#define USUARIO_H

#include <iostream>
#include <string>
#include <vector>

#include "Review.hpp"

using namespace std;

class Usuario {
    string _login, _nome;
    vector<Review *> _reviews;

   public:
    Usuario(string login, string nome);

    void associar_review(Review *review);

    void imprimir_info();

    void imprimir_reviews();
};

#endif