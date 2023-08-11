#include <string>
#include "Persona.h"

using namespace std;

Persona::Persona() : registro(0) {}

Persona::Persona(string nombre, string apellido, string nac, int registro) : nombre(nombre), apellido(apellido), nac(nac), registro(registro) {}

string Persona::GetNombre() const {
    return nombre;
}

string Persona::GetApellido() const {
    return apellido;
}

string Persona::GetNac() const {
    return nac;
}

int Persona::GetRegistro() const {
    return registro;
}