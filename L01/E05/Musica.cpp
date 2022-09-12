#include "Musica.hpp"

Musica::Musica(int id, string nome, string artista, string album, float duracao)
{
    _id = id;
    _nome = nome;
    _artista = artista;
    _album = album;
    _duracao = duracao;
}

void Musica::imprimir_dados()
{
    int min = (int)_duracao;
    cout << _id << '\t' << _album << '\t' << _artista << '\t' << _nome << '\t';
    cout << setfill('0') << setw(2);
    cout << min << ":";
    cout << setfill('0') << setw(2);
    cout << ((_duracao - min) * 60);
    cout << '\t' << _favorita << '\t' << endl;
}