#include "Robo.hpp"

Robo::Robo(int id, Ponto2D ponto, bool com_bola){
  _id = id;
  *_ponto = ponto;
  _com_bola = com_bola;
  _energia = 100;
}

void Robo::mover(double v, double th, double t){
  _ponto->_x += v * t * cos(th);
  _ponto->_y += v * t * sin(th);
  _energia -= v * t;
}

double Robo::calcular_distancia(Robo* robo){
  return _ponto->calcular_distancia(robo->_ponto);
}

Robo* Robo::determinar_robo_mais_proximo(Robo** robos, int n){
  double menor_distancia = std::numeric_limits<double>::max();
  Robo* robo = nullptr;
  for(int i = 0; i < n; i++){
    if(_id != robos[i]->_id && calcular_distancia(robos[i]) < menor_distancia){
      menor_distancia = calcular_distancia(*(robos+i));
      robo = *(robos+i);
    }
  }
  return robo;
}

void Robo::passar_bola(Robo** time, int n){
  if(!_com_bola){
    std::cout << "Estou sem a bola!" << std::endl;
    return;
  }
  Robo* robo = determinar_robo_mais_proximo(time, n);
  if(robo != NULL){
    _com_bola = false;
    robo->_com_bola = true;
  }
}

void Robo::imprimir_status(){
  std::cout << std::fixed;
  std::cout << _id << '\t' << _ponto->_x << '\t' << _ponto->_y << '\t' << _com_bola << '\t' << _energia << std::endl;
}