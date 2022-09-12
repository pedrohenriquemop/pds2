#include <iostream>

#include "Playlist.hpp"
#include "avaliacao_basica_playlist.hpp"

using namespace std;

int main()
{
    char opcao;

    Playlist playlist;
    while (cin >> opcao)
    {
        switch (opcao)
        {
        case 'a':
        {
            string nome, artista, album;
            float duracao;
            cin >> nome >> artista >> album >> duracao;
            playlist.adicionar_musica(nome, artista, album, duracao);
            break;
        }
        case 's':
        {
            string nome, artista;
            cin >> nome >> artista;
            Musica *musica = playlist.buscar_musica(nome, artista);
            if (musica)
                musica->imprimir_dados();
            break;
        }
        case 'r':
        {
            string nome, artista;
            cin >> nome >> artista;
            Musica *musica = playlist.buscar_musica(nome, artista);
            if (musica)
            {
                playlist.remover_musica(musica->_id);
            }
            break;
        }
        case 'f':
        {
            string nome, artista;
            cin >> nome >> artista;
            Musica *musica = playlist.buscar_musica(nome, artista);
            if (musica)
            {
                playlist.favoritar_musica(musica->_id);
            }
            break;
        }
        case 'd':
        {
            string nome, artista;
            cin >> nome >> artista;
            Musica *musica = playlist.buscar_musica(nome, artista);
            if (musica)
            {
                playlist.desfavoritar_musica(musica->_id);
            }
            break;
        }
        case 'p':
        {
            playlist.imprimir();
            break;
        }
        case 'b':
        {
            avaliacao_basica();
            break;
        }
        }
    }
    return 0;
}