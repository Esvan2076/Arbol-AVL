#ifndef NODO_H
#define NODO_H

#include "Persona.h"

using namespace std;

class Nodo
{
public:
	Nodo();
	Nodo(Persona p);
	Persona GetPersona() const;
	Nodo* GetHijoIzquierdo() const;
	Nodo* GetHijoDerecho() const;
	Nodo* GetPadre() const;
	int GetAltura() const;
	void SetHijoIzquierdo(Nodo* nodo);
	void SetHijoDerecho(Nodo* nodo);
	void SetPadre(Nodo* nodo);
	int FactorEquilibrio() const;
	void ActualizarFactorEquilibrio();
	void ActualizarAltura();
	bool EsHoja() const;
	bool TieneUnHijo() const;
	bool TieneDosHijos() const;
	void SetPersona(const Persona& persona);
private:
	Persona p;
	Nodo* hijoIzquierdo;
	Nodo* hijoDerecho;
	Nodo* padre;
	int altura;
};

#endif  // NODO_H