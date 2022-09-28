#include <iostream>

#include "RegistroAvaliacoes.hpp"
#include "avaliacao_basica_cinereview.hpp"

using namespace std;

int main() {
    RegistroAvaliacoes registro;

    char opcao;

    while (cin >> opcao) {
        switch (opcao) {
            case 'u': {
                string login, nome;
                cin >> login >> nome;
                registro.adicionar_usuario(login, nome);
                break;
            }
            case 'f': {
                string nome, genero;
                int duracao;
                cin >> nome >> genero >> duracao;
                registro.adicionar_filme(nome, genero, duracao);
                break;
            }
            case 'r': {
                int id;
                string login, comentario;
                float nota;
                cin >> id >> login >> comentario >> nota;
                registro.adicionar_review(id, login, comentario, nota);
                break;
            }
            case 'p': {
                registro.imprimir_registro_geral();
                break;
            }
            case 's': {
                registro.imprimir_estatisticas_usuarios();
                break;
            }
            case 'l': {
                string login;
                cin >> login;
                registro.imprimir_reviews_usuario(login);
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