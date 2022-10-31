#include "aquario.hpp"

Aquario::Aquario(const Aquario &orig) {
    for (shared_ptr<Criatura> criatura_orig : orig._criaturas) {
        Criatura *criatura_add;
        if (criatura_orig->get_subtipo() == "Peixe") {
            criatura_add = new Peixe(
                *dynamic_pointer_cast<Peixe>(criatura_orig));
        }
        if (criatura_orig->get_subtipo() == "Polvo") {
            criatura_add = new Polvo(
                *dynamic_pointer_cast<Polvo>(criatura_orig));
        }
        _criaturas.push_back(shared_ptr<Criatura>(criatura_add));
    }
}

void Aquario::add_peixe(double peso, char sexo) {
    shared_ptr<Peixe> peixe(new Peixe(peso, sexo));
    _criaturas.push_back(peixe);
}
void Aquario::add_polvo(double qi) {
    shared_ptr<Polvo> polvo(new Polvo(qi));
    _criaturas.push_back(polvo);
}
void Aquario::acasalamento(int id1, int id2) {
    if (id1 < 0 || id2 < 0 || id1 >= _criaturas.size() || id2 >= _criaturas.size()) return;
    list<unique_ptr<Criatura>> filhotes = _criaturas[id1]->acasalar(_criaturas[id2]);
    for (list<unique_ptr<Criatura>>::iterator it = filhotes.begin(); it != filhotes.end(); ++it) {
        _criaturas.push_back(move(*it));
    }
}

void Aquario::print() {
    cout << "=============" << endl;
    cout << "Aquario Info:" << endl;
    for (shared_ptr<Criatura> criatura : _criaturas) {
        criatura->print_info();
    }
    cout << "=============" << endl;
}