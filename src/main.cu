
#include "include/Field.hpp"

using Real = float;


int main(int argc, char **argv) {


  std::array<int,3> n = {200,200,200};
  std::array<int,3> n_bd = {20,20,20};

  Field<Real,3> Efield(n,n_bd), Bfield(n,n_bd);



}
