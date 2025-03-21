#include "class.h"
#include <iostream>

// Constructor por defecto
ClienteGym::ClienteGym() : nombre("Desconocido"), edad(0), membresia("ninguna") {}

// Constructor con parametros (corregido)
ClienteGym::ClienteGym(const std::string& _nombre, int _edad, const std::string& _membresia)
    : nombre(_nombre), edad(_edad), membresia(_membresia) {}

// Metodo privado para validar la membresia
bool ClienteGym::validarMembresia(const std::string& tipo) {
    return (tipo == "mensual" || tipo == "anual" || tipo == "semestral");
}

// Getters
std::string ClienteGym::getNombre() const { return nombre; }
int ClienteGym::getEdad() const { return edad; }
std::string ClienteGym::getMembresia() const { return membresia; }

// Setters
void ClienteGym::setNombre(const std::string& _nombre) { nombre = _nombre; }
void ClienteGym::setEdad(int _edad) { edad = _edad; }  // Corregido
void ClienteGym::setMembresia(const std::string& _membresia) {
    if (validarMembresia(_membresia)) {
        membresia = _membresia;
    }
}

// Método para mostrar informacion (declarado en class.h y corregido aqui)
void ClienteGym::mostrarInfo() const {
    std::cout << "Nombre: " << nombre << "\n";
    std::cout << "Edad: " << edad << "\n";
    std::cout << "Membresia: " << membresia << "\n";
}
