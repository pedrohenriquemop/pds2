#ifndef VEICULO_H
#define VEICULO_H

#include <iostream>
#include <string>

using namespace std;

class Veiculo {
   private:
    static int _next_id;
    int _id;
    string _subtipo;

   protected:
    int _vel_max, _n_passageiros;

   public:
    Veiculo(string subtipo, int vel_max, int n_passageiros);

    virtual ~Veiculo();

    int get_id();

    virtual int estima_preco() = 0;

    virtual void print_info();
};

#endif