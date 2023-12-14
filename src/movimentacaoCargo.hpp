#pragma once
#include "funcionario.hpp"
#include "cargo.hpp"
#include <ctime>
class MovimentacaoCargo{
  Funcionario* funcionario;
  Cargo* cargo;
  time_h dataInicio;
  time_h dataFim;
  int id;
};
