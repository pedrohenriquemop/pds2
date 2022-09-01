#ifndef ROBO_H
#define ROBO_H

#include "Ponto2D.hpp"
#include <iostream>
#include <limits>

struct Robo{
  int _id;
  bool _com_bola;
  double _energia;
  Ponto2D* _ponto = new Ponto2D();

  Robo(int, Ponto2D, bool);

  void mover(double v, double th, double t);

  double calcular_distancia(Robo* robo);

  Robo* determinar_robo_mais_proximo(Robo** robos, int n);

  void passar_bola(Robo** time, int n);

  void imprimir_status();
};

#endif