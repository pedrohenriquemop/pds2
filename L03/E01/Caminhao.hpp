#ifndef CAMINHAO_H
#define CAMINHAO_H

#include <iostream>
#include <string>

#include "Veiculo.hpp"

class Caminhao : public Veiculo {
   protected:
    int _carga_max;

   public:
    Caminhao(string subtipo, int vel_max, int n_passageiros, int carga_max);

    Caminhao(int vel_max, int n_passageiros, int carga_max);

    virtual ~Caminhao();

    int estima_preco();

    void print_info();
};

#endif