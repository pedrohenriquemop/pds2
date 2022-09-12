#ifndef PLAYLIST_H
#define PLAYLIST_H

#include "Musica.hpp"

#include <iostream>
#include <iomanip>
#include <cmath>

struct Node
{
    Node *next = nullptr;
    Node *prev = nullptr;
    Musica *music;
};

struct MusicList
{
    int size = 0;
    Node *first = nullptr;
    Node *last = nullptr;

    void push_music(Musica *music); // adiciona no fim

    void unshift_music(Musica *music); // adiciona no inicio

    void rem_music(Musica *music);

    Musica *find_music(int id);
};

struct Playlist
{
    MusicList _musicList;

    void adicionar_musica(string nome, string artista, string album, float duracao);

    Musica *buscar_musica(string nome, string artista);

    void remover_musica(int id);

    void favoritar_musica(int id);

    void desfavoritar_musica(int id);

    void imprimir();
};

#endif