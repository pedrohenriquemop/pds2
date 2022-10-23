#include "Caminhao.hpp"

Caminhao::Caminhao(string subtipo, int vel_max, int n_passageiros, int carga_max)
    : Veiculo(subtipo, vel_max, n_passageiros) {
    _carga_max = carga_max;
}

Caminhao::Caminhao(int vel_max, int n_passageiros, int carga_max)
    : Veiculo("Caminhao", vel_max, n_passageiros) {
    _carga_max = carga_max;
}

Caminhao::~Caminhao() {
    cout << "Destrutor Caminhao" << endl;
}

int Caminhao::estima_preco() {
    return 50000 + 100 * _carga_max + 10 * _vel_max;
}

void Caminhao::print_info() {
    Veiculo::print_info();

    cout << '\t' << "Carga maxima: " << _carga_max << " kg" << endl;
}