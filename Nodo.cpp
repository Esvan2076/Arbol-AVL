#include <iostream>
#include <string>
#include "Nodo.h"
#include "Persona.h"

using namespace std;

Nodo::Nodo() : p(Persona()), hijoIzquierdo(nullptr), hijoDerecho(nullptr), padre(nullptr), altura(1) {}

Nodo::Nodo(Persona p) : p(p), hijoIzquierdo(nullptr), hijoDerecho(nullptr), padre(nullptr), altura(1) {}

Persona Nodo::GetPersona() const {
    return p;
}

Nodo* Nodo::GetHijoIzquierdo() const {
    return hijoIzquierdo;
}

Nodo* Nodo::GetHijoDerecho() const {
    return hijoDerecho;
}

Nodo* Nodo::GetPadre() const {
    return padre;
}

int Nodo::GetAltura() const {
    return altura;
}

void Nodo::SetHijoIzquierdo(Nodo* nodo) {
    hijoIzquierdo = nodo;
}

void Nodo::SetHijoDerecho(Nodo* nodo) {
    hijoDerecho = nodo;
}

void Nodo::SetPadre(Nodo* nodo) {
    padre = nodo;
}

int Nodo::FactorEquilibrio() const {
    int alturaIzquierdo = (hijoIzquierdo != nullptr) ? hijoIzquierdo->GetAltura() : 0;
    int alturaDerecho = (hijoDerecho != nullptr) ? hijoDerecho->GetAltura() : 0;
    return alturaIzquierdo - alturaDerecho;
}

void Nodo::ActualizarFactorEquilibrio() {
    if (hijoIzquierdo != nullptr)
        hijoIzquierdo->ActualizarAltura();
    if (hijoDerecho != nullptr)
        hijoDerecho->ActualizarAltura();
}

void Nodo::ActualizarAltura() {
    int alturaIzquierdo = (hijoIzquierdo != nullptr) ? hijoIzquierdo->GetAltura() : 0;
    int alturaDerecho = (hijoDerecho != nullptr) ? hijoDerecho->GetAltura() : 0;
    altura = 1 + max(alturaIzquierdo, alturaDerecho);
}

bool Nodo::EsHoja() const {
    return (hijoIzquierdo == nullptr && hijoDerecho == nullptr);
}

bool Nodo::TieneUnHijo() const {
    return ((hijoIzquierdo != nullptr && hijoDerecho == nullptr) || (hijoIzquierdo == nullptr && hijoDerecho != nullptr));
}

bool Nodo::TieneDosHijos() const {
    return (hijoIzquierdo != nullptr && hijoDerecho != nullptr);
}

void Nodo::SetPersona(const Persona& persona) {
    this->p = persona;
}