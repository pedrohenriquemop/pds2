#ifndef REGISTRO_AVALIACOES_H
#define REGISTRO_AVALIACOES_H

#include <iostream>
#include <map>
#include <string>

#include "Filme.hpp"
#include "Usuario.hpp"

class RegistroAvaliacoes {
    static int static_id_filme;

    map<string, Usuario*, less<string>> _usuarios;
    map<int, Filme*> _filmes;

   public:
    void adicionar_usuario(string login, string nome);

    void adicionar_filme(string nome, string genero, int duracao);

    void adicionar_review(int id_filme, string login_usuario, string comentario, float nota);

    void imprimir_estatisticas_usuarios();

    void imprimir_registro_geral();

    void imprimir_reviews_usuario(string login);
};

#endif