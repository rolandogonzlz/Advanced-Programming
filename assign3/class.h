#ifndef CLIENTE_GYM_H
#define CLIENTE_GYM_H

#include <string>

class ClienteGym {
    private:
        std::string nombre;
        int edad;
        std::string membresia;

        bool validarMembresia(const std::string& tipo);

    public:
        // Constructores
        ClienteGym();
        ClienteGym(const std::string& _nombre, int _edad, const std::string& _membresia);

        // Getters
        std::string getNombre() const;
        int getEdad() const;
        std::string getMembresia() const;

        // Setters
        void setNombre(const std::string& _nombre);
        void setEdad(int _edad);  // Corregido
        void setMembresia(const std::string& _membresia);

        // Metodo para mostrar informacion
        void mostrarInfo() const;  // Agregado
};

#endif // CLIENTE_GYM_H
