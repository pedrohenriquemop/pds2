#include "peixe.hpp"

Peixe::Peixe(double peso, char sexo) : Criatura("Peixe") {
    _peso = peso;
    _sexo = sexo;
    cout << "Peixe:" << _subtipo << endl;
}

Peixe::~Peixe() {
    cout << "~Peixe:" << _subtipo << endl;
}

double Peixe::get_peso() {
    return _peso;
}

char Peixe::get_sexo() {
    return _sexo;
}

void Peixe::print_info() {
    Criatura::print_info();
    cout << '\t' << "Peso: " << _peso << " kg" << endl;
    cout << '\t' << "Sexo: " << _sexo << endl;
}

list<unique_ptr<Criatura>> Peixe::acasalar(shared_ptr<Criatura> c) {
    list<unique_ptr<Criatura>> lista;

    if (c->get_subtipo() != "Peixe") return lista;
    if (dynamic_pointer_cast<Peixe>(c)->get_sexo() == _sexo) return lista;

    double media_peso = (dynamic_pointer_cast<Peixe>(c)->get_peso() + _peso) / 2;
    lista.push_back(
        unique_ptr<Peixe>(new Peixe(media_peso, 'F')));
    lista.push_back(
        unique_ptr<Peixe>(new Peixe(media_peso, 'M')));

    return lista;
}