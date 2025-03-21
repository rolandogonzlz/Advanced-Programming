/*
 * CS106L Assignment 3: Make a Class
 * Created by Fabio Ibanez with modifications by Jacob Roberts-Baca.
 */
#include <iostream>
#include "class.h"
void sandbox() {
  ClienteGym cliente1("Felix Rolando",25,"mensual");

  std::cout<<"Nombre: "<<cliente1.getNombre()<<std::endl;
  std::cout<<"Edad: "<<cliente1.getEdad()<<std::endl;
  std::cout<<"Membresia: "<<cliente1.getMembresia()<<std::endl;

  cliente1.setNombre("Felix Rolando");
  cliente1.setEdad(25);
  cliente1.setMembresia("anual");

  std::cout << "\nDespues de modificaciones:" << std::endl;
  std::cout << "Nombre: " << cliente1.getNombre() << std::endl;
  std::cout << "Edad: " << cliente1.getEdad() << std::endl;
  std::cout << "Membresia: " << cliente1.getMembresia() << std::endl;

  
}