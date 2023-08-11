#include <iostream>
#include <string>
#include "Nodo.h"
#include "Arbol.h"
#include "Persona.h"

using namespace std;

Arbol::Arbol() : raiz(nullptr) {}

void Arbol::Insertar(Persona persona) {
    raiz = InsertarNodo(raiz, persona);
}

Nodo* Arbol::InsertarNodo(Nodo* nodo, Persona persona) {
    // Paso 1: Insertar el nodo como en un árbol de búsqueda binaria
    if (nodo == nullptr) {
        Nodo* nuevoNodo = new Nodo(persona);
        return nuevoNodo;
    }

    if (persona.GetRegistro() < nodo->GetPersona().GetRegistro()) {
        Nodo* nuevoHijoIzquierdo = InsertarNodo(nodo->GetHijoIzquierdo(), persona);
        nodo->SetHijoIzquierdo(nuevoHijoIzquierdo);
        nuevoHijoIzquierdo->SetPadre(nodo); // Establecer el puntero al padre para el nuevo nodo
    }
    else {
        Nodo* nuevoHijoDerecho = InsertarNodo(nodo->GetHijoDerecho(), persona);
        nodo->SetHijoDerecho(nuevoHijoDerecho);
        nuevoHijoDerecho->SetPadre(nodo); // Establecer el puntero al padre para el nuevo nodo
    }

    // Paso 2: Actualizar la altura y factor de equilibrio del nodo actual
    nodo->ActualizarAltura();
    nodo->ActualizarFactorEquilibrio();

    // Paso 3: Realizar rotaciones si es necesario para mantener el equilibrio
    if (nodo->FactorEquilibrio() > 1) {
        if (persona.GetRegistro() < nodo->GetHijoIzquierdo()->GetPersona().GetRegistro()) {
            // Rotación simple a la derecha
            return RotacionDerecha(nodo);
        }
        else {
            // Rotación doble izquierda-derecha
            nodo->SetHijoIzquierdo(RotacionIzquierda(nodo->GetHijoIzquierdo()));
            return RotacionDerecha(nodo);
        }
    }
    else if (nodo->FactorEquilibrio() < -1) {
        if (persona.GetRegistro() > nodo->GetHijoDerecho()->GetPersona().GetRegistro()) {
            // Rotación simple a la izquierda
            return RotacionIzquierda(nodo);
        }
        else {
            // Rotación doble derecha-izquierda
            nodo->SetHijoDerecho(RotacionDerecha(nodo->GetHijoDerecho()));
            return RotacionIzquierda(nodo);
        }
    }

    return nodo;
}

Nodo* Arbol::RotacionDerecha(Nodo* nodo) {
    Nodo* nuevoPadre = nodo->GetHijoIzquierdo();
    nodo->SetHijoIzquierdo(nuevoPadre->GetHijoDerecho());
    nuevoPadre->SetHijoDerecho(nodo);

    // Actualizar punteros al nodo padre
    if (nodo->GetHijoIzquierdo() != nullptr) {
        nodo->GetHijoIzquierdo()->SetPadre(nodo); // Actualizar hijo izquierdo del nodo rotado
    }
    nuevoPadre->SetPadre(nodo->GetPadre()); // Actualizar padre del nodo padre
    nodo->SetPadre(nuevoPadre); // Actualizar padre del nodo rotado

    nodo->ActualizarAltura();
    nuevoPadre->ActualizarAltura();

    return nuevoPadre;
}

Nodo* Arbol::RotacionIzquierda(Nodo* nodo) {
    Nodo* nuevoPadre = nodo->GetHijoDerecho();
    nodo->SetHijoDerecho(nuevoPadre->GetHijoIzquierdo());
    nuevoPadre->SetHijoIzquierdo(nodo);

    // Actualizar punteros al nodo padre
    if (nodo->GetHijoDerecho() != nullptr) {
        nodo->GetHijoDerecho()->SetPadre(nodo); // Actualizar hijo derecho del nodo rotado
    }
    nuevoPadre->SetPadre(nodo->GetPadre()); // Actualizar padre del nodo padre
    nodo->SetPadre(nuevoPadre); // Actualizar padre del nodo rotado

    nodo->ActualizarAltura();
    nuevoPadre->ActualizarAltura();

    return nuevoPadre;
}

void Arbol::MostrarInOrden() const {
    MostrarInOrdenRecursivo(raiz);
}

void Arbol::MostrarInOrdenRecursivo(Nodo* nodo) const {
    if (nodo != nullptr) {
        MostrarInOrdenRecursivo(nodo->GetHijoIzquierdo());
        Persona persona = nodo->GetPersona();
        cout << "Nombre: " << persona.GetNombre() << endl;
        cout << "Apellido: " << persona.GetApellido() << endl;
        cout << "Fecha de nacimiento: " << persona.GetNac() << endl;
        cout << "Registro: " << persona.GetRegistro() << endl;
        cout << endl;
        MostrarInOrdenRecursivo(nodo->GetHijoDerecho());
    }
}

void Arbol::MostrarPreorden() const {
    MostrarPreordenRecursivo(raiz);
}

void Arbol::MostrarPreordenRecursivo(Nodo* nodo) const {
    if (nodo != nullptr) {
        Persona persona = nodo->GetPersona();
        cout << "Nombre: " << persona.GetNombre() << endl;
        cout << "Apellido: " << persona.GetApellido() << endl;
        cout << "Fecha de nacimiento: " << persona.GetNac() << endl;
        cout << "Registro: " << persona.GetRegistro() << endl;
        cout << endl;
        MostrarPreordenRecursivo(nodo->GetHijoIzquierdo());
        MostrarPreordenRecursivo(nodo->GetHijoDerecho());
    }
}

void Arbol::MostrarPostorden() const {
    MostrarPostordenRecursivo(raiz);
}

void Arbol::MostrarPostordenRecursivo(Nodo* nodo) const {
    if (nodo != nullptr) {
        MostrarPostordenRecursivo(nodo->GetHijoIzquierdo());
        MostrarPostordenRecursivo(nodo->GetHijoDerecho());
        Persona persona = nodo->GetPersona();
        cout << "Nombre: " << persona.GetNombre() << endl;
        cout << "Apellido: " << persona.GetApellido() << endl;
        cout << "Fecha de nacimiento: " << persona.GetNac() << endl;
        cout << "Registro: " << persona.GetRegistro() << endl;
        cout << endl;
    }
}

Persona Arbol::BuscarNodo(int registro) const {
    Nodo* nodoEncontrado = BuscarNodoRecursivo(raiz, registro);
    return nodoEncontrado ? nodoEncontrado->GetPersona() : Persona();
}

Nodo* Arbol::BuscarNodoRecursivo(Nodo* nodo, int registro) const {
    if (nodo == nullptr || nodo->GetPersona().GetRegistro() == registro) {
        return nodo;
    }

    if (registro < nodo->GetPersona().GetRegistro()) {
        return BuscarNodoRecursivo(nodo->GetHijoIzquierdo(), registro);
    }
    else {
        return BuscarNodoRecursivo(nodo->GetHijoDerecho(), registro);
    }
}

void Arbol::EliminarNodo(int registro){
    Nodo* nodoEliminar = BuscarNodoRecursivo(raiz, registro);
    if (nodoEliminar->EsHoja()) {
        EliminarNodoHoja(nodoEliminar);
    }
    else if (nodoEliminar->TieneUnHijo()) {
        EliminarNodoConUnHijo(nodoEliminar);
    }
    else{
        EliminarNodoConDosHijos(nodoEliminar);
    }
}

void Arbol::EliminarNodoHoja(Nodo* nodo) {
    if (nodo == raiz) {
        raiz = nullptr;
    }
    else {
        Nodo* padre = nodo->GetPadre();
        if (padre->GetHijoIzquierdo() == nodo) {
            padre->SetHijoIzquierdo(nullptr);
        }
        else {
            padre->SetHijoDerecho(nullptr);
        }

        EquilibrarDespuesEliminacion(padre);
    }

    delete nodo;
}

void Arbol::EliminarNodoConUnHijo(Nodo* nodo) {
    if (nodo->GetHijoIzquierdo() != nullptr) {
        Nodo* Hijo = nodo->GetHijoIzquierdo();
        if (nodo == raiz) {
            Hijo->SetPadre(nullptr);
            raiz = Hijo;
        }
        else {
            Nodo* NuevoPadre = nodo->GetPadre();
            Hijo->SetPadre(NuevoPadre);
            EquilibrarDespuesEliminacion(NuevoPadre);
        }
    } 
    else {
        Nodo* Hijo = nodo->GetHijoDerecho();
        if (nodo == raiz) {
            Hijo->SetPadre(nullptr);
            raiz = Hijo;
        }
        else {
            Nodo* NuevoPadre = nodo->GetPadre();
            Hijo->SetPadre(NuevoPadre);
            EquilibrarDespuesEliminacion(NuevoPadre);
        }
    }
    delete nodo;
}

void Arbol::EliminarNodoConDosHijos(Nodo* nodo) {
    Nodo* nodoSustituto = nodo->GetHijoDerecho();
    while (nodoSustituto->GetHijoIzquierdo() != nullptr) {
        nodoSustituto = nodoSustituto->GetHijoIzquierdo();
    }
    Persona datosSustituto = nodoSustituto->GetPersona();
    EliminarNodo(nodoSustituto->GetPersona().GetRegistro());
    nodo->SetPersona(datosSustituto);
}

void Arbol::EquilibrarDespuesEliminacion(Nodo* nodo) {
    while (nodo) {
        nodo->ActualizarAltura();
        int factorEquilibrio = nodo->FactorEquilibrio();

        if (factorEquilibrio > 1) {
            if (nodo->GetHijoIzquierdo()->FactorEquilibrio() >= 0) {
                RotacionDerecha(nodo);
            }
            else {
                nodo->SetHijoIzquierdo(RotacionIzquierda(nodo->GetHijoIzquierdo()));
                RotacionDerecha(nodo);
            }
        }
        else if (factorEquilibrio < -1) {
            if (nodo->GetHijoDerecho()->FactorEquilibrio() <= 0) {
                RotacionIzquierda(nodo);
            }
            else {
                nodo->SetHijoDerecho(RotacionDerecha(nodo->GetHijoDerecho()));
                RotacionIzquierda(nodo);
            }
        }

        nodo = nodo->GetPadre();
    }
}

int Arbol::ContarNodos() const {
    return ContarNodosRecursivo(raiz);
}

int Arbol::ContarNodosRecursivo(Nodo* nodo) const {
    if (nodo == nullptr) {
        return 0;
    }

    int nodosIzquierda = ContarNodosRecursivo(nodo->GetHijoIzquierdo());
    int nodosDerecha = ContarNodosRecursivo(nodo->GetHijoDerecho());

    return 1 + nodosIzquierda + nodosDerecha;
}

void Arbol::EliminarArbol() {
    EliminarTodasLasHojas(raiz);
    raiz = nullptr;
}

void Arbol::EliminarTodasLasHojas(Nodo* nodo) {
    if (nodo != nullptr) {
        EliminarTodasLasHojas(nodo->GetHijoIzquierdo());
        EliminarTodasLasHojas(nodo->GetHijoDerecho());
        delete nodo;
    }
}

int Arbol::CalcularAltura() const {
    if (raiz == nullptr) {
        return 0; // Árbol vacío, altura 0
    }
    return CalcularAlturaRecursivo(raiz);
}

int Arbol::CalcularAlturaRecursivo(Nodo* nodo) const {
    if (nodo == nullptr) {
        return 0; // Nodo nulo, altura 0
    }

    int alturaIzquierda = CalcularAlturaRecursivo(nodo->GetHijoIzquierdo());
    int alturaDerecha = CalcularAlturaRecursivo(nodo->GetHijoDerecho());

    // La altura del árbol es la altura máxima entre los subárboles izquierdo y derecho, más 1 por el nodo actual
    return max(alturaIzquierda, alturaDerecha) + 1;
}

bool Arbol::EsVacia() const {
    return (raiz == nullptr);
}

Persona Arbol::GetPadre(int registro) const {
    Nodo* nodoEncontrado = BuscarNodoRecursivo(raiz, registro);
    if (nodoEncontrado->GetPadre() == nullptr)
    {
        return Persona();
    }
    return nodoEncontrado ? nodoEncontrado->GetPadre()->GetPersona() : Persona();
}

Persona Arbol::GetHijoDer(int registro) const {
    Nodo* nodoEncontrado = BuscarNodoRecursivo(raiz, registro);
    if (nodoEncontrado->GetHijoDerecho() == nullptr)
    {
        return Persona();
    }
    return nodoEncontrado ? nodoEncontrado->GetHijoDerecho()->GetPersona() : Persona();
}
Persona Arbol::GetHijoIzq(int registro) const {
    Nodo* nodoEncontrado = BuscarNodoRecursivo(raiz, registro);
    if (nodoEncontrado->GetHijoDerecho() == nullptr)
    {
        return Persona();
    }
    return nodoEncontrado ? nodoEncontrado->GetHijoIzquierdo()->GetPersona() : Persona();
}