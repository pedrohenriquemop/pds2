#include "RegistroAvaliacoes.hpp"

int RegistroAvaliacoes::static_id_filme = 1;

void RegistroAvaliacoes::adicionar_usuario(string login, string nome) {
    _usuarios[login] = new Usuario(login, nome);
}

void RegistroAvaliacoes::adicionar_filme(string nome, string genero, int duracao) {
    _filmes[static_id_filme] = new Filme(static_id_filme, nome, genero, duracao);
    static_id_filme++;
}

void RegistroAvaliacoes::adicionar_review(int id_filme, string login_usuario, string comentario, float nota) {
    Review* review = _filmes[id_filme]->adicionar_review(comentario, nota);
    _usuarios[login_usuario]->associar_review(review);
}

void RegistroAvaliacoes::imprimir_estatisticas_usuarios() {
    for (map<string, Usuario*>::iterator it = _usuarios.begin(); it != _usuarios.end(); it++) {
        it->second->imprimir_info();
    }
}

void RegistroAvaliacoes::imprimir_registro_geral() {
    for (map<int, Filme*>::iterator it = _filmes.begin(); it != _filmes.end(); it++) {
        it->second->imprimir_nota_consolidada();
    }
}

void RegistroAvaliacoes::imprimir_reviews_usuario(string login) {
    _usuarios[login]->imprimir_reviews();
}