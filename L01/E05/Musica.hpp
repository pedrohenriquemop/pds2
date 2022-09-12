#ifndef MUSICA_H
#define MUSICA_H

#include <iostream>
#include <iomanip>

using namespace std;

struct Musica
{
    int _id;
    string _nome, _artista, _album;
    float _duracao;
    bool _favorita = false;

    Musica(int id, string nome, string artista, string album, float duracao);

    void imprimir_dados();
};

#endif