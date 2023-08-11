#ifndef ARBOL_H
#define ARBOL_H

#include "Persona.h"
#include "Nodo.h"

using namespace std;

class Arbol
{
public:
	Arbol();
	void Insertar(Persona persona);
	void MostrarInOrden() const;
	void MostrarPreorden() const;
	void MostrarPostorden() const;
	Persona BuscarNodo(int registro) const;
	void EliminarNodo(int registro);
	int ContarNodos() const;
	void EliminarArbol();
	int CalcularAltura() const;
	bool EsVacia() const;
	Persona GetPadre(int registro) const;
	Persona GetHijoIzq(int registro) const;
	Persona GetHijoDer(int registro) const;
private:
	Nodo* raiz;
	Nodo* InsertarNodo(Nodo* nodo, Persona persona);
	Nodo* RotacionDerecha(Nodo* nodo);
	Nodo* RotacionIzquierda(Nodo* nodo);
	void MostrarInOrdenRecursivo(Nodo* nodo) const;
	void MostrarPreordenRecursivo(Nodo* nodo) const;
	void MostrarPostordenRecursivo(Nodo* nodo) const;
	Nodo* BuscarNodoRecursivo(Nodo* nodo, int registro) const;
	void EliminarNodoHoja(Nodo* nodo);
	void EliminarNodoConUnHijo(Nodo* nodo);
	void EliminarNodoConDosHijos(Nodo* nodo);
	void EquilibrarDespuesEliminacion(Nodo* nodo);
	int ContarNodosRecursivo(Nodo* nodo) const;
	void EliminarTodasLasHojas(Nodo* nodo);
	int CalcularAlturaRecursivo(Nodo* nodo) const;
};

#endif  // ARBOL_H