#include <list>

#include "Caminhao.hpp"
#include "CaminhaoAutonomo.hpp"
#include "Veiculo.hpp"

using namespace std;

void print_list(list<Veiculo *> l) {
    for (list<Veiculo *>::iterator it = l.begin(); it != l.end(); it++) {
        (*it)->print_info();
    }
}

void rm_id(list<Veiculo *> &l, int id) {
    for (list<Veiculo *>::iterator it = l.begin(); it != l.end(); it++) {
        if ((*it)->get_id() == id) {
            l.erase(it);
            delete (*it);
            return;
        }
    }
}

int main() {
    list<Veiculo *> lista;
    string opcao;

    while (cin >> opcao) {
        if (opcao == "add_c") {
            int vel_max, n_passageiros, carga_max;
            cin >> vel_max >> n_passageiros >> carga_max;
            lista.push_back(new Caminhao(vel_max, n_passageiros, carga_max));
        }
        if (opcao == "add_ca") {
            int vel_max, n_passageiros, carga_max;
            string fabricante;
            cin >> vel_max >> n_passageiros >> carga_max >> fabricante;
            lista.push_back(new CaminhaoAutonomo(vel_max, n_passageiros, carga_max, fabricante));
        }
        if (opcao == "rm") {
            int id;
            cin >> id;
            rm_id(lista, id);
        }
        if (opcao == "print") {
            print_list(lista);
        }
    }

    return 0;
}