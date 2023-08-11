#ifndef PERSONA_H
#define PERSONA_H

using namespace std;

class Persona
{
public:
    Persona();
    Persona(string nombre, string apellido, string nac, int registro);
    string GetNombre() const;
    string GetApellido() const;
    string GetNac() const;
    int GetRegistro() const;
private:
    string nombre;
    string apellido;
    string nac;
    int registro;
};

#endif  // PERSONA_H