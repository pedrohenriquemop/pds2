#include "polvo.hpp"

Polvo::Polvo(double qi) : Criatura("Polvo") {
    _qi = qi;
    cout << "Polvo:" << _subtipo << endl;
}

Polvo::~Polvo() {
    cout << "~Polvo:" << _subtipo << endl;
}

double Polvo::get_qi() {
    return _qi;
}

void Polvo::print_info() {
    Criatura::print_info();
    cout << '\t' << "QI: " << _qi << endl;
}

list<unique_ptr<Criatura>> Polvo::acasalar(shared_ptr<Criatura> c) {
    list<unique_ptr<Criatura>> lista;

    if (c->get_subtipo() != "Polvo") return lista;

    double media_qi = (dynamic_pointer_cast<Polvo>(c)->get_qi() + _qi) / 2;
    lista.push_back(
        unique_ptr<Polvo>(new Polvo(media_qi)));

    return lista;
}