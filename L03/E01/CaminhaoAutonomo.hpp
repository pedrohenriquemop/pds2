#ifndef CAMINHAO_AUTONOMO_H
#define CAMINHAO_AUTONOMO_H

#include <iostream>
#include <string>

#include "Caminhao.hpp"

class CaminhaoAutonomo : public Caminhao {
   protected:
    string _fabricante;

   public:
    CaminhaoAutonomo(int vel_max, int n_passageiros, int carga_max, string fabricante);

    virtual ~CaminhaoAutonomo();

    int estima_preco();

    void print_info();
};

#endif