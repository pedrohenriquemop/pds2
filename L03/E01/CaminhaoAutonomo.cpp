#include "CaminhaoAutonomo.hpp"

CaminhaoAutonomo::CaminhaoAutonomo(int vel_max, int n_passageiros, int carga_max, string fabricante)
    : Caminhao("CaminhaoAutonomo", vel_max, n_passageiros, carga_max) {
    _fabricante = fabricante;
}

CaminhaoAutonomo::~CaminhaoAutonomo() {
    cout << "Destrutor CaminhaoAutonomo" << endl;
}

int CaminhaoAutonomo::estima_preco() {
    if (_fabricante == "Tesla") return 500000 + 100 * _carga_max + 10 * _vel_max;
    if (_fabricante == "Waymo") return 400000 + 100 * _carga_max + 10 * _vel_max;
    return Caminhao::estima_preco();
}

void CaminhaoAutonomo::print_info() {
    Caminhao::print_info();

    cout << '\t' << "Fabricante: " << _fabricante << endl;
}