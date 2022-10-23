#include "Veiculo.hpp"

int Veiculo::_next_id = 1;

Veiculo::Veiculo(string subtipo, int vel_max, int n_passageiros) {
    _id = _next_id;
    _subtipo = subtipo;
    _vel_max = vel_max;
    _n_passageiros = n_passageiros;

    _next_id++;
}

Veiculo::~Veiculo() {
    cout << "Destrutor Veiculo" << endl;
}

int Veiculo::get_id() {
    return _id;
}

void Veiculo::print_info() {
    cout << "Info: Veiculo " << _id << endl;
    cout << "Preco estimado: RS " << this->estima_preco() << ",00" << endl;
    cout << '\t' << "Subtipo: " << _subtipo << endl;
    cout << '\t' << "Velocidade maxima: " << _vel_max << " km/h" << endl;
    cout << '\t' << "Capacidade de passageiros: " << _n_passageiros << endl;
}