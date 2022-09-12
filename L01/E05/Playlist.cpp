#include "Playlist.hpp"

void MusicList::push_music(Musica *music)
{
    Node *node = new Node;
    node->music = music;
    node->next = nullptr;
    if (first == nullptr)
    {
        first = node;
        last = node;
    }
    else
    {
        node->prev = last;
        last->next = node;
        last = node;
    }
    size++;
}

void MusicList::unshift_music(Musica *music)
{
    Node *node = new Node;
    node->music = music;
    node->prev = nullptr;
    if (first == nullptr)
    {
        first = node;
        last = node;
    }
    else
    {
        node->next = first;
        first->prev = node;
        first = node;
    }
    size++;
}

void MusicList::rem_music(Musica *music)
{
    if (size == 0 || !music)
        return;
    Node *curr = first;
    while (curr != NULL)
    {
        if (curr->music == music)
        {
            if (curr->prev)
            {
                curr->prev->next = curr->next;
            }
            else
            {
                first = curr->next;
            }

            if (curr->next)
            {
                curr->next->prev = curr->prev;
            }
            else
            {
                last = curr->prev;
            }

            size--;
            delete curr;
            return;
        }

        curr = curr->next;
    }
}

Musica *MusicList::find_music(int id)
{
    Node *curr = first;
    while (curr != NULL)
    {
        if (curr->music->_id == id)
        {
            return curr->music;
        }
        curr = curr->next;
    }
    return nullptr;
}

void Playlist::adicionar_musica(string nome, string artista, string album, float duracao)
{
    static int id = 1;
    Musica *musica = new Musica(id, nome, artista, album, duracao);
    _musicList.push_music(musica);
    id++;
}

Musica *Playlist::buscar_musica(string nome, string artista)
{
    Node *curr = _musicList.first;
    while (curr != NULL)
    {
        if (curr->music->_nome == nome && curr->music->_artista == artista)
        {
            return curr->music;
        }
        curr = curr->next;
    }
    return nullptr;
}

void Playlist::remover_musica(int id)
{
    _musicList.rem_music(_musicList.find_music(id));
}

void Playlist::favoritar_musica(int id)
{
    Musica *musica = _musicList.find_music(id);
    if (musica != nullptr && !musica->_favorita)
    {
        musica->_favorita = true;
        _musicList.rem_music(musica);
        _musicList.unshift_music(musica);
    }
}

void Playlist::desfavoritar_musica(int id)
{
    Musica *musica = _musicList.find_music(id);
    if (musica != nullptr && musica->_favorita)
    {
        musica->_favorita = false;
        _musicList.rem_music(musica);
        _musicList.push_music(musica);
    }
}

void Playlist::imprimir()
{
    Node *curr = _musicList.first;
    float ttotal = 0.0;
    while (curr)
    {
        curr->music->imprimir_dados();
        ttotal += curr->music->_duracao;
        curr = curr->next;
    }

    cout << "Tempo total: ";
    int hor = (int)ttotal / 60;
    int min = (int)ttotal % 60;
    cout << setfill('0') << setw(2);
    cout << hor << ":";
    cout << setfill('0') << setw(2);
    cout << min << ":";

    cout.precision(0);

    cout << setfill('0') << setw(2) << fixed;
    cout << ((ttotal - 60 * hor - min) * 60);
    cout << endl;
}